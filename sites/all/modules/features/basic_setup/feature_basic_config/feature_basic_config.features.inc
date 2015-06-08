<?php
/**
 * @file
 * feature_basic_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_basic_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_basic_config_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
