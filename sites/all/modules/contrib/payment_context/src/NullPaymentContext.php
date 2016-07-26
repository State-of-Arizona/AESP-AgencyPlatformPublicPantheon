<?php

namespace Drupal\payment_context;

/**
 * Default payment context.
 *
 * This payment context provides default behavior that can be safely assumed
 * from any context. If no other context object is explicitly set an instance
 * of this class is put as $payment->contextObj.
 */
class NullPaymentContext {
  public function name() { return 'null'; }
  public function value($key) { return NULL; }
  public function redirect($path, $options) {
    drupal_goto($path, $options);
  }
}
