<?php
/*
  Credit Card Validator
  Author - Harish Chauhan
           Matthew Heald     matthew.heald@virgin.net
          Matthias Weiss    matthias@more-onion.com


  ABOUT
  This PHP script will calidate credit cards by checking there length
  and pattern and checksum using mod 10.

  Supported credit cards are VISA, MASTERCARD, DISCOVER, AMEX, DINERS,
*/

class CreditCardValidator {

  // copied from http://de.wikipedia.org/wiki/Luhn-Algorithmus#PHP
  // and modified
  public function checkLuhn($number) {
    $sum = (int) 0;
    $numDigits = strlen($number) - 1;
    $is_even = (($numDigits % 2) == 1) ? 0 : 1;

    for ($i = $numDigits; $i >= 0; $i--) {
      $digit = (int) $number[$i];

      if ($is_even == ($i % 2)) {
        $digit <<= 1;
      }

      if ($digit > 9) {
        $digit = $digit - 9;
      }

      $sum += $digit;
    }
    if (($sum % 10) == 0) {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  public function isValidCreditCard($ccnum, $issuer = NULL, $returnobj = FALSE) {

    $ccnum = str_replace(array(' ', '-'), '', $ccnum);

    $creditcard = array(
      'visa'       => '/^4\d{15}$/',
      'mastercard' => '/^5[1-5]\d{14}$/',
      'discover'   => '/^(6011|622[1-9]|64[4-9]\d|65\d{2})\d{12}$/',
      'amex'       => '/^3[4,7]\d{13}$/',
      'diners'     => '/(^(30[0-5]|36\d)\d{11}$)|(^5[45]\d{14}$)/'
    );

    $result = new stdclass;

    $result->valid  = FALSE;
    $result->issuer = NULL;
    $result->ccnum  = $ccnum;

    // if issuer is not set try to guess it from the card number
    if ($issuer == NULL) {
      foreach ($creditcard as $card_issuer => $pattern) {
        if (preg_match($pattern, $ccnum) == 1) {
          $result->issuer = $card_issuer;
          break;
        }
      }
    }
    elseif (   isset($creditcard[$issuer]) == TRUE
            && preg_match($creditcard[$issuer], $ccnum) == 1) {
      $result->issuer = $issuer;
    }

    if (   $result->issuer == NULL
        && $returnobj == FALSE) {
      // we couldn't determine an issuer and no obj is requested as return value
      return FALSE;
    }
    elseif (   $result->issuer != NULL
            && $returnobj == FALSE) {
      return $this->checkLuhn($ccnum);
    }
    else {
      // we have to return an object and we set success or error in the object
      if ($result->issuer != NULL) {
        $result->valid = $this->checkLuhn($ccnum);
      }

      return $result;
    }
  }

  public function isValidSecureCode($sec_code, $issuer) {
    switch ($issuer) {
      case 'visa':
      case 'mastercard':

        if (   preg_match('/^[a-z0-9]{8,16}$/i', $sec_code) == 1
            && preg_match('/^.*[0-9]+.*$/',  substr($sec_code, 0, 8)) == 1
            && preg_match('/^.*[a-z]+.*$/i', substr($sec_code, 0, 8)) == 1) {
          return TRUE;
        }
        else {
          return FALSE;
        }

      default:
        return TRUE;
    }
  }

  public function isValidCardValidationCode($cvc2_code, $issuer) {
    switch ($issuer) {
      case 'visa':
      case 'mastercard':
        if (preg_match('/^\d{3}$/', $cvc2_code) == 1) {
          return TRUE;
        }
        else {
          return FALSE;
        }
        break;

      case 'amex':
        if (preg_match('/^\d{4}$/', $cvc2_code) == 1) {
          return TRUE;
        }
        else {
          return FALSE;
        }
        break;

      default:
        return FALSE;
    }
  }
}
