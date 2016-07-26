<?php
/**
 * @file
 * Payment Menthod Controller for the SCS payment gateway
 *
 */
class PaymentMethodCashController extends PaymentMethodController {
        
  public $controller_data_defaults = array( 
    'debug' => FALSE, 
  );

  public $payment_method_configuration_form_elements_callback = 'cash_payment_payment_method_configuration_form_elements';
  public $payment_configuration_form_elements_callback = 'cash_payment_payment_configuration_form_elements';

  function __construct() {
    $this->title = t('Cash Payment');
    $this->description = t('Take Cash or Check payment system.');
  }   
  
  /**
   * Implements PaymentMethodController::execute().
   */
  function execute(Payment $payment) { 
    $payment->setStatus(new PaymentStatusItem('payment_status_success')); 
    $payment->finish();
  }

  /**
   * {@inheritdoc}
   */
  public function validate(Payment $payment, PaymentMethod $payment_method, $strict) {
    // This payment method controller does not have a minimum amount, so when
    // the parent throws such an exception, catch it and do nothing.
    try {
      parent::validate($payment, $payment_method, $strict);
    }
    catch (PaymentValidationAmountBelowMinimumException $e) {
    }
  }
         
}

