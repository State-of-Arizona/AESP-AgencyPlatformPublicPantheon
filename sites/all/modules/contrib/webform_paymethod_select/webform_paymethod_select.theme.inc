<?php

/**
 * Returns HTML for the webform component if payment options are displayed.
 * @param array $variables
 *   - element: the placeholder element with the following special keys:
 *     - #title: The component name.
 *     - #payment_description
 *     - #selected_payment_methods: Enabled payment methods (pmids) for this
 *         component.
 *     - #currency_code: Code of the selected currency.
 *     - #line_items: An array of payment_line_items.
 *     - #payment: The payment object.
 *
 * @ingroup themeable
 */
function theme_webform_paymethod_select_component(&$variables) {
  $element = &$variables['element'];
  $children = element_children($element, TRUE);
  $output = '';
  foreach ($children as $key) {
    $output .= drupal_render($elements[$key]);
  }
  return $output;
}

/**
 * Returns HTML for the webform component if there is already a payment with
 * a successful status.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: the placeholder element with the following special keys:
 *     - #title: The component name.
 *     - #payment_description
 *     - #selected_payment_methods: Enabled payment methods (pmids) for this
 *         component.
 *     - #currency_code: Code of the selected currency.
 *     - #line_items: An array of payment_line_items.
 *     - #payment: The payment object.
 *
 * @ingroup themeable
 */
function theme_webform_paymethod_select_already_paid(&$variables) {
  $element = &$variables['element'];
  $payment = $element['#payment'];

  $render = array(
    '#theme_wrappers' => array('fieldset'),
    '#title' => t('Payment made.'),
    '#description' => t('The payment has been processed successfully.'),
  );

  return render($render);
}

/**
 * Returns HTML for the webform_paymethod_select form_builder placeholder.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: the placeholder element with the following special keys:
 *     - #title: The component name.
 *     - #payment_description
 *     - #selected_payment_methods: Enabled payment methods (pmids) for this
 *         component.
 *     - #currency_code: Code of the selected currency.
 *     - #line_items: An array of payment_line_items.
 *     - #payment: The payment object.
 *
 * @ingroup themeable
 */
function theme_webform_paymethod_select_placeholder(&$variables) {
  $element = &$variables['element'];

  $render = array(
    '#theme_wrappers' => array('fieldset'),
    '#title' => $element['#title'],
  );

  $pmids = array_keys(array_filter($element['#selected_payment_methods']));
  $methods = array();
  foreach (entity_load('payment_method', $pmids) as $pm) {
    $methods[] = $pm->title_specific;
  }
  if (!$methods) {
    $methods[] = t('No payment method is enabled at the moment. Please enable at least one.');
  }

  $render['payment_methods'] = array(
    '#theme' => 'item_list',
    '#title' => t('Enabled payment methods'),
    '#items' => $methods,
  );

  return render($render);
}
