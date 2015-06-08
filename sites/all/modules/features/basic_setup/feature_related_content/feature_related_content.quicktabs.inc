<?php
/**
 * @file
 * feature_related_content.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function feature_related_content_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'draggable_views_related_content';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Draggable Views Related Content';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'views_delta_related_content-block_1',
      'hide_title' => 1,
      'title' => 'Display',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'views_delta_related_content-block',
      'hide_title' => 1,
      'title' => 'Sort',
      'weight' => '-99',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Zen';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Display');
  t('Draggable Views Related Content');
  t('Sort');

  $export['draggable_views_related_content'] = $quicktabs;

  return $export;
}
