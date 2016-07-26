<?php

namespace Drupal\wps_test_method;

use \Drupal\payment_forms\FormInterface;

class DummyForm implements FormInterface {
  public function getForm(array &$element, array &$form_state, \Payment $payment) {
    $method = $payment->method;
    $settings['wps_test_method'][$method->pmid] = true;
    drupal_add_js($settings, 'setting');
    drupal_add_js(
      drupal_get_path('module', 'wps_test_method') . '/wps_test_method.js',
      'file'
    );

    $element['js_succeed'] = array(
      '#type' => 'checkbox',
      '#title' => 'JS validation success.',
      '#description' => 'If this is checked a succeeding JS validation will be simulated.',
      '#default_value' => TRUE,
    );
    $element['js_timeout'] = array(
      '#type' => 'select',
      '#title' => 'Client-side validation timeout.',
      '#description' => 'Timeout before the actual form-submit may happen.',
      '#options' => array(0 => 'Zero', 1 => '1 second', 5 => '5 seconds', 30 => '30 seconds', 120 => '2 minutes'),
    );

    $options = array();
    foreach (payment_statuses_info() as $info) {
      $options[$info->status] = $info->title;
    }
    $element['status'] = array(
      '#type' => 'select',
      '#title' => 'Target status',
      '#description' => 'The payment processing will finish with this status.',
      '#options' => $options,
    );

    $element['validate_timeout'] = array(
      '#type' => 'select',
      '#title' => 'Server-side validation timeout.',
      '#description' => 'Timeout before redirecting to another URL.',
      '#options' => array(0 => 'Zero', 1 => '1 second', 5 => '5 seconds', 30 => '30 seconds', 120 => '2 minutes'),
    );

    $element['redirect'] = array(
      '#type' => 'checkbox',
      '#title' => 'Redirect',
      '#description' => 'Simulate a payment method that needs to redirect the user to an external page.',
    );
  }

  public function validateForm(array &$element, array &$form_state, \Payment $payment) {
    $values =& $form_state['values'];
    foreach ($element['#parents'] as $key) {
      $values =& $values[$key];
    }
    $payment->context_data['method_data'] = $values;
    $payment->form_state = &$form_state;
  }
}
