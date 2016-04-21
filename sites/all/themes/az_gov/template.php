<?php

function az_gov_preprocess_node(&$vars) {
  if (isset($vars['field_basic_slideshow_style'])) {
    if (!empty($vars['field_basic_slideshow_style'][LANGUAGE_NONE][0]['value'])) {
      $style = $vars['field_basic_slideshow_style'][LANGUAGE_NONE][0]['value'];
      $vars['content']['field_basic_slideshow_images'][0]['#js_variables']['fx'] = $vars['field_basic_slideshow_effect'][LANGUAGE_NONE][0]['value'];
    }
    else {
      $style = 'basic-slideshow-style-1';
    }
    $vars['classes_array'][] = $style;
  }
}

/**
 * Establishes variables to be used in page template
 */
function az_gov_preprocess_page(&$vars) {
  //footer contact section variables
  $vars['footer_settings'] = array(
    'show branding' => theme_get_setting('display_footer_branding'),
    'show contact' => theme_get_setting('display_footer_contact'),
    'title' => theme_get_setting('footer_title'),
    'title link' => theme_get_setting('footer_title_link'),
    'agency' => theme_get_setting('footer_agency_title'),
    'address 1' => theme_get_setting('footer_address_1'),
    'address 2' => theme_get_setting('footer_address_2'),
    'phone' => theme_get_setting('footer_phone'),
    'fax' => theme_get_setting('footer_fax'),
    'map link' => theme_get_setting('footer_map_link'),
  );
  if (theme_get_setting('footer_map_image')) {
    $vars['footer_settings']['map'] = file_create_url(file_load(theme_get_setting('footer_map_image'))->uri);
  }

  //creates a variable that is used for alt tags on image regardless if the 'Show Site Name' setting is unchecked.
  $vars['persistent_site_name'] = variable_get('site_name', '');

  //checks for existence of the sidebars and will create variable to wrap the main content region
  if ($vars['page']['sidebar_first'] && !$vars['page']['sidebar_second']) {
    $vars['content_class'] = 'col-sm-9 col-md-10';
  }
  elseif (!$vars['page']['sidebar_first'] && $vars['page']['sidebar_second']) {
    $vars['content_class'] = 'col-sm-8 col-md-8';
  }
  elseif ($vars['page']['sidebar_first'] && $vars['page']['sidebar_second']) {
    $vars['content_class'] = 'col-sm-5 col-md-6';
  }
  else {
    $vars['content_class'] = '';
  }

  //checks for the number of regions in the preface area being used and will wrap them in an appropriate class
  $num_preface = 0;
  if ($vars['page']['preface_first']) {
    $num_preface += 1;
  }
  if ($vars['page']['preface_second']) {
    $num_preface += 1;
  }
  if ($vars['page']['preface_third']) {
    $num_preface += 1;
  }
  switch ($num_preface) {
    case 2:
      $vars['preface_first'] = 'col-sm-6';
      $vars['preface_second'] = 'col-sm-6';
      $vars['preface_third'] = 'col-sm-6';
      break;
    case 3:
      $vars['preface_first'] = 'col-md-4';
      $vars['preface_second'] = 'col-sm-6 col-md-4';
      $vars['preface_third'] = 'col-sm-6 col-md-4';
      break;
    default:
      $vars['preface_first'] = '';
      $vars['preface_second'] = '';
      $vars['preface_third'] = '';
  }

  //checks for the number of regions in the postscript area being used and will wrap them in an appropriate class
  $num_postscripts = 0;
  if ($vars['page']['postscript_first']) {
    $num_postscripts += 1;
  }
  if ($vars['page']['postscript_second']) {
    $num_postscripts += 1;
  }
  if ($vars['page']['postscript_third']) {
    $num_postscripts += 1;
  }
  if ($vars['page']['postscript_fourth']) {
    $num_postscripts += 1;
  }

  switch ($num_postscripts) {
    case 2:
      $vars['postscript'] = 'col-sm-6';
      $vars['postscript_num'] = 'two-postscript';
      break;
    case 3:
      $vars['postscript'] = 'col-sm-4';
      $vars['postscript_num'] = 'three-postscript';
      break;
    case 4:
      $vars['postscript'] = 'col-sm-6 col-md-3';
      $vars['postscript_num'] = 'four-postscript';
      break;
    default:
      $vars['postscript'] = '';
      $vars['postscript_num'] = 'single-postscript';
  }
}

/**
 * color module support
 */
function az_gov_process_page(&$vars) {
  if (module_exists('color')) {
    _color_page_alter($vars);
  }
}

/**
 * IE Header and Background
 */
