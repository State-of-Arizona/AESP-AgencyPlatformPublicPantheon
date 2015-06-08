<?php
/**
 * @file
 * openpublic_home_page_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function openpublic_home_page_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = 'Context for the Home page';
  $context->tag = 'Front Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'theme' => array(
      'values' => array(
        'agency_1' => 'agency_1',
        'agency_2' => 'agency_2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-f357e00a950996a5a5f114f3de9b7a5f' => array(
          'module' => 'views',
          'delta' => 'f357e00a950996a5a5f114f3de9b7a5f',
          'region' => 'header_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for the Home page');
  t('Front Page');
  $export['home'] = $context;

  return $export;
}
