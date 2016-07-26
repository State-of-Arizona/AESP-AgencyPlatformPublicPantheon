<?php
/** 
* @file
* The scs_payment.classes.inc provide a payment method which admin could use for credit card payment.
* 
*/
  
  
/*
 * Payment Menthod Controller for the SCS payment gateway
 *
 */
class PaymentMethodSCSController extends PaymentMethodController {

  public $controller_data_defaults = array(
    'name' => '',
    'number' => '',
    'gao_batch_agency' => '',
    'gao_doc_no_agency' => '',
    //'gao_agency' => '',
    'service' => '',
    'server' => '',
    'debug' => FALSE,
  );

  public $payment_method_configuration_form_elements_callback = 'scs_payment_payment_method_configuration_form_elements';  
  public $payment_configuration_form_elements_callback = 'scs_payment_payment_configuration_form_elements';
  
  // Setup private variables for our paths
  private $post_url;
  private $checkout_url;

  function __construct() {
    $this->title = t('SCS Payment');
    $this->description = t('Send user to the SCS payment system.');
  }  

  /*
   * Execute the request from the payment submission
   */
  function execute(Payment $payment) { 
    // Setup our server and paths
    $server = $this->getServer($payment->method->controller_data['server']);
    $this->post_url = $server . '/chargePayment.serv';
    $this->checkout_url = $server . '/checkout/paymentInformation.seam'; 
    // Process our payment request
    $this->request($payment);
  }



  /*
   * Process the payment request with curl.
   */
  function request(Payment $payment) {  
    module_load_include('inc', 'webform', 'includes/webform.submissions');
    //get the product codes and then add it to the payment object 
    $submission = webform_get_submission($payment->context_data['nid'], $payment->context_data['sid']);
    $node = node_load($payment->context_data['nid']); 
    $product_code_value = '';
    
    foreach ($node->webform['cids'] as $key => $component) {
      if ($key == 'product_code') {
        $product_code_cid = $node->webform['cids'][$key];   
        $product_code_value = $submission->data[$product_code_cid]['0'];
        if (!empty($product_code_value)) {
          $info = array_pad(explode("_", $product_code_value), 5, '');
          list($product_code, $function, $product_revenue, $product_accounting_template, $product_department_revenue_source) = $info;
          $payment->product_code = $product_code; 
          $payment->function = $function;
          $payment->revenue_source = $product_revenue; 
          $payment->product_accounting_template = $product_accounting_template;
          $payment->product_department_revenue_source = $product_department_revenue_source;
        }
      }
    } 
        
    if (!isset($payment->product_code) || !isset($payment->function) || !isset($payment->revenue_source)) {
      drupal_set_message(t('Please provide Product Code, Function, and Revenue Source for the product.'), 'error');
      return;
    }
    
    $options = array(
      'headers' => array('Content-Type' => 'text/xml'),
      'method' => 'POST',
      'data' => $this->generate_xml($payment)
      //'data' => $this->xmlTest()
    ); 
    
    //do the debug log for the XML
    if ($payment->method->controller_data['debug'] == 1) {
      $message = $options['data'];
      watchdog('SCS Payment XML', $message, $variables = array(), $severity = WATCHDOG_NOTICE, $link = NULL);
      watchdog('SCS Payment Post URL', $this->post_url, $variables = array(), $severity = WATCHDOG_NOTICE, $link = NULL);
    }
    
    $output = drupal_http_request($this->post_url, $options);
    if (isset($output->status_message) && $output->status_message != 'OK' && $output->code != 200) { 
      //do the debug log for the XML
      if ($payment->method->controller_data['debug'] == 1) {
        $message = 'Post XML server error: ' . $output->status_message . ' and status code ' . $output->code;
        watchdog('SCS Payment Post XML Respond', $message, $variables = array(), $severity = WATCHDOG_NOTICE, $link = NULL);
      } 
    }
    // Lets parse our output and fetch our URL.
    $checkout_url = '';
    if (isset($output->data)) {
      $checkout_url = drupal_parse_url(ltrim($output->data, 'url='));
    }
    
    $message = '';
    if (isset ($checkout_url['query']['error'])) {
      switch ($checkout_url['query']['error']) { 
        case 1:
          $message = 'The request xml document was invalid. (illformed)';
          watchdog('SCS_Payment', $message, $variables = array(), $severity = WATCHDOG_NOTICE, $link = NULL);
        break;
        case 2:
          $message = 'The transaction data was invalid. This error will occur when required AFIS data is missing.';
          watchdog('SCS_Payment', $message, $variables = array(), $severity = WATCHDOG_NOTICE, $link = NULL); 
          break;
        case 3:
          $message = 'Internal server error which would prevent a transaction from processing.';
          watchdog('SCS_Payment', $message, $variables = array(), $severity = WATCHDOG_NOTICE, $link = NULL); 
          break;
        default:
          drupal_goto($checkout_url['path'], array('query' => $checkout_url['query']));
          break;
      } 
    }
  }
  

