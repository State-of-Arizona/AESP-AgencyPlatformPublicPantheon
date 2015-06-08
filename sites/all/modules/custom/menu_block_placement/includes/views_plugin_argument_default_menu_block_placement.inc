<?php
/**
 * @file
 * A contectual filter that allows content to show per menu hierarchy
 */

/**
 * Extending views_plugin_argument_default_node()
 */
class views_plugin_argument_default_menu_block_placement extends views_plugin_argument_default {

  /**
   * Provide an imploded list of mlids
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
      for ($i = 1; $i < 9; $i++) {
        if ($row['p' . $i]) {
          $mlids[] = $row['p' . $i];
        }
      }
    }

    if (!empty($mlids)) {
      return implode('+', $mlids);
    }
    else {
      return FALSE;
    }

  }
}