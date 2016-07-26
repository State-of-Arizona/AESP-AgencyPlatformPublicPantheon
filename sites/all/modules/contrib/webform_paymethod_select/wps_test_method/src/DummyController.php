<?php

namespace Drupal\wps_test_method;

class DummyController extends \PaymentMethodController {
  public $payment_configuration_form_elements_callback = 'payment_forms_method_form';
  public $form;
  public function __construct() {
    $this->form = new DummyForm();
    $this->title = 'Dummy payment method.';
    $this->description = 'This payment method allows to mock payment provider behavior.';
  }

  /**
   * Implements PaymentMethodController::validate().
   */
  function validate(\Payment $payment, \PaymentMethod $payment_method, $strict) {
    if (!$strict)
      return;

    if (isset($payment->context_data['method_data'])) {
      sleep($payment->context_data['method_data']['validate_timeout']);
    }
  }

  /**
   * Implements PaymentMethodController::execute().
   */
  function execute(\Payment $payment) {
    $data = &$payment->context_data['method_data'];
    $redirect = NULL;

    if (!empty($data['redirect'])) {
      $payment->setStatus(new \PaymentStatusItem(PAYMENT_STATUS_PENDING));
      $path = WPS_TEST_PAYMENT_REDIRECT_URL . (int) $payment->pid;
      $redirect = array($path, array());
    }
    else {
      $payment->setStatus(new \PaymentStatusItem($data['status']));
    }

    if ($redirect) {
      $payment->contextObj->redirect($redirect[0], $redirect[1]);
    }
  }
}
