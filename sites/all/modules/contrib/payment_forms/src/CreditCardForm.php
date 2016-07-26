<?php
namespace Drupal\payment_forms;

/**
 *
 */
class CreditCardForm implements FormInterface {
  static protected $issuers = array(
    'visa' => 'Visa',
    'mastercard' => 'MasterCard',
    'amex' => 'American Express',
  );
  static protected $cvc_label = array(
    'visa' => 'CVV2 (Card Verification Value 2)',
    'amex' => 'CID (Card Identification Number)',
    'mastercard' => 'CVC2 (Card Validation Code 2)',
  );

  public function getForm(array &$form, array &$form_state, \Payment $payment) {
    $form['issuer'] = array(
      '#type'		    => 'select',
      '#options'   	=> static::$issuers,
      '#empty_value'	=> '',
      '#title'		=> t('Issuer'),
      '#weight'		=> 0,
    );

    $form['credit_card_number'] = array(
      '#type'      => 'textfield',
      '#title'     => t('Credit card number '),
      '#weight'    => 1,
      '#size'      => 32,
      '#maxlength' => 32,
    );

    $form['secure_code'] = array(
      '#type'      => 'textfield',
      '#title'     => t('Secure code'),
      '#weight'    => 2,
      '#size'      => 4,
      '#maxlength' => 4,
    );

    $form['expiry_date'] = array(
      '#type'   => 'fieldset',
      '#title'  => t('Expiry date'),
      '#weight' => 3,
      '#tree'   => TRUE,
      '#attributes' => array('class' => array('expiry-date')),
    );

    $months = array();
    foreach (range(1, 12) as $month) {
      $month = str_pad($month, 2, '0', STR_PAD_LEFT);
      $months[$month] = $month;
    }
    $year = (int) date('Y');
    $form['expiry_date']['month'] = array(
      '#type' => 'select',
      '#title' => t('Month'),
      '#options' => $months,
      '#attributes' => array('class' => array('expiry-date')),
    );
    $form['expiry_date']['year'] = array(
      '#type' => 'select',
      '#title' => t('Year'),
      '#options' => array_combine(range($year, $year+8), range($year, $year+8)),
    );
    return $form;
  }

  /**
   * Mockable wrapper around form_error().
   */
  protected function formError(array &$element, $error) {
    form_error($element, $error);
  }

  /**
   * Validate and data and set form errors accordingly.
   */
  public function validateValues(array &$element, array &$data) {
    $data['credit_card_number'] = preg_replace('/\s+/', '', $data['credit_card_number']);

    require_once(dirname(__FILE__) . '/../creditcard_validation.inc.php');
    $credit_card_validator = new \CreditCardValidator();

    $validation_result = $credit_card_validator->isValidCreditCard($data['credit_card_number'], '', TRUE);
    if (!$validation_result->valid) {
      $this->formError($element['credit_card_number'], t('%card is not a valid credit card number.', array('%card' => $data['credit_card_number'])));
    }
    elseif ($validation_result->issuer != $data['issuer']) {
      $this->formError($element['credit_card_number'], t(
        'Credit card number %card doesn\'t appear to be from issuer %issuer.',
        array(
          '%card'   => $data['credit_card_number'],
          '%issuer' => self::$issuers[$data['issuer']],
        )
      ));
    }

    // Validate secure code (CVC).
    if (!$credit_card_validator->isValidCardValidationCode($data['secure_code'], $data['issuer'])) {
      $msg = t('The %secure_code_label %code is not valid.', array(
        '%card' => $data['secure_code'],
        '%secure_code_label' => self::$cvc_label[$data['issuer']],
      ));
      $this->formError($element['secure_code'], $msg);
    }

    // Validate expiry date.
    if ($data['expiry_date'] = $this->parseDate($data['expiry_date'])) {
      if ($data['expiry_date']->getTimestamp() < time()) {
        $this->formError($element['expiry_date'], t('The credit card has expired.'));
      }
    } else {
      $this->formError($element['expiry_date'], t('Please enter a valid expiration date'));
    }
  }

  public function parseDate($date) {
    try {
      $dateObj = new \DateTime($date['month'] . '/01/' . $date['year']);
      return $dateObj;
    }
    catch (\Exception $e) {
      // Parsing failed that's fine we return FALSE in that case.
      return FALSE;
    }
  }

  public function validateForm(array &$element, array &$form_state, \Payment $payment) {
    $values = drupal_array_get_nested_value($form_state['values'], $element['#parents']);

    $this->validateValues($element, $values);

    // Merge in validated fields.
    foreach(array('issuer', 'credit_card_number', 'secure_code', 'expiry_date') as $key) {
      $payment->method_data[$key] = $values[$key];
    }
  }
}
