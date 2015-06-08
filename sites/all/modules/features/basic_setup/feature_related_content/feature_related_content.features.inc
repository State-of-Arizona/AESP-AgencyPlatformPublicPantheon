<?php
/**
 * @file
 * feature_related_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_related_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_related_content_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
