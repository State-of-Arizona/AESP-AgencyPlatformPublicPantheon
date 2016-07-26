<?php
/**
 * @file
 * feature_search_scs_purchase.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_search_scs_purchase_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "css_injector" && $api == "css_injector_rules") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_search_scs_purchase_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
