<?php
/**
 * @file
 * Variable module integration.
 */

/**
 * Implements hook_variable_info().
 */
function xmlsitemap_engines_variable_info() {
  $variable = array();

  $variable['xmlsitemap_engines_custom_urls'] = array(
    'type' => 'text',
    'title' => t('Custom submission URLs'),
    'description' => t('Enter one URL per line. The token [sitemap] will be replaced with the URL to your sitemap. For example: %example-before would become %example-after.', array('%example-before' => 'http://example.com/ping?[sitemap]', '%example-after' => xmlsitemap_engines_prepare_url('http://example.com/ping?[sitemap]', url('sitemap.xml', array('absolute' => TRUE))))),
    'default' => '',
    'group' => 'xmlsitemap',
  );

  // Build the list of support engines for the checkboxes options.
  $engines = xmlsitemap_engines_get_engine_info();
  $engine_options = array();
  foreach ($engines as $engine => $engine_info) {
    $engine_options[$engine] = $engine_info['name'];
  }
  asort($engine_options);
  $variable['xmlsitemap_engines_engines'] = array(
    'type' => 'options',
    'title' => t('Submit the sitemap to the following engines'),
    'options' => $engine_options,
    'default' => array(),
    'group' => 'xmlsitemap',
  );

  $variable['xmlsitemap_engines_minimum_lifetime'] = array(
    'type' => 'select',
    'title' => t('Do not submit more often than every'),
    'options' => drupal_map_assoc(array(3600, 10800, 21600, 32400, 43200, 86400, 172800, 259200, 604800, 604800 * 2, 604800 * 4), 'format_interval'),
    'default' => 86400,
    'group' => 'xmlsitemap',
  );

  $variable['xmlsitemap_engines_submit_updated'] = array(
    'type' => 'boolean',
    'title' => t('Only submit if the sitemap has been updated since the last submission.'),
    'default' => TRUE,
    'group' => 'xmlsitemap',
  );

  return $variable;
}
