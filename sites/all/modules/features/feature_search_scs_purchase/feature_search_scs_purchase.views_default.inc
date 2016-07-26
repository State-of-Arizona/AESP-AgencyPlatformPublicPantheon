<?php
/**
 * @file
 * feature_search_scs_purchase.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_search_scs_purchase_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'scs_search_webform_results';
  $view->description = '';
  $view->tag = 'webform';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'SCS Search Webform Results';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 50, 100, 200, 500, 1000';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = 'All';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'value' => 'value',
    'serial' => 'serial',
  );
  $handler->display->display_options['style_options']['default'] = 'serial';
  $handler->display->display_options['style_options']['info'] = array(
    'value' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'serial' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Header: Global: Result summary with an additional token to change the items/page */
  $handler->display->display_options['header']['webform_result']['id'] = 'webform_result';
  $handler->display->display_options['header']['webform_result']['table'] = 'views';
  $handler->display->display_options['header']['webform_result']['field'] = 'webform_result';
  $handler->display->display_options['header']['webform_result']['content'] = '<div class="webform-results-per-page">Showing @start - @end of @total. &nbsp; @items_per_page_links</div>';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'There are no submissions for this form or results from this search query. <a href="/node/!1">View this form</a>.';
  $handler->display->display_options['empty']['area_text_custom']['tokenize'] = TRUE;
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Webform submissions: Data */
  $handler->display->display_options['relationships']['data']['id'] = 'data';
  $handler->display->display_options['relationships']['data']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['data']['field'] = 'data';
  $handler->display->display_options['relationships']['data']['label'] = 'Last Name';
  $handler->display->display_options['relationships']['data']['required'] = TRUE;
  $handler->display->display_options['relationships']['data']['webform_nid'] = '1890';
  $handler->display->display_options['relationships']['data']['webform_cid'] = '3';
  /* Relationship: Webform submissions: Data */
  $handler->display->display_options['relationships']['data_1']['id'] = 'data_1';
  $handler->display->display_options['relationships']['data_1']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['data_1']['field'] = 'data';
  $handler->display->display_options['relationships']['data_1']['label'] = 'First Name';
  $handler->display->display_options['relationships']['data_1']['required'] = TRUE;
  $handler->display->display_options['relationships']['data_1']['webform_nid'] = '1890';
  $handler->display->display_options['relationships']['data_1']['webform_cid'] = '2';
  /* Field: Webform submissions: Serial number */
  $handler->display->display_options['fields']['serial']['id'] = 'serial';
  $handler->display->display_options['fields']['serial']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['serial']['field'] = 'serial';
  $handler->display->display_options['fields']['serial']['label'] = '';
  $handler->display->display_options['fields']['serial']['exclude'] = TRUE;
  $handler->display->display_options['fields']['serial']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['serial']['alter']['text'] = '[view_submission]
