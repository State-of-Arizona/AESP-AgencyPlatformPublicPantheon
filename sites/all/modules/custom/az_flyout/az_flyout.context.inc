<?php
/**
 * @file
 * az_flyout1.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function az_flyout_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'az_flyout';
  $context->description = '';
  $context->tag = 'AZ Flyout';
  $context->conditions = array(
    'admin_theme' => array(
      'values' => array(
        'non_admin' => 'non_admin',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'az_flyout-az_flyout' => array(
          'module' => 'az_flyout',
          'delta' => 'az_flyout',
          'region' => 'user_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('AZ Flyout');
  $export['az_flyout'] = $context;

  return $export;
}
