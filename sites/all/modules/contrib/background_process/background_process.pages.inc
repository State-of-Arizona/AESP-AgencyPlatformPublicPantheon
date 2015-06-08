<?php

/**
 * @file
 * @TODO is this file neccessary?
 */

/**
 * Callback for token validation.
 */
function background_process_check_token() {
  header("Content-Type: text/plain");
  print variable_get('background_process_token', '');
  exit;
}

