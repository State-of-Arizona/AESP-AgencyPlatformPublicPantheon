<?php

namespace Drupal\payment_context;

interface PaymentContextInterface {
  /**
   * Create a payment context from $payment->context_data.
   *
   * @param mixed $data
   * @return object
   *   A payment context object.
   */
  public static function fromContextData($data);
  /**
   * Export into a data structure that can be saved in $payment->context_data.
   *
   * @return mixed
   *   Serializable data structure.
   */
  public function toContextData();
  /**
   * Get a value from the context.
   *
   * Returns the value that this context provides for $key or NULL if it does
   * not provide a value. Usually those values are used to pre-populate payment
   * forms.
   *
   * @param $key string
   * @return mixed
   *   Any value.
   */
  public function value($key);
  /**
   * Redirect user in a to a given url.
   * Parameters are the same as for drupal_goto()
   *
   * @param $path string
   * @param $options array
   */
  public function redirect($path, array $options = array());
  /**
   * Return the machine name for this payment context.
   *
   * This name is stored as $payment->context and used to load the context
   * when the payment is loaded.
   */
  public function name();
}
