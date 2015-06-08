<?php
/**
 * @file
 * commercial_theme.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function commercial_theme_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'commercial-theme-all-pages';
  $context->description = '';
  $context->tag = 'Blocks';
  $context->conditions = array(
    'theme' => array(
      'values' => array(
        'comm' => 'comm',
        'lottery' => 'lottery',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-sticky-nav' => array(
          'module' => 'menu',
          'delta' => 'menu-sticky-nav',
          'region' => 'user_second',
          'weight' => '-10',
        ),
        'menu-menu-footer-utility' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-utility',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks');
  $export['commercial-theme-all-pages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'commercial-theme-home';
  $context->description = '';
  $context->tag = 'Blocks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'theme' => array(
      'values' => array(
        'comm' => 'comm',
        'lottery' => 'lottery',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-commercial_slider-block' => array(
          'module' => 'views',
          'delta' => 'commercial_slider-block',
          'region' => 'header_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks');
  $export['commercial-theme-home'] = $context;

  return $export;
}
