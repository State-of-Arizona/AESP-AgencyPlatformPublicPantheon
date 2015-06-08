<?php
//comm theme
/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 *
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

function hook_block_view_alter(&$data, $block) {
  if ($block -> module == 'search-form') {
    $data['content'] = array();
  }
}

/**
 * Unset the Alpha/Omega themes from the appearance page
 * We don't want anyone enabling them directly
 *
 * Needs moved to module since theme isn't used for admin, but keeping here for reference
 */
function open_omega_system_themes_page_alter(&$theme_groups) {
  $hidden = array(
    'alpha',
    'omega',
  );
  foreach ($theme_groups as $state => &$group) {
    if ($state == 'disabled') {
      foreach ($theme_groups[$state] as $id => &$theme) {
        if (in_array($theme, $hidden)) {
          unset($theme_groups[$state][$id]);
        }
      }
    }
  }
}

function comm_preprocess_block(&$vars) {
  $vars['sticky_logo'] = theme_get_setting('sticky_nav_path');
  $vars['use_sticky_logo'] = theme_get_setting('use_sticky_nav');
  $vars['sticky_nav_mobile'] = theme_get_setting('sticky_nav_mobile');
  $vars['site_name'] = variable_get('site_name');
}

function comm_preprocess_region(&$vars) {
  global $language;

  switch($vars['region']) {

    // User Flyout Region
    case'user_flyout':
      $vars['flyout_text'] = theme_get_setting('flyout_nav_text');
      $vars['use_flyout_text'] = theme_get_setting('use_flyout_text');

      //Contact Us Block
      $vars['display_flyout_contact'] = theme_get_setting('display_footer_contact');
      $vars['flyout_contact_title'] = theme_get_setting('footer_contact_us_title');
      $vars['flyout_contact_comm_title'] = theme_get_setting('footer_contact_us_comm_title');
      $vars['flyout_contact_address_1'] = theme_get_setting('footer_contact_us_address_1');
      $vars['flyout_contact_address_2'] = theme_get_setting('footer_contact_us_address_2');
      $vars['flyout_contact_phone'] = theme_get_setting('footer_contact_us_phone');
      $vars['flyout_contact_fax'] = theme_get_setting('footer_contact_us_fax');
      $vars['flyout_contact_map_link'] = theme_get_setting('footer_contact_us_map_link');
      $vars['flyout_contact_map_image'] = theme_get_setting('footer_contact_us_map_image');
      $vars['flyout_contact_title_link'] = theme_get_setting('footer_contact_us_title_link');
      $vars['flyout_contact_map_path'] = theme_get_setting('footer_contact_us_map_path');

      break;

    // menu region
    case 'menu':
      $footer_menu_cache = cache_get("footer_menu_data:" . $language -> language);
      if ($footer_menu_cache) {
        $footer_menu = $footer_menu_cache -> data;
      }
      else {
        $footer_menu = menu_tree_output(_comm_menu_build_tree('main-menu', array('max_depth' => 2)));
        cache_set("footer_menu_data:" . $language -> language, $footer_menu);
      }
      //set the active trail
      $active_trail = menu_get_active_trail();
      foreach ($active_trail as $trail) {
        if (isset($trail['mlid']) && isset($footer_menu[$trail['mlid']])) {
          $footer_menu[$trail['mlid']]['#attributes']['class'][] = 'active-trail';
        }
      }
      $vars['dropdown_menu'] = $footer_menu;
      break;
    // default footer content
    case 'footer_first':
      $footer_menu_cache = cache_get("footer_menu_data:" . $language -> language);
      if ($footer_menu_cache) {
        $footer_menu = $footer_menu_cache -> data;
      }
      else {
        $footer_menu = menu_tree_output(_comm_menu_build_tree('main-menu', array('max_depth' => 2)));
        cache_set("footer_menu_data", $footer_menu);
      }
      //set the active trail
      $active_trail = menu_get_active_trail();
      foreach ($active_trail as $trail) {
        if (isset($trail['mlid']) && isset($footer_menu[$trail['mlid']])) {
          $footer_menu[$trail['mlid']]['#attributes']['class'][] = 'active-trail';
        }
      }
      $vars['footer_menu'] = $footer_menu;

      $vars['site_name'] = $site_name = variable_get('site_name');
      $vars['footer_logo'] = l(theme('image', array(
        'path' => drupal_get_path('theme', 'comm') . "/logo-sm.png",
        'alt' => "$site_name logo"
      )), '', array(
        "html" => TRUE,
        'attributes' => array('class' => 'logo')
      ));

      /*
       //Branding
       $vars['display_footer_branding'] = theme_get_setting('display_footer_branding');

       //Contact Us Block
       $vars['display_footer_contact'] = theme_get_setting('display_footer_contact');
       $vars['footer_contact_us_title'] = theme_get_setting('footer_contact_us_title');
       $vars['footer_contact_us_comm1_title'] = theme_get_setting('footer_contact_us_comm1_title');
       $vars['footer_contact_us_address_1'] = theme_get_setting('footer_contact_us_address_1');
       $vars['footer_contact_us_address_2'] = theme_get_setting('footer_contact_us_address_2');
       $vars['footer_contact_us_phone'] = theme_get_setting('footer_contact_us_phone');
       $vars['footer_contact_us_fax'] = theme_get_setting('footer_contact_us_fax');
       $vars['footer_contact_us_map_link'] = theme_get_setting('footer_contact_us_map_link');
       $vars['footer_contact_us_map_image'] = theme_get_setting('footer_contact_us_map_image');
       $vars['footer_contact_us_title_link'] = theme_get_setting('footer_contact_us_title_link');
       $vars['footer_contact_us_map_path'] = theme_get_setting('footer_contact_us_map_path');*/

      if (function_exists('defaultcontent_get_node') && ($node = defaultcontent_get_node("email_update"))) {
        $node = node_view($node);
        $vars['subscribe_form'] = $node['webform'];
      }
      //krumo($vars['footer_menu']);
      break;
  }

}

