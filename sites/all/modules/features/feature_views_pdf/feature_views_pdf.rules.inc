<?php

/**
 * @file
 * Rules integration.
 */
    
function feature_views_pdf_rules_event_info(){
  return array(
    'payment_pre_finish' => array(
      'label' => t('Generate Permit PDF File After Payment Completed'),
      'group' => t('Payment'),
      'variables' => array(
      'payment' => array(
        'type' => 'payment',
        'label' => t('Payment'),
        ),
      ),
      'access callback' => TRUE,
    ),
  );
}
/**
 * implementation of hook_rules_condition_info()
 */
function feature_views_pdf_rules_condition_info() {
  $conditions = array(); 
  $conditions['feature_views_pdf_by_pid'] = array(
    'label' => t('Generate Permit PDF base on PID With completed payment'),
    'group' => t('Payment'), 
    'parameter' => array( 
      'base_table' => array(
        'type' => 'text',
        'label' => t('The [payment:pid] is required for this condition'),
        'restriction' => 'input',
      ),
    ),
  ); 
  $conditions['feature_views_check_nid'] = array(
    'label' => t('Compare Payment Webform NID'), 
    'arguments' => array( 
        'pid' => array(
          'type' => 'text',
          'label' => t('The [payment:pid] is required for this condition.'),
          'restriction' => 'input',
          'group' => t('Payment'),   
        ), 
        'nid' => array('type' => 'text', 'label' => t('The Webform NID')),
      ),
    'module' => 'feature_views_pdf',
  ); 

  return $conditions;
}
 
/**
 * 
 */
function feature_views_check_nid($pid, $nid) {
  $payment = entity_load_single('payment', $pid);
  if(isset($payment->context_data['nid'])) {
    $payment_nid = $payment->context_data['nid'];  
    if($payment_nid == $nid) { 
      return TRUE;
    } else { 
      return FALSE;
    } 
  }
}
/**
 * Check to see if the submission need to generate the PDF or not.
 * @param type $pid
 * @return boolean
 */
function feature_views_pdf_by_pid($pid) {
  $payment = entity_load_single('payment', $pid);
  $nid = $payment->context_data['nid'];
  $uri = '';
  $uri = prepare_to_generate_pdf($nid, $pid);
  watchdog('custom rule', 'call from custom rule');
  if(empty($uri)) {
    return false;
  } else {
    return true; 
  }
} 