<?php
/**
 * @file
 * Places the constructed blocks in their appropriate regions.
 */

/**
 * Implements hook_context_default_contexts().
 */
function mbp_defaults_context_default_contexts() {
  $export = array();
  $fields = variable_get('mbp_defaults');
  $regions = variable_get('mbp_regions');

  $blocks = array();
  foreach ($fields as $fkey => $field) {
    $field_info = field_info_field($field);
    if (isset($field_info['columns']['region'])) {
      foreach ($regions as $rkey => $rlabel) {
        $blocks["mbp_defaults-mbp-$fkey-$rkey"] = array(
          'module' => 'mbp_defaults',
          'delta' => "mbp-$fkey-$rkey",
          'region' => $rkey,
          'weight' => 5,
        );
      }
    }
  }

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mbp_defaults';
  $context->description = 'Region designation for default blocks';
  $context->tag = 'Menu Block Placement';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~node/*/edit' => '~node/*/edit',
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
      'blocks' => $blocks,
    ),
  );

  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Menu Block Placement');
  t('Region designation for default blocks');
  $export['mbp_defaults'] = $context;

  return $export;
}
