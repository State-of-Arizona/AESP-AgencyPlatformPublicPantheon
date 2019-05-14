<?php
/**
 * @file
 * feature_webform_honeypot.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_webform_honeypot_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
