<?php
/**
 * @file
 * feature_az_antispam.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_az_antispam_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