  /*
   * Takes a payment object from the payment module and builds the necessary
   * request for the SCS payment gateway.
   */
  function generate_xml(Payment $payment) {
    global $base_url, $base_path;
    // Define our default schema for our XML
    $schema = array(
      'xmlns:GAOPaymentTransaction' => 'http://payment.az.gov',
      'xmlns:xsi' => 'http://www.w3.org/2001/XMLSchema-instance',
      'xsi:schemaLocation' => 'http://payment.az.gov GAOPaymentTransaction.xsd',
    );
    
    //use this order_number for return after payment paid with credit card 
    $order_number = $payment->pid; 

    // Create our XML string
    $xml = new SCSPaymentXML();
    // Open our Transaction
    $xml->push('GAOPaymentTransaction:transaction', $schema);

    // Get our Merchant information
    $xml->element('merchantName', $payment->method->controller_data['name']);
    $xml->element('merchantNumber', $payment->method->controller_data['number']);
    $xml->element('service', $payment->method->controller_data['service']); 
    $xml->element('orderNumber', $order_number);
    $xml->element('gaoBatchAgency', $payment->method->controller_data['gao_batch_agency']);
    $xml->element('gaoDocNoAgency', $payment->method->controller_data['gao_doc_no_agency']);
    //This might not be accurante, because the system autotmatically get quantity * amount
    //and use it for total and this "totalAmount" value got disregard
    $xml->element('totalAmount', ($payment->totalAmount(TRUE))*100);
        
    // Include Test element in if the server is sandbox or Test Server. 1 => $this::URL_CHECKOUT_SANDBOX,
    if ($payment->method->controller_data['server'] == 1) {
      $xml->element('test', 'test');
    }

    // return URL stuff based on drupal functions 
    $link = $base_url . $base_path . 'scs_payment/return'; 
    $xml->element('returnURL', $link);
 
    // This would be the Payment Description. other other one is the lineitem description would be 
    // use for each product.
    $xml->element('summaryDescription', $payment->description); 
    $xml->push('lineItemList'); 
    // Start Foreach 
    foreach ($payment->line_items as $product) {
      $xml->push('lineItem');
      if ($product->amount_source == 'fixed') {
        $xml->element('gaoProductCode', $product->product_code_id);
        $xml->element('function', $product->product_function);
        $xml->element('revenueSource', $product->product_revenue_source);
        $xml->element('AccountingTemplate', (isset($product->product_accounting_template) ? $product->product_accounting_template : ''));
        $xml->element('departmentRevenueSource', (isset($product->product_department_revenue_source) ? $product->product_department_revenue_source : ''));
      } else {
        $xml->element('gaoProductCode', $payment->product_code);
        $xml->element('function', $payment->function);
        $xml->element('revenueSource', $payment->revenue_source);
        $xml->element('AccountingTemplate', $payment->product_accounting_template);
        $xml->element('departmentRevenueSource', $payment->product_department_revenue_source);
      }
      $xml->element('gaoAgency', $payment->method->controller_data['gao_doc_no_agency']);
      $xml->element('gaoDescription', htmlentities($product->description));  
      $xml->element('amount', ($product->amount)*100);
      $xml->element('quantity', $product->quantity);
      $xml->pop();  
    }
    // End Foreach
    $xml->pop();

    // Close Transaction
    $xml->pop();

    return $xml->getXML();
  }

