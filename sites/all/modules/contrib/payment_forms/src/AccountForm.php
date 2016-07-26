<?php
namespace Drupal\payment_forms;

/**
 *
 */
class AccountForm implements FormInterface {
  static protected $id = 0;

  public function getForm(array &$form, array &$form_state, \Payment $payment) {
    $form['holder'] = array(
      '#type'  => 'textfield',
      '#title' => t('Account holder'),
    );

    include_once DRUPAL_ROOT . '/includes/locale.inc';

    $form['ibanbic'] = array(
      '#type'   => 'container',
    );

    $form['ibanbic']['iban'] = array(
      '#type'          => 'textfield',
      '#title'         => t('IBAN'),
      '#required'      => FALSE,
      '#default_value' => NULL,
      '#size'          => 48,
      '#maxlength'     => 48,
    );

    $form['ibanbic']['bic'] = array(
      '#type'          => 'textfield',
      '#title'         => t('BIC'),
      '#required'      => FALSE,
      '#default_value' => NULL,
      '#size'          => 16,
      '#maxlength'     => 16,
    );

    return $form;
  }

  public function validateForm(array &$element, array &$form_state, \Payment $payment) {

    $values = &drupal_array_get_nested_value($form_state['values'], $element['#parents']);
    $method_data = &$payment->method_data;

    $method_data['holder'] = $values['holder'];

    if (empty($values['holder']) == TRUE) {
      form_error($element['holder'], t('Please enter the name of the account holder.'));
    }

    $method_data['iban']    = trim($values['ibanbic']['iban']);
    $method_data['bic']     = trim($values['ibanbic']['bic']);
    $method_data['country'] = substr($method_data['iban'], 0, 2);

    require_once(dirname(__FILE__) . '/../php-iban.php');
    if (verify_iban($method_data['iban']) == FALSE) {
      form_error($element['ibanbic']['iban'], t('Please enter a valid IBAN.'));
    }

    if (preg_match('/^[a-z]{6}[2-9a-z][0-9a-np-z](|xxx|[0-9a-wyz][0-9a-z]{2})$/i', $method_data['bic']) != 1) {
      form_error($element['ibanbic']['bic'], t('Please enter a valid BIC.'));
    }
  }
}
