<?php
/** 
* @file
* The file provide a custom rule event.
* 
*/
  
/**
 * Implementation of hook_rules_event_info()
 */
function webform_config_helper_rules_event_info() {
  return array(
    'renewal_reminder_event' => array(
      'label' => t('AZ Permit Renewal event'),
      'module' => 'webform_config_helper',
      'group' => 'AZ Land' ,
      'variables' => array(
        'current_user' => array('type' => 'user', 'label' => t('The current logged in user.')),
        'submitter_email' => array('type' => 'text', 'label' => t('Permit Submitter Email')),
        'permit_expired_date' => array('type' => 'text', 'label' => t('Permit Expired Date')),
      ),
    ),
  );
}