  /*
   * Return our server url
   */
  function getServer($server) {
    //  OLD url
    //  const URL_CHECKOUT_PRODUCTION = 'https://az.gov/app/pmtpages';
    //  const URL_CHECKOUT_SANDBOX = 'https://prodtest.az.gov/app/pmtpages';
    //  Get the set url and append "/app/pmtpages" to it to make it match with the old url pattern.
    $servers = array(
      0 => variable_get('scs_prod_url', 'https://ptl.az.gov') . '/app/pmtpages',
      1 => variable_get('scs_test_url', 'https://az.stagingaz.gov') . '/app/pmtpages',
    );
    
    if (isset($servers[$server])) {
      return $servers[$server];
    }
    // Default to sandbox mode if no selection
    return $servers[1];
  }


  function xmlTest() {
    return '<?xml version="1.0" encoding="UTF-8"?>
      <GAOPaymentTransaction:transaction xmlns:GAOPaymentTransaction="http://payment.az.gov" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="http://payment.az.gov GAOPaymentTransaction.xsd ">
      <merchantName>LDA-LAND DEPARTMENT-PERMIT</merchantName>
      <merchantNumber>LDA_TEST</merchantNumber>
      <service>LDA_TEST</service>
      <orderNumber>192</orderNumber>
      <gaoBatchAgency>LDA</gaoBatchAgency>
      <gaoDocNoAgency>LDA</gaoDocNoAgency>
      <totalAmount>1500</totalAmount>
      <returnURL>http://dev-az-scs.pantheon.io/scs_payment/return</returnURL>
      <summaryDescription>Default Payment</summaryDescription>
      <test>test</test>
      <lineItemList>
      <lineItem>
      <gaoProductCode>LDRECIND</gaoProductCode>
      <gaoAgency>LDA</gaoAgency>
      <function>37321</function>
      <revenueSource>4699</revenueSource>
      <Department RevenueSource></Department RevenueSource> 
      <AccountingTemplate></AccountingTemplate> 
      <gaoDescription>Testing Payment for SCS</gaoDescription>
      <amount>1500</amount>
      <quantity>1</quantity>
      </lineItem>
      </lineItemList>
      </GAOPaymentTransaction:transaction>';

    return '<?xml version="1.0" encoding="UTF-8"?><GAOPaymentTransaction:transaction xmlns:GAOPaymentTransaction="http://payment.az.gov" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="http://payment.az.gov GAOPaymentTransaction.xsd"><merchantName>Arizona Test Merchant</merchantName><merchantNumber>ADOA_TEST</merchantNumber><service>ADOA_TEST_LICENSING</service><orderNumber>1001</orderNumber><gaoBatchAgency>TST</gaoBatchAgency><gaoDocNoAgency>TST</gaoDocNoAgency><totalAmount>5000</totalAmount><returnURL>https://prodtest.az.gov/app/pmtpages/testGovReceive.serv</returnURL><summaryDescription>This is a test transaction. License #AZ123456</summaryDescription><test>test</test><lineItemList><lineItem><gaoProductCode>PM000091</gaoProductCode><gaoAgency>TST</gaoAgency><gaoIndex>13100</gaoIndex><gaoCompObject>4312</gaoCompObject><gaoAgencyObject>9999</gaoAgencyObject><gaoMultipurposeCode></gaoMultipurposeCode><gaoDescription>SR App - Test</gaoDescription><amount>5000</amount><quantity>1</quantity></lineItem></lineItemList></GAOPaymentTransaction:transaction>';
  }
}

