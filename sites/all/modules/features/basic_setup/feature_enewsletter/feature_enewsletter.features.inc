<?php
/**
 * @file
 * feature_enewsletter.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_enewsletter_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_enewsletter_node_info() {
  $items = array(
    'enewsletter_subscription' => array(
      'name' => t('ENewsletter Subscription'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
