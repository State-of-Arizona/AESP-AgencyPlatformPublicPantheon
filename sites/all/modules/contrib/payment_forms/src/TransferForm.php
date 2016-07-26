<?php

namespace Drupal\payment_forms;

/**
 *
 */
class TransferForm implements FormInterface {

  public function getForm(array &$form, array &$form_state, \Payment $payment) {
    $form['send_transfer_form'] = array(
      '#type'     => 'markup',
      '#markup'    => t('The transfer form will be sent to the address you provided earlier.'),
    );

    return $form;
  }

  public function validateForm(array &$element, array &$form_state, \Payment $payment) {
    $values = drupal_array_get_nested_value($form_state['values'], $element['#parents']);

    if (!empty($values['send_transfer_form'])) {
      $payment->method_data['send_transfer_form'] = $values['send_transfer_form'];
    }
  }
}
