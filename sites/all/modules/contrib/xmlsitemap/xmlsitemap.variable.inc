<?php
/**
 * @file
 * Variable module integration.
 */

/**
 * Implements hook_variable_info().
 */
function xmlsitemap_variable_info() {
  $variable = array();

  $variable['xmlsitemap_base_url'] = array(
    'title' => t('Default base URL'),
    'description' => t('This is the default base URL used for sitemaps and sitemap links.'),
    'default' => $GLOBALS['base_url'],
    'required' => TRUE,
    'group' => 'xmlsitemap',
  );

  $variable['xmlsitemap_batch_limit'] = array(
    'type' => 'select',
    'title' => t('Maximum number of sitemap links to process at once'),
    'description' => t('If you have problems running cron or rebuilding the sitemap, you may want to lower this value.'),
    'options' => drupal_map_assoc(array(5, 10, 25, 50, 100, 250, 500, 1000, 2500, 5000)),
    'default' => 100,
    'group' => 'xmlsitemap',
  );

  $variable['xmlsitemap_developer_mode'] = array(
    'type' => 'boolean',
    'title' => t('Enable developer mode to expose additional settings.'),
    'default' => 0,
    'group' => 'xmlsitemap',
  );

  module_load_include('admin.inc', 'xmlsitemap');
  $variable['xmlsitemap_frontpage_changefreq'] = array(
    'type' => 'select',
    'title' => t('Frontpage change frequency'),
    'options' => xmlsitemap_get_changefreq_options(),
    'default' => XMLSITEMAP_FREQUENCY_DAILY,
    'group' => 'xmlsitemap',
  );

  $variable['xmlsitemap_frontpage_priority'] = array(
    'type' => 'select',
    'title' => t('Frontpage priority'),
    'options' => xmlsitemap_get_priority_options(),
    'default' => 1.0,
    'group' => 'xmlsitemap',
  );

  $variable['xmlsitemap_lastmod_format'] = array(
    'type' => 'select',
    'title' => t('Last modification date format'),
    'options' => array(
      XMLSITEMAP_LASTMOD_SHORT => t('Short'),
      XMLSITEMAP_LASTMOD_MEDIUM => t('Medium'),
      XMLSITEMAP_LASTMOD_LONG => t('Long'),
    ),
    'default' => XMLSITEMAP_LASTMOD_MEDIUM,
    'group' => 'xmlsitemap',
  );
  foreach ($variable['xmlsitemap_lastmod_format']['options'] as $key => &$label) {
    $label .= ' (' . gmdate($key, REQUEST_TIME) . ')';
  }

  $variable['xmlsitemap_minimum_lifetime'] = array(
    'type' => 'select',
    'title' => t('Minimum sitemap lifetime'),
    'options' => array(0 => t('No minimum')) + drupal_map_assoc(array(300, 900, 1800, 3600, 10800, 21600, 43200, 86400, 172800, 259200, 604800), 'format_interval'),
    'description' => t('The minimum amount of time that will elapse before the sitemaps are regenerated. The sitemaps will also only be regenerated on cron if any links have been added, updated, or deleted.') . '<br />' . t('Recommended value: %value.', array('%value' => t('1 day'))),
    'default' => 0,
    'group' => 'xmlsitemap',
  );

  $variable['xmlsitemap_path'] = array(
    'title' => t('Sitemap cache directory'),
    'description' => t('Subdirectory where the sitemap data will be stored. This folder <strong>must not be shared</strong> with any other Drupal site or install using XML sitemap.'),
    'default' => 'xmlsitemap',
    'required' => TRUE,
    'group' => 'xmlsitemap',
  );

  $variable['xmlsitemap_prefetch_aliases'] = array(
    'type' => 'boolean',
    'title' => t('Prefetch URL aliases during sitemap generation.'),
    'description' => t('When enabled, this will fetch all URL aliases at once instead of one at a time during sitemap generation. For medium or large sites, it is recommended to disable this feature as it uses a lot of memory.'),
    'default' => 1,
    'group' => 'xmlsitemap',
  );

  $variable['xmlsitemap_xsl'] = array(
    'type' => 'boolean',
    'title' => t('Include a stylesheet in the sitemaps for humans.'),
    'description' => t('When enabled, this will add formatting and tables with sorting to make it easier to view the XML sitemap data instead of viewing raw XML output. Search engines will ignore this.'),
    'default' => 1,
    'group' => 'xmlsitemap',
  );


  return $variable;
}

/**
 * Implements hook_variable_group_info().
 */
function xmlsitemap_variable_group_info() {
  $groups['xmlsitemap'] = array(
    'title' => t('XML sitemap'),
    'description' => t('XML sitemap configuration settings'),
    'access' => 'administer xmlsitemap',
    'path' => array('admin/config/search/xmlsitemap'),
  );
  return $groups;
}
