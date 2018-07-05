<?php
/**
 * @file
 * feature_basic_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_basic_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_basic_content_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_basic_content_image_default_styles() {
  $styles = array();

  // Exported image style: slideshow_image.
  $styles['slideshow_image'] = array(
    'label' => 'Slideshow Image (1240 x 460)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1240,
          'height' => 460,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function feature_basic_content_node_info() {
  $items = array(
    'basic_block' => array(
      'name' => t('Basic Block'),
      'base' => 'node_content',
      'description' => t('A section of text that can be placed in a region and on multiple pages.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'basic_page' => array(
      'name' => t('Basic Page'),
      'base' => 'node_content',
      'description' => t('A basic page that can be placed in the menu.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'basic_slideshow' => array(
      'name' => t('Basic Slideshow'),
      'base' => 'node_content',
      'description' => t('Content that can be used as a slideshow and placed at the top of any page within the menu'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
