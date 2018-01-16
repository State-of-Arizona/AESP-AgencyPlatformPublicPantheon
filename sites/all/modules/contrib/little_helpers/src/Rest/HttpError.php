<?php

namespace Drupal\little_helpers\Rest;

/**
 * An exception class that signifies a non 200 HTTP response.
 */
class HttpError extends \Exception {

  public $result;

  /**
   * Construct the error class from a result object.
   */
  public function __construct($result) {
    $msg = "HTTP {$result->code}: {$result->error}";
    parent::__construct($msg, $result->code);
    $this->result = $result;
  }

}
