<?php
/**
 * @file
 * feature_basic_content.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function feature_basic_content_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'body'
  $field_bases['body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'node',
    ),
    'field_name' => 'body',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_available_views'
  $field_bases['field_available_views'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_available_views',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'insert_view_gen',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'insert_view_generator',
  );

  // Exported field_base: 'field_basic_block_block_sections'
  $field_bases['field_basic_block_block_sections'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_basic_block_block_sections',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'menu_block_placement',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => '',
      'default_menus' => array(
        'devel' => 0,
        'main-menu' => 'main-menu',
        'management' => 0,
        'menu-footer-nav' => 0,
        'menu-sticky-nav' => 0,
        'navigation' => 0,
        'user-menu' => 0,
      ),
      'default_selects' => array(
        'individ' => 'individ',
        'region' => 'region',
      ),
    ),
    'translatable' => 0,
    'type' => 'menu_block_placement_reference',
  );

  // Exported field_base: 'field_basic_page_tab_body'
  $field_bases['field_basic_page_tab_body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_basic_page_tab_body',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_basic_page_tab_label'
  $field_bases['field_basic_page_tab_label'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_basic_page_tab_label',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 50,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_basic_page_tabs'
  $field_bases['field_basic_page_tabs'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_basic_page_tabs',
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_basic_slideshow_assignment'
  $field_bases['field_basic_slideshow_assignment'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_basic_slideshow_assignment',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'menu_block_placement',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => '',
      'default_menus' => array(
        'main-menu' => 'main-menu',
        'management' => 0,
        'menu-footer-utility' => 0,
        'menu-sticky-nav' => 0,
        'navigation' => 0,
        'user-menu' => 0,
      ),
      'default_selects' => array(
        'individ' => 0,
        'region' => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'menu_block_placement_reference',
  );

  // Exported field_base: 'field_basic_slideshow_caption'
  $field_bases['field_basic_slideshow_caption'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_basic_slideshow_caption',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_basic_slideshow_effect'
  $field_bases['field_basic_slideshow_effect'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_basic_slideshow_effect',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'blindY' => 'blind',
        'cover' => 'cover',
        'fade' => 'fade',
        'scrollUp' => 'scrollUp',
        'scrollDown' => 'scrollDown',
        'scrollLeft' => 'scrollLeft',
        'scrollRight' => 'scrollRight',
        'scrollHorz' => 'scrollHorz',
        'scrollVert' => 'scrollVert',
        'shuffle' => 'shuffle',
        'toss' => 'toss',
        'turnUp' => 'turnUp',
        'turnDown' => 'turnDown',
        'turnLeft' => 'turnLeft',
        'turnRight' => 'turnRight',
        'uncover' => 'uncover',
        'wipe' => 'wipe',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_basic_slideshow_images'
  $field_bases['field_basic_slideshow_images'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_basic_slideshow_images',
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_basic_slideshow_style'
  $field_bases['field_basic_slideshow_style'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_basic_slideshow_style',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'basic-slideshow-style-1' => 'Side by Side',
        'basic-slideshow-style-2' => 'Large Image',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_slideshow_image'
  $field_bases['field_slideshow_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_slideshow_image',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_slideshow_image_link'
  $field_bases['field_slideshow_image_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_slideshow_image_link',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  return $field_bases;
}
