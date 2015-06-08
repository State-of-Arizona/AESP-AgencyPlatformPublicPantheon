<?php
/**
 * @file
 * A contectual filter that allows content to show per menu item (not hierarchical)
 */

/**
 * Extending views_plugin_argument_default_node()
 */
class views_plugin_argument_default_menu_block_placement_per_path extends views_plugin_argument_default {
  /**
   * Provide the mlid
   */
  function get_argument() {
    $path = current_path();
    if ($path == variable_get('site_frontpage', 'node')) {
      $path = '<front>';
    }
    $menus = array();
    foreach ($this->view->argument as $arg) {
      if (strpos($arg->options['default_argument_type'], 'menu_block_placement_mlid') !== FALSE) {
        $field = field_info_field($arg->definition['field_name']);
        $menus = array_merge($menus, array_filter($field['settings']['default_menus']));
      }
    }

    foreach ($menus as $menu) {
      $row = db_select('menu_links', 'm')
        ->fields('m')
        ->condition('menu_name', $menu)
        ->condition('link_path', $path)
        ->execute()
        ->fetchAssoc();

      $mlids[] = $row['mlid'];
    }

    if (!empty($mlids)) {
      return implode('+', array_filter($mlids));
    }
    else {
      return FALSE;
    }
  }
}