<?php
/**
 * @file
 * agency_platform_defaults.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function agency_platform_defaults_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: features.
  $menus['features'] = array(
    'menu_name' => 'features',
    'title' => 'Features',
    'description' => 'Menu items for any enabled features.',
  );
  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: management.
  $menus['management'] = array(
    'menu_name' => 'management',
    'title' => 'Management',
    'description' => 'The <em>Management</em> menu contains links for administrative tasks.',
  );
  // Exported menu: menu-footer-utility.
  $menus['menu-footer-utility'] = array(
    'menu_name' => 'menu-footer-utility',
    'title' => 'Footer Utility',
    'description' => 'Contains Accessibility, Feeds, Privacy, Tools',
  );
  // Exported menu: menu-layout-options.
  $menus['menu-layout-options'] = array(
    'menu_name' => 'menu-layout-options',
    'title' => 'Layout Options Menu',
    'description' => 'Current Navigation for the Layout menu',
  );
  // Exported menu: menu-utility.
  $menus['menu-utility'] = array(
    'menu_name' => 'menu-utility',
    'title' => 'Utility',
    'description' => 'List User and Feedback Links',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Contains Accessibility, Feeds, Privacy, Tools');
  t('Current Navigation for the Layout menu');
  t('Features');
  t('Footer Utility');
  t('Layout Options Menu');
  t('List User and Feedback Links');
  t('Main menu');
  t('Management');
  t('Menu items for any enabled features.');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('The <em>Management</em> menu contains links for administrative tasks.');
  t('Utility');


  return $menus;
}
