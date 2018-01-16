<?php

namespace Drupal\little_helpers;

class ArrayConfig {

  /**
   * Helper functions that recursively merges $defaults into a $config array.
   *
   * @param array &$config
   *   A config array to merge the defaults into.
   * @param array $defaults
   *   The defaults array.
   */
  public static function mergeDefaults(array &$config, array $defaults) {
    $config += $defaults;
    foreach ($config as $key => $value) {
      if (is_array($value) && isset($defaults[$key]) && is_array($defaults[$key])) {
        // Only merge sub-arrays for empty or associative arrays.
        $is_assoc = empty($value) || array_keys($value) !== range(0, count($value) - 1);
        if ($is_assoc) {
          self::mergeDefaults($config[$key], $defaults[$key]);
        }
      }
    }
  }

}
