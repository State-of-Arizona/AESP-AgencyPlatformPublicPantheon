<?php
/**
 * @file
 * feature_sliver.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_sliver_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
