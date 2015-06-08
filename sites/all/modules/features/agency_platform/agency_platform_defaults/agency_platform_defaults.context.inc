<?php
/**
 * @file
 * agency_platform_defaults.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function agency_platform_defaults_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'content_display_blocks';
  $context->description = '';
  $context->tag = 'Site Wide';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/content' => 'admin/content',
      ),
    ),
    'user' => array(
      'values' => array(
        'Contributor' => 'Contributor',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-content_displays-block' => array(
          'module' => 'views',
          'delta' => 'content_displays-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-content_displays-block_1' => array(
          'module' => 'views',
          'delta' => 'content_displays-block_1',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Site Wide');
  $export['content_display_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'nav_breadcrumb_title';
  $context->description = 'Add Page Title to Breadcrumbs for some Pages';
  $context->tag = 'Navigation';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'about' => 'about',
        'contact-us' => 'contact-us',
        'feedback' => 'feedback',
        'frequently-asked-questions' => 'frequently-asked-questions',
      ),
    ),
    'views' => array(
      'values' => array(
        'blogs:page_1' => 'blogs:page_1',
        'press_releases:page_1' => 'press_releases:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'breadcrumb_current_page' => array(
      'breadcrumb_show_current_page' => 1,
      'breadcrumb_show_current_page_title' => '',
      'breadcrumb_show_current_page_only' => 0,
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add Page Title to Breadcrumbs for some Pages');
  t('Navigation');
  $export['nav_breadcrumb_title'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'nav_search';
  $context->description = 'Navigation for Search Results';
  $context->tag = 'Navigation';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search*' => 'search*',
      ),
    ),
  );
  $context->reactions = array(
    'breadcrumb_current_page' => array(
      'breadcrumb_show_current_page' => 1,
      'breadcrumb_show_current_page_title' => 'Search Results',
      'breadcrumb_show_current_page_only' => 1,
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Navigation');
  t('Navigation for Search Results');
  $export['nav_search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site_wide_after';
  $context->description = 'Site wide blocks that appear after other blocks';
  $context->tag = 'Site Wide';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Site Wide');
  t('Site wide blocks that appear after other blocks');
  $export['site_wide_after'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site_wide_before';
  $context->description = 'Site wide blocks that appear before other blocks';
  $context->tag = 'Site Wide';
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
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '0',
        ),
        'delta_blocks-messages' => array(
          'module' => 'delta_blocks',
          'delta' => 'messages',
          'region' => 'header_second',
          'weight' => '-10',
        ),
        'menu-menu-footer-utility' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-utility',
          'region' => 'footer_second',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Site Wide');
  t('Site wide blocks that appear before other blocks');
  $export['site_wide_before'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site_wide_not_home';
  $context->description = 'All pages except for the home page';
  $context->tag = 'Site Wide';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
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
        'delta_blocks-breadcrumb' => array(
          'module' => 'delta_blocks',
          'delta' => 'breadcrumb',
          'region' => 'header_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages except for the home page');
  t('Site Wide');
  $export['site_wide_not_home'] = $context;

  return $export;
}
