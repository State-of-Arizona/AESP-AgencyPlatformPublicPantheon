<?php
/** 
* @file
* The scs_payment.tokens.inc provide a set of tokens to be use for credit card payment.
* 
*/
  
  
/**
 * Implements hook_token_info().
 */
function scs_payment_token_info() {
// you will find this in the node section in path auto replacement pattrens
// then you could use [node:relatedtype]/[node:title] as a url pattern
  $info['tokens']['submission']['pid'] = array(
    'name' => t('SCS PID'),
    'description' => t('This is the pid for the payment'), // this is so you see it in the big list
  );

  $info['tokens']['submission']['total_amount'] = array(
    'name' => t('Total Payment'),
    'description' => t('This is the total for the payment'), 
  );
  $info['tokens']['submission']['description'] = array(
    'name' => t('Payment Description'),
    'description' => t('This is the description of the payment'), 
  );
  $info['tokens']['submission']['tax_rate'] = array(
    'name' => t('Payment Tax Rate'),
    'description' => t('This is the tax rate of the payment'), 
  );
  $info['tokens']['submission']['quantity'] = array(
    'name' => t('Quantity Purchased'),
    'description' => t('This is the quantity purchased'), 
  );
  return $info;
}
 
 
/**
 * Implements hook_tokens().
 */
 
function scs_payment_tokens($type, $tokens, array $data = array(), array $options = array()) { 
  $replacements = array();
  $sanitize = !empty($options['sanitize']); 
  
  if ($type == 'submission' && !empty($data['webform-submission'])) {
    $node = $data['webform-submission']; 
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'pid':
        $toreplace = scs_payment_set_mytoken($name, $data);
        $replacements[$original] = $toreplace;
        break; 
        case 'total_amount':
        $toreplace = scs_payment_set_mytoken($name, $data);
        $replacements[$original] = $toreplace;
        break;
        case 'description':
        $toreplace = scs_payment_set_mytoken($name, $data);
        $replacements[$original] = $toreplace;
        break;
        case 'tax_rate':
        $tax_rate_before_percentage = scs_payment_set_mytoken($name, $data);
        $toreplace = $tax_rate_before_percentage * 100 . '%';
        $replacements[$original] = $toreplace;
        break;
        case 'quantity':
        $toreplace = scs_payment_set_mytoken($name, $data);
        $replacements[$original] = $toreplace;
        break;
      }
    }
  }
  return $replacements;
}
 
// however we will need to call this function from our code or see above
function scs_payment_set_mytoken($name, $data) {
  //Todo For Loop to check 
  switch ($name) {
    case 'pid':
      return $data['node']->webform['components'][1]['pid'];
      break; 
    case 'total_amount':
      return $data['node']->webform['components'][1]['extra']['line_items'][0]->amount;
      break;
    case 'description':
      return $data['node']->webform['components'][1]['extra']['line_items'][0]->description;
      break;
    case 'tax_rate':
      return $data['node']->webform['components'][1]['extra']['line_items'][0]->tax_rate;
      break;
    case 'quantity':
      return $data['node']->webform['components'][1]['extra']['line_items'][0]->quantity;
      break;
  }
}




