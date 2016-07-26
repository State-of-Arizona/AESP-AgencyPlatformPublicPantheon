<?php
/**
 * @file
 */

/**
 * Implements _webform_defaults_[component]().
 */
function _webform_defaults_paymethod_select() {
  $element = array(
    'name'      => 'Payment Method Selector',
    'form_key'  => NULL,
    'mandatory' => 1,
    'value'     => '',
    'pid'       => 0,
    'weight'    => 0,
    'extra' => array(
      'payment_description'      => 'Default Payment',
      'selected_payment_methods' => array(),
      'line_items'               => array(),
      'currency_code'            => 'EUR',
      'private'                  => FALSE,
    ),
  );

  return $element;
}

/**
 * Helper function to get a list of all payment methods that have
 * been configured for this drupal installation
 */
function _webform_paymethod_select_payment_method_options() {
  // temporary payment object used just in this function
  $payment = entity_create('payment', array(
    'currency_code'   => 'EUR',
    'description'     => t('Default Payment'),
    'finish_callback' => 'webform_paymethod_select_payment_finish',
  ));

  $payment_method_options = array();

  foreach ($payment->availablePaymentMethods() as $pmid => $payment_method) {
    $payment_method_options[$pmid] = $payment_method->title_specific;
  }

  return $payment_method_options;
}

/**
 * Implements _webform_edit_[component]().
 */
function _webform_edit_paymethod_select($component) {

  $settings = drupal_array_merge_deep(
    array(
      'payment_description'      => 'Default Payment',
      'selected_payment_methods' => array(),
      'currency_code'            => 'EUR',
      'line_items'               => NULL,
    ),
    $component['extra']
  );

  $form = array(
    'extra' => array(
      'payment_description' => array(
        '#type'          => 'textfield',
        '#title'         => t('Payment Description'),
        '#default_value' => $component['extra']['payment_description'],
        '#required'      => TRUE,
      )
    )
  );

  $form['extra']['selected_payment_methods'] = array(
    '#title'         => t('Selected Payment Methods'),
    '#description'   => 'Select 1 or more payment methods that will be available for seletion to the user.',
    '#type'          => 'checkboxes',
    '#options'       => _webform_paymethod_select_payment_method_options(),
    '#default_value' => $settings['selected_payment_methods'],
  );

  $node = node_load($component['nid']);

  require dirname(__FILE__) . '/currency_codes.inc.php';

  $form['extra']['currency_code'] = array(
    '#title'         => t('Select a currency code'),
    '#description'   => t('Select the currency code for this payment.'),
    '#type'          => 'select',
    '#multiple'      => FALSE,
    '#options'       => $currency_codes,
    '#default_value' => $settings['currency_code'],
  );

  $form['extra']['line_items'] = array(
    '#type' => 'fieldset',
    '#title' => t('Line Items'),
  );

  $form['extra']['line_items']['items'] = array(
    '#title'         => t('Line items'),
    '#description'   => t('Define 1 or more line items.'),
    '#type'          => 'payment_line_item',
    '#cardinality'   => 0,
    '#default_value' => $settings['line_items'],
    '#required'      => TRUE,
    '#currency_code' => $settings['currency_code'],
  );

  return $form;
}

/**
 * Implements _webform_render_[component]().
 */
function _webform_render_paymethod_select($component, $value = NULL, $filter = TRUE) {
  $element = array(
    '#type' => 'container',
    '#theme' => 'webform_paymethod_select_placeholder',
    '#title' => $component['name'],
    '#required' => TRUE,
    '#weight' => isset($component['weight']) == TRUE ? $component['weight'] : 0,
    // This is needed for form_builder to resave already stored values when
    // the component's options are not touched during a form_builder session.
    '#selected_payment_methods' => $component['extra']['selected_payment_methods'],
    '#currency_code' => $component['extra']['currency_code'],
    '#line_items' => array('items' => $component['extra']['line_items']),
    '#payment_description' => $component['extra']['payment_description'],
    '#value' => $value ? $value[0] : NULL,
  );

  return $element;
}
