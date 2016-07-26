<?php
namespace Drupal\payment_forms;

/**
 * Interface that all payment forms provide to PaymentContexts using them.
 */
interface FormInterface {
  public function getForm(array &$element, array &$form_state, \Payment $payment);
  public function validateForm(array &$element, array &$form_state, \Payment $payment);
}
