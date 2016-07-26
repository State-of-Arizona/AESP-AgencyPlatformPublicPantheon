<?php

namespace Drupal\payment_forms;

/**
 *
 */
class OnlineBankingForm implements FormInterface {

  public function getForm(array &$form, array &$form_state, \Payment $payment) {
    $form['redirection_info'] = array(
      '#type'	=> 'markup',
      '#markup'  => t('After submitting this form you will be redirected to our external payment partner to finish the transaction.'),
      '#weight'	=> 0,
    );

    return $form;
  }

  public function validateForm(array &$element, array &$form_state, \Payment $payment) {
    // safe reference to form_state, needed for later execute()
    $payment->form_state = &$form_state;
  }
}
