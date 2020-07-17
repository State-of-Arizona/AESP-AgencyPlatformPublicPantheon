<?php

/**
 * @file
 * Sendgrid marketing admin configuration.
 */

/**
 * @return Settings form.
 *   Form for setting Sendgrid API key.
 */
function sendgrid_marketing_settings_form($form, &$form_state) {
  $form = array();
  $default = '';
  if (variable_get('sendgrid_marketing_key')) {
      $default = 'Encrypted';
  }

  $form['sendgrid_marketing_key'] = array(
      '#type' => 'textfield',
      '#title' => t('Sendgrid API Key'),
      '#maxlength' => 256,
      '#description' => t('Your Sendgrid account key.'),
      '#required' => FALSE,
      '#default_value' => $default,
  );
  $form['sendgrid_marketing_new_api'] = array(
    '#type' => 'checkbox',
    '#title' => t('New Marketing Campaigns API'),
    '#maxlength' => 256,
    '#description' => t('Check to enable the new marketing campaigns API.  Otherwise, the legacy API will be used.'),
    '#required' => FALSE,
    '#default_value' => variable_get('sendgrid_marketing_new_api', FALSE),
  );
  $form['submit_button'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Submit handler for settings form. Encrypts api key.
 *
 */
function sendgrid_marketing_settings_form_submit($form, $form_state) {
  if($form_state['values']['sendgrid_marketing_key'] != 'Encrypted'){
    variable_set('sendgrid_marketing_key', encrypt($form_state['values']['sendgrid_marketing_key']));
    drupal_set_message('Your API key has been saved and encrypted.');

  }

  variable_set('sendgrid_marketing_new_api', $form_state['values']['sendgrid_marketing_new_api']);
}