/* Fix the horrid menu_tree theme function to clearfix since most LI's are floated */
function comm_menu_tree($variables) {
  //if ($variables['attributes']['id'] == 'main-menu-links') {
  //  drupal_set_message( '<pre>' . print_r($variables['tree'], TRUE) . '</pre>', 'status');
  //}
  return '<ul class="menu clearfix">' . $variables['tree'] . '</ul>';
}

function comm_menu_link($variables) {
  //Add classes to the menu <li> and <a> tags
  $menu_class = preg_replace("/[\s_]/", "-", preg_replace("/[\s-]+/", " ", preg_replace("/[^a-z0-9_\s-]/", "", strtolower($variables['element']['#original_link']['link_title']))));

  //<li>
  $variables['element']['#attributes']['class'][] = 'menu-li-' . $menu_class;
  //<a>

  if (isset($variables['element']['#localized_options'])) {
    $variables['element']['#localized_options']['attributes']['class'][] = 'menu-' . $menu_class;
  }
  return theme_menu_link($variables);
}

/* Add the 'clearfix' class to all unformatted views rows */
function comm_preprocess_views_view_unformatted(&$vars) {
  foreach ($vars['classes'] as &$rowclasses) {
    $rowclasses[] = 'clearfix';
  }
  foreach ($vars['classes_array'] as &$rowclasses) {
    $rowclasses .= ' clearfix';
  }
  foreach ($vars['attributes_array']['class'] as &$rowclasses) {
    $rowclasses .= ' clearfix';
  }
}

function _comm_menu_build_tree($menu_name, $parameters = array()) {
  $tree = menu_build_tree($menu_name, $parameters);
  if (function_exists('i18n_menu_localize_tree')) {
    $tree = i18n_menu_localize_tree($tree);
  }

  return $tree;
}

