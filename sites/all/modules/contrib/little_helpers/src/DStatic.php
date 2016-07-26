<?php

namespace Drupal\little_helpers;

/**
 * This class deals with request wide variables and flags. It's best to think
 * of it like an object oriented version of drupal_static().
 */
class DStatic {
  protected static $data = array();
  /**
   * Set a value by value. This is mainly for convenience (default value) and
   * so that calls like:
   *  DStatic::setFlag('name', 'somevalue');
   * work without warings.
   *
   * @param string $name
   *   name of the value to set.
   * @param mixed $value
   *   value of any type to store.
   */
  public static function setFlag($name, $value = TRUE) {
    self::$data[$name] = $value;
  }
  /**
   * Set a value by reference.
   *
   * @param string $name
   *   name of the value to set.
   * @param mixed $value
   *   value of any type to store.
   */
  public static function set($name, &$value) {
    self::$data[$name] = &$value;
  }
  /**
   * Get a stored value.
   *
   * @param string $name
   *   name of the value to get.
   */
  public static function get($name) {
    return isset(self::$data[$name]) ? self::$data[$name] : NULL;
  }
  /**
   * Delete all static variables that have been accumulated in this request.
   */
  public static function reset() {
    self::$data = array();
  }
}
