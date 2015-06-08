<?php
/**
 * @file
 * A views plugin to add a contextual filter
 */

/**
 * Implements hook_views_plugins().
 */
function menu_block_placement_views_plugins() {
  return array(
    'module' => 'views',
    'argument validator' => array(
      'menu_block_placement' => array(
        'title' => t('Menu Block Placement'),
        'handler' => 'views_plugin_argument_validate_node',
      ),
    ),
    'argument default' => array(
      'menu_block_placement_mlid' => array(
        'title' => t('Active Menu Tree - Menu Block Placement'),
        'handler' => 'views_plugin_argument_default_menu_block_placement',
        'parent' => 'fixed',
      ),
      'menu_block_placement_mlid_per_node' => array(
        'title' => t('Active Menu Item - Menu Block Placement Per Path'),
        'handler' => 'views_plugin_argument_default_menu_block_placement_per_path',
        'parent' => 'fixed',
      ),
    ),
  );
}