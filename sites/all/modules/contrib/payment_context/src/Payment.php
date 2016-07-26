<?php

namespace Drupal\payment_context;

class Payment extends \Payment {
  /**
   * An object representing the payment context.
   *
   * @var \Drupal\payment_context\PaymentContextInterface
   */
  public $contextObj;
  /**
   * @inherit
   */
  public function __construct(array $properties = array()) {
    parent::__construct($properties);
    if (empty($this->contextObj)) {
      $this->contextObj = new NullPaymentContext();
    }
  }
}
