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
  variable_set('sendgrid_marketing_key', encrypt($form_state['values']['sendgrid_marketing_key']));
  drupal_set_message('Your API key has been saved and encrypted.');
}
