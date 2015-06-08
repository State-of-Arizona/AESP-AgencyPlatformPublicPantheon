<?php
/**
 * @file
 * feature_basic_config.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_basic_config_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'basic_config_blocks';
  $context->description = '';
  $context->tag = 'Basic Setup';
  $context->conditions = array(
    'admin_theme' => array(
      'values' => array(
        'non_admin' => 'non_admin',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'branding',
          'weight' => '0',
        ),
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'menu',
          'weight' => '0',
        ),
        'delta_blocks-breadcrumb' => array(
          'module' => 'delta_blocks',
          'delta' => 'breadcrumb',
          'region' => 'header_second',
          'weight' => '10',
        ),
        'menu-menu-footer-nav' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-nav',
          'region' => 'footer_second',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Setup');
  $export['basic_config_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'image_style_preview';
  $context->description = '';
  $context->tag = 'Basic Setup';
  $context->conditions = array(
    'admin_theme' => array(
      'values' => array(
        'admin' => 'admin',
      ),
    ),
    'path' => array(
      'values' => array(
        'admin/config/media/image-styles' => 'admin/config/media/image-styles',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'image_style_preview-image_style_preview' => array(
          'module' => 'image_style_preview',
          'delta' => 'image_style_preview',
          'region' => 'content',
          'weight' => '17',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Setup');
  $export['image_style_preview'] = $context;

  return $export;
}
