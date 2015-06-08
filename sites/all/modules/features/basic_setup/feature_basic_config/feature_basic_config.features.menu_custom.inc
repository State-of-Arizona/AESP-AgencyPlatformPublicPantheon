<?php
/**
 * @file
 * feature_basic_config.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function feature_basic_config_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer-nav.
  $menus['menu-footer-nav'] = array(
    'menu_name' => 'menu-footer-nav',
    'title' => 'Footer Nav',
    'description' => '',
  );
  // Exported menu: menu-sticky-nav.
  $menus['menu-sticky-nav'] = array(
    'menu_name' => 'menu-sticky-nav',
    'title' => 'Sticky Nav',
    'description' => 'A top mobile menu for the commercial theme.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('A top mobile menu for the commercial theme.');
  t('Footer Nav');
  t('Sticky Nav');


  return $menus;
}
