<?php
/**
 * @file
 * feature_views_pdf.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_views_pdf_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'azl_permit';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'AZL permit';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'AZL permit %1';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Webform submissions: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Field: Webform submissions: Serial number */
  $handler->display->display_options['fields']['serial']['id'] = 'serial';
  $handler->display->display_options['fields']['serial']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['serial']['field'] = 'serial';
  /* Contextual filter: Webform submissions: Sid */
  $handler->display->display_options['arguments']['sid']['id'] = 'sid';
  $handler->display->display_options['arguments']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['arguments']['sid']['field'] = 'sid';
  $handler->display->display_options['arguments']['sid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['sid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['sid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['sid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['sid']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: AZ Land Permit PDF Page */
  $handler = $view->new_display('pdf', 'AZ Land Permit PDF Page', 'az_land_permit_pdf');
  $handler->display->display_options['display_description'] = 'This View will help to generate the AZ Land Permit';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'pdf_unformatted';
  $handler->display->display_options['row_plugin'] = 'pdf_fields';
  $handler->display->display_options['row_options']['formats'] = array(
    'serial' => array(
      'position' => array(
        'object' => 'page',
        'corner' => 'bottom_right',
        'x' => '-42',
        'y' => '-46',
        'width' => '120',
        'height' => '15',
      ),
      'text' => array(
        'font_size' => '10',
        'font_family' => 'helvetica',
        'font_style' => NULL,
        'align' => NULL,
        'hyphenate' => 'auto',
        'color' => '111111',
      ),
      'render' => array(
        'is_html' => 1,
        'minimal_space' => '10',
      ),
    ),
    'value' => array(
      'position' => array(
        'object' => 'page',
        'corner' => 'bottom_right',
        'x' => '-186',
        'y' => '-35.5',
        'width' => '120',
        'height' => '15',
      ),
      'text' => array(
        'font_size' => '10',
        'font_family' => 'helvetica',
        'font_style' => NULL,
        'align' => NULL,
        'hyphenate' => 'auto',
        'color' => '111111',
      ),
      'render' => array(
        'is_html' => 1,
        'minimal_space' => '10',
      ),
    ),
    'value_3' => array(
      'position' => array(
        'object' => 'page',
        'corner' => 'bottom_right',
        'x' => '-186',
        'y' => '-24.5',
        'width' => '120',
        'height' => '10',
      ),
      'text' => array(
        'font_size' => '10',
        'font_family' => 'helvetica',
        'font_style' => NULL,
        'align' => NULL,
        'hyphenate' => 'auto',
        'color' => '111111',
      ),
      'render' => array(
        'is_html' => 1,
        'minimal_space' => '10',
      ),
    ),
    'value_4' => array(
      'position' => array(
        'object' => 'page',
        'corner' => 'bottom_right',
        'x' => '-43',
        'y' => '-40.5',
        'width' => '50',
        'height' => '11',
      ),
      'text' => array(
        'font_size' => '10',
        'font_family' => 'helvetica',
        'font_style' => NULL,
        'align' => NULL,
        'hyphenate' => 'auto',
        'color' => '111111',
      ),
      'render' => array(
        'is_html' => 1,
        'minimal_space' => '10',
      ),
    ),
    'value_7' => array(
      'position' => array(
        'object' => 'page',
        'corner' => 'bottom_right',
        'x' => '-186',
        'y' => '-10.5',
        'width' => '120',
        'height' => '15',
      ),
      'text' => array(
        'font_size' => '10',
        'font_family' => 'helvetica',
        'font_style' => NULL,
        'align' => NULL,
        'hyphenate' => 'auto',
        'color' => '111111',
      ),
      'render' => array(
        'is_html' => 1,
        'minimal_space' => '10',
      ),
    ),
    'serial_1' => array(
      'position' => array(
        'object' => 'last_position',
        'corner' => 'top_left',
        'x' => '108',
        'y' => '73',
        'width' => '50',
        'height' => '15',
      ),
      'text' => array(
        'font_size' => '15',
        'font_family' => 'helvetica',
        'font_style' => NULL,
        'align' => NULL,
        'hyphenate' => 'auto',
        'color' => '111111',
      ),
      'render' => array(
        'is_html' => 1,
        'minimal_space' => '15',
      ),
    ),
    'value_1' => array(
      'position' => array(
        'object' => 'last_position',
        'corner' => 'bottom_right',
        'x' => '84.5',
        'y' => '-4.5',
        'width' => '50',
        'height' => '15',
      ),
      'text' => array(
        'font_size' => '15',
        'font_family' => 'helvetica',
        'font_style' => NULL,
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '111111',
      ),
      'render' => array(
        'is_html' => 1,
        'minimal_space' => '15',
      ),
    ),
    'value_9' => array(
      'position' => array(
        'object' => 'field_serial',
        'corner' => 'top_right',
        'x' => '-263.5',
        'y' => '',
        'width' => '50',
        'height' => '11',
      ),
      'text' => array(
        'font_size' => '10',
        'font_family' => 'helvetica',
        'font_style' => NULL,
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '990000',
      ),
      'render' => array(
        'is_html' => 1,
        'minimal_space' => '20',
      ),
    ),
    'value_8' => array(
      'position' => array(
        'object' => 'last_position',
        'corner' => 'bottom_right',
        'x' => '79',
        'y' => '24.5',
        'width' => '75',
        'height' => '12',
      ),
      'text' => array(
        'font_size' => '10',
        'font_family' => 'helvetica',
        'font_style' => NULL,
        'align' => NULL,
        'hyphenate' => 'auto',
        'color' => '111111',
      ),
      'render' => array(
        'is_html' => 1,
        'minimal_space' => '20',
      ),
    ),
  );
  $handler->display->display_options['row_options']['leading_template'] = '0';
  $handler->display->display_options['row_options']['template'] = 'PermitAndParking.pdf';
  $handler->display->display_options['row_options']['succeed_template'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Webform submissions: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Webform submissions: Serial number */
  $handler->display->display_options['fields']['serial']['id'] = 'serial';
  $handler->display->display_options['fields']['serial']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['serial']['field'] = 'serial';
  $handler->display->display_options['fields']['serial']['label'] = '';
  $handler->display->display_options['fields']['serial']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['serial']['separator'] = '';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_2']['id'] = 'value_2';
  $handler->display->display_options['fields']['value_2']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_2']['field'] = 'value';
  $handler->display->display_options['fields']['value_2']['label'] = 'First Name';
  $handler->display->display_options['fields']['value_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['value_2']['custom_label'] = 'none';
  $handler->display->display_options['fields']['value_2']['webform_nid'] = '3';
  $handler->display->display_options['fields']['value_2']['webform_cid'] = '5';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['label'] = '';
  $handler->display->display_options['fields']['value']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['value']['alter']['text'] = '[value], [value_2]';
  $handler->display->display_options['fields']['value']['custom_label'] = 'none';
  $handler->display->display_options['fields']['value']['webform_nid'] = '3';
  $handler->display->display_options['fields']['value']['webform_cid'] = '2';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_3']['id'] = 'value_3';
  $handler->display->display_options['fields']['value_3']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_3']['field'] = 'value';
  $handler->display->display_options['fields']['value_3']['label'] = '';
  $handler->display->display_options['fields']['value_3']['webform_nid'] = '3';
  $handler->display->display_options['fields']['value_3']['webform_cid'] = '6';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_4']['id'] = 'value_4';
  $handler->display->display_options['fields']['value_4']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_4']['field'] = 'value';
  $handler->display->display_options['fields']['value_4']['label'] = '';
  $handler->display->display_options['fields']['value_4']['custom_label'] = 'none';
  $handler->display->display_options['fields']['value_4']['webform_nid'] = '3';
  $handler->display->display_options['fields']['value_4']['webform_cid'] = '4';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_5']['id'] = 'value_5';
  $handler->display->display_options['fields']['value_5']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_5']['field'] = 'value';
  $handler->display->display_options['fields']['value_5']['label'] = 'City';
  $handler->display->display_options['fields']['value_5']['exclude'] = TRUE;
  $handler->display->display_options['fields']['value_5']['custom_label'] = 'none';
  $handler->display->display_options['fields']['value_5']['webform_nid'] = '3';
  $handler->display->display_options['fields']['value_5']['webform_cid'] = '7';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_6']['id'] = 'value_6';
  $handler->display->display_options['fields']['value_6']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_6']['field'] = 'value';
  $handler->display->display_options['fields']['value_6']['label'] = '';
  $handler->display->display_options['fields']['value_6']['exclude'] = TRUE;
  $handler->display->display_options['fields']['value_6']['custom_label'] = 'none';
  $handler->display->display_options['fields']['value_6']['webform_nid'] = '3';
  $handler->display->display_options['fields']['value_6']['webform_cid'] = '14';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_7']['id'] = 'value_7';
  $handler->display->display_options['fields']['value_7']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_7']['field'] = 'value';
  $handler->display->display_options['fields']['value_7']['label'] = '';
  $handler->display->display_options['fields']['value_7']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['value_7']['alter']['text'] = '[value_5], [value_6] [value_7]';
  $handler->display->display_options['fields']['value_7']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_7']['webform_nid'] = '3';
  $handler->display->display_options['fields']['value_7']['webform_cid'] = '9';
  /* Field: Webform submissions: Serial number */
  $handler->display->display_options['fields']['serial_1']['id'] = 'serial_1';
  $handler->display->display_options['fields']['serial_1']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['serial_1']['field'] = 'serial';
  $handler->display->display_options['fields']['serial_1']['label'] = '';
  $handler->display->display_options['fields']['serial_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['serial_1']['separator'] = '';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['label'] = '';
  $handler->display->display_options['fields']['value_1']['webform_nid'] = '3';
  $handler->display->display_options['fields']['value_1']['webform_cid'] = '4';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_9']['id'] = 'value_9';
  $handler->display->display_options['fields']['value_9']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_9']['field'] = 'value';
  $handler->display->display_options['fields']['value_9']['label'] = '';
  $handler->display->display_options['fields']['value_9']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['value_9']['alter']['text'] = 'X   [value_9]';
  $handler->display->display_options['fields']['value_9']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_9']['webform_nid'] = '3';
  $handler->display->display_options['fields']['value_9']['webform_cid'] = '12';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_8']['id'] = 'value_8';
  $handler->display->display_options['fields']['value_8']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_8']['field'] = 'value';
  $handler->display->display_options['fields']['value_8']['label'] = '';
  $handler->display->display_options['fields']['value_8']['webform_nid'] = '3';
  $handler->display->display_options['fields']['value_8']['webform_cid'] = '13';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Webform submissions: Draft */
  $handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['value'] = array(
    0 => '0',
    1 => '1',
  );
  /* Filter criterion: Webform submissions: Sid */
  $handler->display->display_options['filters']['sid']['id'] = 'sid';
  $handler->display->display_options['filters']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['sid']['field'] = 'sid';
  $handler->display->display_options['filters']['sid']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'print/%';
  $handler->display->display_options['default_page_format'] = 'custom';
  $handler->display->display_options['default_page_format_custom'] = '[11.5]x[60]';
  $handler->display->display_options['margin_top'] = '30';
  $handler->display->display_options['leading_template'] = '0';
  $handler->display->display_options['template'] = '0';
  $handler->display->display_options['succeed_template'] = '0';
  $handler->display->display_options['default_font_style'] = array(
    'b' => 'b',
    'i' => 0,
    'u' => 0,
    'd' => 0,
    'o' => 0,
  );
  $handler->display->display_options['default_font_color'] = '333333';
  $export['azl_permit'] = $view;

  return $export;
}
