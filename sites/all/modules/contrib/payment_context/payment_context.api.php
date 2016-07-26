<?php

/**
 * Returns a mapping of context names to classes.
 *
 * The classes must implement the \Drupal\payment_context\Interface.
 * The implementing module has to take care that the class is being autoloaded.
 *
 * @return array
 *   An array of class names keyed by unique machine-names.
 */
function hook_payment_context_info() {
  $classes['webform_paymethod_select'] = '\\Drupal\\webform_paymethod_select\\WebformPaymentContext';
  return $classes;
}
