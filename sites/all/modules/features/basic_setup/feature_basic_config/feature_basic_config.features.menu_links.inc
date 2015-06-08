<?php
/**
 * @file
 * feature_basic_config.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feature_basic_config_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_home:<front>
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => 'Home',
      ),
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-footer-nav_site-map:sitemap
  $menu_links['menu-footer-nav_site-map:sitemap'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'sitemap',
    'router_path' => 'sitemap',
    'link_title' => 'Site Map',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-nav_site-map:sitemap',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-footer-nav_statewide-policies:http://az.gov/policies
  $menu_links['menu-footer-nav_statewide-policies:http://az.gov/policies'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'http://az.gov/policies',
    'router_path' => '',
    'link_title' => 'Statewide Policies',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-nav_statewide-policies:http://az.gov/policies',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -25,
    'customized' => 1,
  );
  // Exported menu link: menu-sticky-nav_home:<front>
  $menu_links['menu-sticky-nav_home:<front>'] = array(
    'menu_name' => 'menu-sticky-nav',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => 'Home',
      ),
      'identifier' => 'menu-sticky-nav_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Home');
  t('Site Map');
  t('Statewide Policies');


  return $menu_links;
}
