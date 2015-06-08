<?php
/**
 * @file
 * feature_expandable_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_expandable_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_expandable_page_node_info() {
  $items = array(
    'expandable_page' => array(
      'name' => t('Expandable Page'),
      'base' => 'node_content',
      'description' => t('A content type with areas that can be expanded and collapsed.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