';
  $handler->display->display_options['fields']['serial']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['serial']['separator'] = '';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['label'] = 'Permit Type';
  $handler->display->display_options['fields']['value']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['value']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value']['webform_nid'] = '1890';
  $handler->display->display_options['fields']['value']['webform_cid'] = '1';
  /* Field: Webform submissions: View link */
  $handler->display->display_options['fields']['view_submission']['id'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['view_submission']['field'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['label'] = 'Permit #';
  $handler->display->display_options['fields']['view_submission']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_submission']['text'] = '[serial]';
  $handler->display->display_options['fields']['view_submission']['access_check'] = 1;
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['label'] = 'Reference #';
  $handler->display->display_options['fields']['value_1']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_1']['webform_nid'] = '1890';
  $handler->display->display_options['fields']['value_1']['webform_cid'] = '15';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_2']['id'] = 'value_2';
  $handler->display->display_options['fields']['value_2']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_2']['field'] = 'value';
  $handler->display->display_options['fields']['value_2']['label'] = '';
  $handler->display->display_options['fields']['value_2']['webform_nid'] = '1890';
  $handler->display->display_options['fields']['value_2']['webform_cid'] = '14';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_3']['id'] = 'value_3';
  $handler->display->display_options['fields']['value_3']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_3']['field'] = 'value';
  $handler->display->display_options['fields']['value_3']['label'] = '';
  $handler->display->display_options['fields']['value_3']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['value_3']['webform_nid'] = '1890';
  $handler->display->display_options['fields']['value_3']['webform_cid'] = '3';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_4']['id'] = 'value_4';
  $handler->display->display_options['fields']['value_4']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_4']['field'] = 'value';
  $handler->display->display_options['fields']['value_4']['label'] = 'Last Name';
  $handler->display->display_options['fields']['value_4']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['value_4']['webform_nid'] = '1890';
  $handler->display->display_options['fields']['value_4']['webform_cid'] = '2';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_5']['id'] = 'value_5';
  $handler->display->display_options['fields']['value_5']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_5']['field'] = 'value';
  $handler->display->display_options['fields']['value_5']['label'] = '';
  $handler->display->display_options['fields']['value_5']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['value_5']['webform_nid'] = '1890';
  $handler->display->display_options['fields']['value_5']['webform_cid'] = '5';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_6']['id'] = 'value_6';
  $handler->display->display_options['fields']['value_6']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_6']['field'] = 'value';
  $handler->display->display_options['fields']['value_6']['label'] = 'Product';
  $handler->display->display_options['fields']['value_6']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['value_6']['webform_nid'] = '1890';
  $handler->display->display_options['fields']['value_6']['webform_cid'] = '6';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_7']['id'] = 'value_7';
  $handler->display->display_options['fields']['value_7']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_7']['field'] = 'value';
  $handler->display->display_options['fields']['value_7']['label'] = '';
  $handler->display->display_options['fields']['value_7']['webform_nid'] = '1890';
  $handler->display->display_options['fields']['value_7']['webform_cid'] = '7';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_8']['id'] = 'value_8';
  $handler->display->display_options['fields']['value_8']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_8']['field'] = 'value';
  $handler->display->display_options['fields']['value_8']['label'] = '';
  $handler->display->display_options['fields']['value_8']['webform_nid'] = '1890';
  $handler->display->display_options['fields']['value_8']['webform_cid'] = '8';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_9']['id'] = 'value_9';
  $handler->display->display_options['fields']['value_9']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_9']['field'] = 'value';
  $handler->display->display_options['fields']['value_9']['label'] = '';
  $handler->display->display_options['fields']['value_9']['webform_nid'] = '1890';
  $handler->display->display_options['fields']['value_9']['webform_cid'] = '9';
  /* Contextual filter: Webform submissions: Node */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'webform' => 'webform',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['value']['value'] = '1891';
  /* Filter criterion: Webform submission data: Data field */
  $handler->display->display_options['filters']['data']['id'] = 'data';
  $handler->display->display_options['filters']['data']['table'] = 'webform_submitted_data';
  $handler->display->display_options['filters']['data']['field'] = 'data';
  $handler->display->display_options['filters']['data']['relationship'] = 'data';
  $handler->display->display_options['filters']['data']['operator'] = 'contains';
  $handler->display->display_options['filters']['data']['exposed'] = TRUE;
  $handler->display->display_options['filters']['data']['expose']['operator_id'] = 'data_op';
  $handler->display->display_options['filters']['data']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['data']['expose']['operator'] = 'data_op';
  $handler->display->display_options['filters']['data']['expose']['identifier'] = 'data';
  $handler->display->display_options['filters']['data']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Webform submission data: Data field */
  $handler->display->display_options['filters']['data_1']['id'] = 'data_1';
  $handler->display->display_options['filters']['data_1']['table'] = 'webform_submitted_data';
  $handler->display->display_options['filters']['data_1']['field'] = 'data';
  $handler->display->display_options['filters']['data_1']['relationship'] = 'data_1';
  $handler->display->display_options['filters']['data_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['data_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['data_1']['expose']['operator_id'] = 'data_1_op';
  $handler->display->display_options['filters']['data_1']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['data_1']['expose']['operator'] = 'data_1_op';
  $handler->display->display_options['filters']['data_1']['expose']['identifier'] = 'data_1';
  $handler->display->display_options['filters']['data_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1890');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['value']['value'] = '1890';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  /* Filter criterion: Webform submissions: Serial number */
  $handler->display->display_options['filters']['serial']['id'] = 'serial';
  $handler->display->display_options['filters']['serial']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['serial']['field'] = 'serial';
  $handler->display->display_options['filters']['serial']['group'] = 1;
  $handler->display->display_options['filters']['serial']['exposed'] = TRUE;
  $handler->display->display_options['filters']['serial']['expose']['operator_id'] = 'serial_op';
  $handler->display->display_options['filters']['serial']['expose']['label'] = 'Permit number';
  $handler->display->display_options['filters']['serial']['expose']['operator'] = 'serial_op';
  $handler->display->display_options['filters']['serial']['expose']['identifier'] = 'serial';
  $handler->display->display_options['filters']['serial']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Webform submission data: Data field */
  $handler->display->display_options['filters']['data']['id'] = 'data';
  $handler->display->display_options['filters']['data']['table'] = 'webform_submitted_data';
  $handler->display->display_options['filters']['data']['field'] = 'data';
  $handler->display->display_options['filters']['data']['relationship'] = 'data';
  $handler->display->display_options['filters']['data']['operator'] = 'contains';
  $handler->display->display_options['filters']['data']['exposed'] = TRUE;
  $handler->display->display_options['filters']['data']['expose']['operator_id'] = 'data_op';
  $handler->display->display_options['filters']['data']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['data']['expose']['operator'] = 'data_op';
  $handler->display->display_options['filters']['data']['expose']['identifier'] = 'data';
  $handler->display->display_options['filters']['data']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Webform submission data: Data field */
  $handler->display->display_options['filters']['data_1']['id'] = 'data_1';
  $handler->display->display_options['filters']['data_1']['table'] = 'webform_submitted_data';
  $handler->display->display_options['filters']['data_1']['field'] = 'data';
  $handler->display->display_options['filters']['data_1']['relationship'] = 'data_1';
  $handler->display->display_options['filters']['data_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['data_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['data_1']['expose']['operator_id'] = 'data_1_op';
  $handler->display->display_options['filters']['data_1']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['data_1']['expose']['operator'] = 'data_1_op';
  $handler->display->display_options['filters']['data_1']['expose']['identifier'] = 'data_1';
  $handler->display->display_options['filters']['data_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $export['scs_search_webform_results'] = $view;

  return $export;
}
