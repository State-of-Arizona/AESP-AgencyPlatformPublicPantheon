<?php
/**
 * @file
 * Default views based on the available fields from MBP.
 */

/**
 * Implements hook_views_default_views().
 */
function mbp_defaults_views_default_views() {
  //lists of all available MBP fields
  $fields = variable_get('mbp_defaults');

  $views = array();
  foreach ($fields as $key => $field_name) {
    $field_settings = field_info_field($field_name);

    $region = $field_settings['settings']['default_selects']['region'];
    $individual = $field_settings['settings']['default_selects']['individ'];
    $tags = 'mbp_defaults';
    $tags .= $region ? ', mbp_regions' : '';
    $tags .= $individual ? ', mbp_individual' : '';

    $view = new view();
    $view->name = 'mbp_' . $key;
    $view->description = '';
    $view->tag = $tags;
    $view->base_table = 'node';
    $view->human_name = 'Menu Block Placement - ' . $field_name;
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['use_ajax'] = TRUE;
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['query']['options']['distinct'] = TRUE;
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'none';
    $handler->display->display_options['style_plugin'] = 'default';
    $handler->display->display_options['style_options']['row_class'] = 'mbp-defaults-row';
    $handler->display->display_options['row_plugin'] = 'node';
    $handler->display->display_options['row_options']['view_mode'] = 'full';
    $handler->display->display_options['row_options']['links'] = FALSE;
    /* Field: Content: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
    $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
    /* Contextual filter: Content: Block Settings (field_block_settings:region) */
    if ($region) {
      $handler->display->display_options['arguments'][$field_name . '_region']['id'] = $field_name . '_region';
      $handler->display->display_options['arguments'][$field_name . '_region']['table'] = 'field_data_' . $field_name;
      $handler->display->display_options['arguments'][$field_name . '_region']['field'] = $field_name . '_region';
      $handler->display->display_options['arguments'][$field_name . '_region']['default_action'] = 'not found';
      $handler->display->display_options['arguments'][$field_name . '_region']['default_argument_type'] = 'fixed';
      $handler->display->display_options['arguments'][$field_name . '_region']['summary']['number_of_records'] = '0';
      $handler->display->display_options['arguments'][$field_name . '_region']['summary']['format'] = 'default_summary';
      $handler->display->display_options['arguments'][$field_name . '_region']['summary_options']['items_per_page'] = '25';
      $handler->display->display_options['arguments'][$field_name . '_region']['limit'] = '0';
    }
    /* Contextual filter:  Content: Block Settings:mlid (Per Path) */
    $handler->display->display_options['arguments'][$field_name . '_mlid']['id'] = $field_name . '_mlid';
    $handler->display->display_options['arguments'][$field_name . '_mlid']['table'] = 'field_data_' . $field_name;
    $handler->display->display_options['arguments'][$field_name . '_mlid']['field'] = $field_name . '_mlid';
    $handler->display->display_options['arguments'][$field_name . '_mlid']['ui_name'] = $field_name . ':mlid (Per Path)';
    $handler->display->display_options['arguments'][$field_name . '_mlid']['default_action'] = 'default';
    $handler->display->display_options['arguments'][$field_name . '_mlid']['default_argument_type'] = 'menu_block_placement_mlid_per_node';
    $handler->display->display_options['arguments'][$field_name . '_mlid']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments'][$field_name . '_mlid']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments'][$field_name . '_mlid']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['arguments'][$field_name . '_mlid']['limit'] = '0';
    $handler->display->display_options['arguments'][$field_name . '_mlid']['break_phrase'] = TRUE;
    /* Contextual filter:  Content: Block Settings:mlid */
    if ($individual) {
      $handler->display->display_options['arguments'][$field_name . '_mlid_1']['id'] = $field_name . '_mlid_1';
      $handler->display->display_options['arguments'][$field_name . '_mlid_1']['table'] = 'field_data_' . $field_name;
      $handler->display->display_options['arguments'][$field_name . '_mlid_1']['field'] = $field_name . '_mlid';
      $handler->display->display_options['arguments'][$field_name . '_mlid_1']['ui_name'] = $field_name . ':mlid';
      $handler->display->display_options['arguments'][$field_name . '_mlid_1']['default_action'] = 'default';
      $handler->display->display_options['arguments'][$field_name . '_mlid_1']['default_argument_type'] = 'menu_block_placement_mlid';
      $handler->display->display_options['arguments'][$field_name . '_mlid_1']['summary']['number_of_records'] = '0';
      $handler->display->display_options['arguments'][$field_name . '_mlid_1']['summary']['format'] = 'default_summary';
      $handler->display->display_options['arguments'][$field_name . '_mlid_1']['summary_options']['items_per_page'] = '25';
      $handler->display->display_options['arguments'][$field_name . '_mlid_1']['limit'] = '0';
      $handler->display->display_options['arguments'][$field_name . '_mlid_1']['break_phrase'] = TRUE;
    }
    /* Filter criterion: Content: Published */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = 1;
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    if ($individual) {
      /* Filter criterion: Content: Block Settings (field_block_settings:individual_pages) */
      $handler->display->display_options['filters'][$field_name . '_individual_pages']['id'] = $field_name . '_individual_pages';
      $handler->display->display_options['filters'][$field_name . '_individual_pages']['table'] = 'field_data_' . $field_name;
      $handler->display->display_options['filters'][$field_name . '_individual_pages']['field'] = $field_name . '_individual_pages';
      $handler->display->display_options['filters'][$field_name . '_individual_pages']['value']['value'] = '1';
    }
    /* Display: Display */
    $handler = $view->new_display('block', 'Display', 'block');
    $handler->display->display_options['defaults']['sorts'] = FALSE;
    /* Sort criterion: Draggableviews: Weight */
    $handler->display->display_options['sorts']['weight']['id'] = 'weight';
    $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
    $handler->display->display_options['sorts']['weight']['field'] = 'weight';
    $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'mbp_' . $key . ':block_1';
    $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;

    /* Display: Sort */
    $handler = $view->new_display('block', 'Sort', 'block_1');
    $handler->display->display_options['defaults']['access'] = FALSE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['access']['perm'] = 'access draggableviews';
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
      'draggableviews' => 'draggableviews',
      'title' => 'title',
      'edit_node' => 'title',
    );
    $handler->display->display_options['style_options']['default'] = '-1';
    $handler->display->display_options['style_options']['info'] = array(
      'draggableviews' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'title' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'edit_node' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
    );
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Draggableviews: Content */
    $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
    $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
    $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
    $handler->display->display_options['fields']['draggableviews']['label'] = '';
    $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
    $handler->display->display_options['fields']['draggableviews']['draggableviews']['save_button_label'] = 'Save Order';
    $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
    /* Field: Content: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
    $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
    /* Field Content: Edit link */
    $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
    $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
    $handler->display->display_options['fields']['edit_node']['label'] = '';
    $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<br />[edit_node]';
    $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
    $handler->display->display_options['defaults']['sorts'] = FALSE;
    /* Sort criterion: Draggableviews: Weight */
    $handler->display->display_options['sorts']['weight']['id'] = 'weight';
    $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
    $handler->display->display_options['sorts']['weight']['field'] = 'weight';
    $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'self';
    $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;

    $views[] = $view;
  }
  return $views;
}