function comm_preprocess_html(&$page) {
  $meta_ie_render_engine = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'content' =>  'IE=edge,chrome=1',
      'http-equiv' => 'X-UA-Compatible',
    ),
    '#weight' => '-99999',
  );

  drupal_add_html_head($meta_ie_render_engine, 'meta_ie_render_engine');


  //Change the name of the home page
  if (drupal_is_front_page()) {
    $page['head_title'] = variable_get('site_name');
  }

  if (theme_get_setting('default_background')) {
    //drupal_add_css
    //add some default css?  or just rely on the css files to handle it?

    drupal_add_css('body { 
				background: url("/' . drupal_get_path('theme', 'comm') . "/img/bg-image-desert.jpg" . '") no-repeat center center fixed !important; 
				-webkit-background-size: cover !important; 
				-moz-background-size: cover !important; 
				-o-background-size: cover !important; 
				background-size: cover !important;
				}', 'inline');

  }
  else {
    if ($bg_url = theme_get_setting('background_path')) {
      if (substr($bg_url, 0, 4) != 'http') {
        if (isset($_SERVER['HTTPS']) && ($_SERVER['HTTPS'] == 'on' || $_SERVER['HTTPS'] == 1) || isset($_SERVER['HTTP_X_FORWARDED_PROTO']) && $_SERVER['HTTP_X_FORWARDED_PROTO'] == 'https') {
          $protocol = 'https://';
        }
        else {
          $protocol = 'http://';
        }
        $bg_url = $protocol . $_SERVER['HTTP_HOST'] . $bg_url;
      }
      $background_size = getimagesize($bg_url);
      if ($background_size[0] > 300) {
        drupal_add_css('body { 
					background: url("' . $bg_url . '") no-repeat center center fixed !important; 
					-webkit-background-size: cover !important; 
					-moz-background-size: cover !important; 
					-o-background-size: cover !important; 
					background-size: cover !important;
					}', 'inline');
      }
      else {
        drupal_add_css('body {background: url("' . $bg_url . '") fixed !important;
				background-size:contain;
					}', 'inline');
      }

    }
  }

}

function comm_page_build(&$page) {
  //  echo "DEBUG: template.php->comm_page_build()";
}

function comm_preprocess_node(&$page) {
  $page['footer_logo'] = theme_get_setting('logo');
  $page['site_name'] = variable_get('site_name');
  $page['site_slogan'] = variable_get('site_slogan');
  //$page['site_name_hidden'] = theme_get_setting('site_name_hidden');
  //$page['site_slogan_hidden'] = theme_get_setting('site_slogan_hidden');
}

function comm_process_html(&$page) {
  drupal_add_http_header('X-UA-Compatible', 'IE=edge,chrome=1');

  //color module support
  if (module_exists('color')) {
    _color_html_alter($page);
  }
}

function comm_process_page(&$page) {
  //color module support
  if (module_exists('color')) {
    _color_page_alter($page);
  }

}

function comm_preprocess_page(&$vars) {
  /*
   // Sticky Navigation
   $vars['sticky_logo'] = theme_get_setting('sticky_nav_path');
   $vars['use_sticky_logo'] = theme_get_setting('use_sticky_nav');
   $vars['sticky_nav_mobile'] = theme_get_setting('sticky_nav_mobile');

   // Flyout Nav
   $vars['flyout_text'] = theme_get_setting('flyout_nav_text');
   $vars['use_flyout_text'] = theme_get_setting('use_flyout_text');
   //dpm($vars);*/
}

drupal_add_js(drupal_get_path('theme', 'comm') . '/js/agency.js');
drupal_add_js(drupal_get_path('theme', 'comm') . '/js/menu.js');


/**
 * Theme the calendar title
 *
 * Copied and modified from date_views module theme.inc
 */
function comm_date_nav_title($params) {
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