function az_gov_preprocess_html(&$vars) {
  $meta_ie_render_engine = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'content' => 'IE=edge,chrome=1',
      'http-equiv' => 'X-UA-Compatible',
    ),
    '#weight' => '-99999',
  );

  drupal_add_html_head($meta_ie_render_engine, 'meta_ie_render_engine');

  //if a background image is uploaded, it will apply the css needed
  if ($image = theme_get_setting('main_background')) {
    $background = image_load(file_load($image)->uri);
    $bg_url = file_create_url($background->source);
    $bg_width = $background->info['width'];

    $bg_stretch = '
    @media(min-width: 768px) {
        body {
          background: url("' . $bg_url . '") no-repeat center center fixed !important;
          -webkit-background-size: cover !important;
          -moz-background-size: cover !important;
          -o-background-size: cover !important;
          background-size: cover !important;
        }
      }';

    $bg_repeat = '
    @media(min-width: 768px) {
        body {
          background: url("' . $bg_url . '") fixed !important;
          background-size: contain;
        }
      }';

    //if the image is under 300px wide, it will  be repeated, if not, it will stretch
    if ($bg_width > 300) {
      drupal_add_css($bg_stretch, 'inline');
    }
    else {
      drupal_add_css($bg_repeat, 'inline');
    }
  }
}

/**
 * color module support
 */
function az_gov_process_html(&$vars) {
  if (module_exists('color')) {
    _color_html_alter($vars);
  }
}

/**
 * Adds class to the views to indicate the number of results
 */
function az_gov_preprocess_views_view(&$vars) {
  //applies a class to the view indicating how many results.
  $total_results = 'total-results-' . count($vars['view']->result);
  $vars['classes_array'][] = $total_results;
}

/**
 * Add classes to the menu <li> and <a> ta
 */
function az_gov_menu_link($vars) {
  //gs
  $menu_class = str_replace(' ', '-', strtolower($vars['element']['#original_link']['link_title']));
  $vars['element']['#attributes']['class'][] = 'menu-li-' . $menu_class;
  if (isset($variables['element']['#localized_options'])) {
    $vars['element']['#localized_options']['attributes']['class'][] = 'menu-' . $menu_class;
  }
  return theme_menu_link($vars);
}

/**
 * Theme the calendar title
 *
 * Copied and modified from date_views module theme.inc
 */
function az_gov_date_nav_title($params) {
  $granularity = $params['granularity'];
  $view = $params['view'];
  $date_info = $view->date_info;
  $link = !empty($params['link']) ? $params['link'] : FALSE;
  $format = !empty($params['format']) ? $params['format'] : NULL;
  $format_with_year = variable_get('date_views_' . $granularity . 'format_with_year', 'l, F j, Y');
  $format_without_year = variable_get('date_views_' . $granularity . 'format_without_year', 'l, F j');
  switch ($granularity) {
    case 'year':
      $title = $date_info->year;
      $date_arg = $date_info->year;
      break;
    case 'month':
      //customized format for month display
      //$format = !empty($format) ? $format : (empty($date_info->mini) ? $format_with_year : $format_without_year);
      $format = 'F Y';

      $title = date_format_date($date_info->min_date, 'custom', $format);
      $date_arg = $date_info->year . '-' . date_pad($date_info->month);
      break;
    case 'day':
      $format = !empty($format) ? $format : (empty($date_info->mini) ? $format_with_year : $format_without_year);
      $title = date_format_date($date_info->min_date, 'custom', $format);
      $date_arg = $date_info->year . '-' . date_pad($date_info->month) . '-' . date_pad($date_info->day);
      break;
    case 'week':
      $format = !empty($format) ? $format : (empty($date_info->mini) ? $format_with_year : $format_without_year);
      $title = t('Week of @date', array('@date' => date_format_date($date_info->min_date, 'custom', $format)));
      $date_arg = $date_info->year . '-W' . date_pad($date_info->week);
      break;
  }
  if (!empty($date_info->mini) || $link) {
    // Month navigation titles are used as links in the mini view.
    $attributes = array('title' => t('View full page month'));
    $url = date_pager_url($view, $granularity, $date_arg, TRUE);
    return l($title, $url, array('attributes' => $attributes));
  }
  else {
    return $title;
  }
}

function az_gov_preprocess_region(&$vars) {
  switch ($vars['region']) {
    case 'preface_first':
    case 'preface_second':
    case 'preface_third':
    case 'postscript_first':
    case 'postscript_second':
    case 'postscript_third':
    case 'postscript_fourth':
      $keys = array_keys($vars['elements']);
      $mbp = FALSE;
      foreach ($keys as $key) {
        if (strpos($key, 'mbp_defaults') !== FALSE) {
          $mbp = TRUE;
        }
      }
      $vars['classes_array'][] = $mbp ? 'menu-block-placement-exists' : 'menu-block-placement-doesnt-exist';
      break;
  }
}

function az_gov_theme() {
  $items = array();
  // create custom user-login.tpl.php
  $items['user_login'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'az_gov') . '/templates',
    'template' => 'user-login',
    'preprocess functions' => array(
      'az_gov_preprocess_user_login'
    ),
  );
  return $items;
}