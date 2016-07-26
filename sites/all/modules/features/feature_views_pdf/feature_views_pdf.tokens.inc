<?php
/**
 * @file
 * Code for the Feature Views PDF, token file.
 */
  
  
/**
 * Implements hook_token_info().
 */
function feature_views_pdf_token_info() {
// you will find this in the node section in path auto replacement pattrens
// then you could use [node:relatedtype]/[node:title] as a url pattern
  //this one use on the confirmation page
  $info['tokens']['submission']['confirmation_pdf'] = array(
    'name' => t('URL for PDF file'),
    'description' => t('Download PDF file base on SID'), 
  );
  //this one use on the email out as attachment
  $info['tokens']['payment']['confirmation_pdf_uri'] = array(
    'name' => t('URI for PDF file'),
    'description' => t('Download PDF file base on SID'), 
  );
  $info['tokens']['payment']['submitted_user_email'] = array(
    'name' => t('Payment Submitted User Email'),
    'description' => t('Payment Submitted User Email'), 
  );
	$info['tokens']['submission']['scs_authorization_code'] = array(
    'name' => t('SCS authorization code'),
    'description' => t('SCS authorization code'), 
  );
  return $info;
}
 
 
/**
 * Implements hook_tokens().
 */
 
function feature_views_pdf_tokens($type, $tokens, array $data = array(), array $options = array()) {
        
  $replacements = array();
  $sanitize = !empty($options['sanitize']); 
  
  //Get this url for the confirmation page
  if ($type == 'submission' && !empty($data['webform-submission'])) { 
    foreach ($tokens as $name => $original) {
      switch ($name) { 
        case 'confirmation_pdf':  
          $toreplace = feature_views_pdf_set_mytoken($name, $data);
          $replacements[$original] = $toreplace; 
        break;  
        case 'scs_authorization_code':  
          $toreplace = feature_views_pdf_set_mytoken($name, $data);
          $replacements[$original] = $toreplace; 
        break; 
      }
    }
  }
  
  //get this uri for the attachement email in Rule
  //Need a token for payer email
  if ($type == 'payment' && !empty($data['payment'])) { 
    foreach ($tokens as $name => $original) {
      switch ($name) {  
        case 'confirmation_pdf_uri': 
          $toreplace = feature_views_pdf_set_mytoken($name, $data);  
          $replacements[$original] = $toreplace;  
        break;
        //use the payment object that contain sid and nid. load nid to get the node component, then map it to the submission to get the email value.
        case 'submitted_user_email': 
          $toreplace = get_submission_user_email($data['payment']->context_data['nid'], $data['payment']->context_data['sid']);  
          $replacements[$original] = $toreplace;  
        break;
      }
    }
  }
  
  
  return $replacements;
}

/**
 * Get user email base on webform component
 * @param type $name
 * @param type $data
 * @return type
 */
function get_submission_user_email($nid, $sid) {
  $submission = webform_get_submission($nid, $sid);
  $node = node_load($nid);
  $email = ''; 
  $email_component = '';
  //Need to get email field set by the form config
  //webform_email_component
  $query = db_select('webform_auto_renew_email', 'w'); 
  $query->condition('w.nid', $nid, '='); 
  $query->fields('w', array('webform_email_component')); 
  $result = $query->execute()->fetchObject(); 
  //If the view name had been changed after the form config. then we need to check 
  if (isset($result->webform_email_component) && $result->webform_email_component != '') {
    $email_component = $result->webform_email_component; 
    return $submission->data[$email_component]['0'];
  } 
  else {
    foreach ($node->webform['components'] as $key => $component) {
      if ($component['type'] == 'email') {
        $email = $submission->data[$key]; 
        return $email['0'];
      }
    }
  }
}
 
// however we will need to call this function from our code or see above
function feature_views_pdf_set_mytoken($name, $data) { 
  switch ($name) {
    case 'confirmation_pdf':
      //return the urL
      $pid = get_pid_by_sid($data['webform-submission']->nid, $data['webform-submission']->sid);
      return file_create_url(prepare_to_generate_pdf($data['webform-submission']->nid, $data['webform-submission']->sid, $pid)); 
    break;
    case 'scs_authorization_code':
      //return the authorization code
      $pid = get_pid_by_sid($data['webform-submission']->nid, $data['webform-submission']->sid);
      return get_authorization_code_by_nid_and_sid($data['webform-submission']->nid, $data['webform-submission']->sid, $pid); 
    break;
    case 'confirmation_pdf_uri':     
      //return the uri   
      return prepare_to_generate_pdf($data['payment']->context_data['nid'], $data['payment']->context_data['sid'], $data['payment']->pid); 
    break;
  }
}

function get_authorization_code_by_nid_and_sid($nid, $sid, $pid) {
  $payment = entity_load_single('payment', $pid);
  $submission = webform_get_submission($nid, $sid);
  $node = node_load($nid);
  //need to insert/update the $authorizationCode into the "scs_authorization_code". 
  $cid = '';
  
  //it should work
  foreach ($node->webform['components'] as $key => $component) {
    //This one "scs_authorization_code" is custom, so make sure to have it available
    if ($component['form_key'] == 'scs_authorization_code') {
      $cid = $component['cid']; 
      //finish webform submission
      if ((payment_status_is_or_has_ancestor($payment->getStatus()->status, PAYMENT_STATUS_SUCCESS)) || 
        ($payment->method->controller->name == 'PaymentMethodSCSController')) {
        if (!empty($submission->data[$cid][0])) {
        	return 'Authorization #'. $submission->data[$cid][0];
				}
      } 
    }
  }
}
/**
 * 
 * @param type $nid
 * @param type $sid
 * @return type string
 */
function prepare_to_generate_pdf($nid, $sid, $pid) { 
  //use this hook for the pdf  
  //check to see if the webform do need to generate PDF or not
  $query = db_select('webform_extra_pdf_config', 'w'); 
  $query->condition('w.nid', $nid, '='); 
  $query->fields('w', array('generate_pdf', 'pdf_view_name')); ; 
  $result = $query->execute()->fetchObject();
  
  if (isset($result->generate_pdf) && $result->generate_pdf == '1') { 
    //Only Generate the PDF If Payment is Success.   
    //get payment  
    if ($pid != '') {
      $payment = entity_load_single('payment', $pid);  
      //This one is for SCS API, only generate the pdf file if the status is success. or cash 
      if ((payment_status_is_or_has_ancestor($payment->getStatus()->status, PAYMENT_STATUS_SUCCESS)) || 
        ($payment->method->controller->name == 'PaymentMethodCashController')) {
        $url = generate_pdf($result->pdf_view_name, $sid);  
        return $url->uri;
      } 
    }
  }
}


