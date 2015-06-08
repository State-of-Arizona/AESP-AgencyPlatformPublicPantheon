<?php
/**
 * @file
 * agency_platform_editor_s_choice.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function agency_platform_editor_s_choice_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function agency_platform_editor_s_choice_node_info() {
  $items = array(
    'editor_s_choice' => array(
      'name' => t('Editor\'s Choice'),
      'base' => 'node_content',
      'description' => t('A block of text/content that can be placed throughout the site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
