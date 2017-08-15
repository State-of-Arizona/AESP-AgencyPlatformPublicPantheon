<?php
/**
 * @file
 * The search404 module search page related functions.
 */

/**
 * Get the keys that are to be used for the search.
 *
 * The search is based either
 * on the keywords from the URL or from the keys from the search
 * that resulted in the 404.
 */
function search404_get_keys() {
  $keys = '';
  // Try to get keywords from the search result (if it was one)
  // that resulted in the 404 if the config is set.
  if (variable_get('search404_use_search_engine', FALSE)) {
    $keys = search404_search_engine_query();
  }
  // If keys are not yet populated from a search engine referer
  // use keys from the path that resulted in the 404.
  // TODO: Figure out why $_GET['destination'] is not getting
  // populated. https://www.drupal.org/node/1445186
  if (!$keys && isset($_GET['destination'])) {
    $keys = $_GET['destination'];
    drupal_alter('search404_keys', $keys);
  }

  // Abort query on certain extensions, e.g: gif jpg jpeg png.
  $extensions = explode(' ', variable_get('search404_ignore_query', 'gif jpg jpeg bmp png'));
  $extensions = trim(implode('|', $extensions));
  if (!empty($extensions) && preg_match("/\.($extensions)$/i", $keys)) {
    return FALSE;
  }
  /* TODO - How does this work in D7
  // Remove the Language Prefix Appended to
  // Search String (http://drupal.org/node/560426)
  if (LANGUAGE_NEGOTIATION_PATH_DEFAULT && $language->language) {
  $keys = preg_replace("/^" . $language->language . "\//i", '', $keys);
  }*/
  $regex_filter = variable_get('search404_regex', '');
  if (!empty($regex_filter)) {
    $keys = preg_replace("/" . $regex_filter . "/i", '', $keys);
  }
  // Ignore certain extensions from query.
  $extensions = explode(' ', variable_get('search404_ignore_extensions', 'htm html php'));
  $extensions = trim(implode('|', $extensions));
  if (!empty($extensions)) {
    $keys = preg_replace("/\.($extensions)$/i", '', $keys);
  }

  $keys = preg_split('/[' . PREG_CLASS_UNICODE_WORD_BOUNDARY . ']+/u', $keys);

  // Ignore certain words (use case insensitive search).
  $keys = array_udiff($keys, explode(' ', variable_get('search404_ignore', t('and or the'))), 'strcasecmp');
  // Sanitize the keys.
  foreach ($keys as $a => $b) {
    $keys[$a] = check_plain($b);
  }
  $modifier = variable_get('search404_use_or', FALSE) ? ' OR ' : ' ';
  $keys = trim(implode($modifier, $keys));
  return $keys;
}

/**
 * Detect search from search engine.
 */
function search404_search_engine_query() {
  $engines = array(
    'altavista' => 'q',
    'aol' => 'query',
    'google' => 'q',
    'bing' => 'q',
    'lycos' => 'query',
    'yahoo' => 'p',
  );
  $parsed_url = !empty($_SERVER['HTTP_REFERER']) ? parse_url($_SERVER['HTTP_REFERER']) : FALSE;
  $remote_host = !empty($parsed_url['host']) ? $parsed_url['host'] : '';
  $query_string = !empty($parsed_url['query']) ? $parsed_url['query'] : '';
  $query = array();
  parse_str($query_string, $query);

  if (!$parsed_url === FALSE && !empty($remote_host) && !empty($query_string) && count($query)) {
    foreach ($engines as $host => $key) {
      if (strpos($remote_host, $host) !== FALSE && array_key_exists($key, $query)) {
        return trim($query[$key]);
      }
    }
  }

  return '';
}

/**
 * Displays an error message of page not found.
 *
 * @param string $keys
 *   Keywords.
 * @param bool $jump_to_result
 *   This param indicates wheather the search is jumped to a particlar search.
 */
function search404_error_message($keys, $jump_to_result = FALSE) {
  if ($jump_to_result) {
    $default_message = t('The page you requested does not exist.
    For your  convenience, a search was performed using the query @keys. Not quite what you were looking for? !other_results.',
      array(
        '@keys' => $keys,
        '!other_results' => l(
          t('Other results'),
          'search404',
          array(
            'query' => array(
              'no_jump' => 1,
              'destination' => $keys,
            ),
          )
        ),
      )
    );
  }
  else {
    $default_message = t('The page you requested does not exist. For your convenience, a search was performed using the query @keys.',
    array(
      '@keys' => $keys,
    ));
  }
  $show_message = variable_get('search404_search_message', '');
  if (!empty($show_message)) {
    $show_message = format_string($show_message, array('@keys' => $keys));
  }
  else {
    $show_message = $default_message;
  }
  drupal_set_message($show_message, 'error', FALSE);
}

/**
 * Main search function.
 *
 * Started with: http://drupal.org/node/12668
 * Updated to be more similar to search_view.
 */
function search404_page() {
  $output = '';
  drupal_set_title(variable_get('search404_page_title', t('Page not found')));
  $keys = search404_get_keys();

  // If the current path is set as one of the ignore path, then do not get into
  // the complex search functions.
  $paths_to_ignore = variable_get('search404_ignore_paths', '');

  if (!empty($paths_to_ignore)) {
    $path = str_replace(' ', '/', $keys);
    $page_match = drupal_match_path($path, $paths_to_ignore);

    // If the page matches to any of the listed paths to ignore, then return.
    if ($page_match) {
      return;
    }
  }
  if (module_exists('search') && (user_access('search content') || user_access('search by page'))) {
    $results = array();

    // Get and use the default search engine for the site.
    $default_search = search_get_default_module_info();
    $type_search = $default_search['module'];

    // Get throttle status.
    $throttle = module_invoke('throttle', 'status');
    // If search keys are present and site is not throttled and
    // automatic searching is not disabled.
    if ($keys && !$throttle && !variable_get('search404_skip_auto_search', FALSE)) {
      if (module_exists('search_by_page') && variable_get('search404_do_search_by_page', FALSE)) {
        search404_error_message($keys);
        search404_goto('search_pages/' . $keys);
      }
      elseif (module_exists('google_cse') && user_access('search Google CSE') && variable_get('search404_do_google_cse', FALSE)) {
        search404_error_message($keys);
        search404_goto('search/google/' . $keys);
      }
      elseif (module_exists('google_cse_adv') && user_access('search content') && variable_get('search404_do_google_cse_adv', FALSE)) {
        search404_error_message($keys);
        search404_goto('search/google_cse_adv/' . $keys);
      }
      else {
        // Called for apache solr, lucene, xapian and core search.
        $results = search_data($keys, $type_search);
        // Apache Solr puts the results in $results['search_results'].
        if (isset($results['search_results'])) {
          $results = $results['search_results'];
        }
        // Some modules like ds_search (#1253426) returns its own results format
        // and may not have $results['#results'].
        if (isset($results['#results'])) {
          // Check if there are any specific paths are set where only we need to
          // jump to the first result.
          $paths = variable_get('search404_first_on_paths', '');
          $path_match = TRUE;

          // Check if the current path exists in the set paths list.
          if (!empty($paths)) {
            $path = str_replace(' ', '/', $keys);
            $path_match = drupal_match_path($path, $paths);
          }

          // Jump to first result if there are results and
          // if there is only one result and if jump to first is selected or
          // if there are more than one results and force jump to first is
          // selected and current path is set to jump to the first result
          // and if no_jump is not set.
          if (is_array($results['#results']) &&
            (
              (count($results['#results']) == 1 && variable_get('search404_jump', FALSE))
              || (count($results['#results']) >= 1 && variable_get('search404_first', FALSE) && $path_match)
            ) &&
            !isset($_GET['no_jump'])
          ) {
            search404_error_message($keys, TRUE);
            $result_path = drupal_get_path_alias('node/' . $results['#results'][0]['node']->nid);
            search404_goto($result_path);
          }
          else {
            search404_error_message($keys);
            if (isset($results['#results']) && count($results['#results']) >= 1) {
              drupal_add_css(drupal_get_path('module', 'search') . '/search.css');
            }
            else {
              $results['#markup'] = search_help('search#noresults', drupal_help_arg());
            }
          }
        }
        else {
          // Normal $results['#results'] doesn't exist, we will not redirect
          // and just hope the strange search module knows
          // how to render its output.
          search404_error_message($keys);
        }
      }
    }
    // Construct the search form.
    if ($type_search == 'apachesolr_search') {
      // Get Apachesolr search form.
      module_load_include('inc', 'apachesolr_search', 'apachesolr_search.pages');
      $search_page = apachesolr_search_page_load(apachesolr_search_default_search_page());
      $form = drupal_get_form('apachesolr_search_custom_page_search_form', $search_page, $keys);

      // Set the action to point to the search page, otherwise form will submit
      // to current 404 page.
      // Newer versions of apache_solr is returning search_page as an array
      // while earlier versions return an object. (#1923954)
      if (is_array($search_page)) {
        $search_path = $search_page['search_path'];
      }
      else {
        $search_page->search_path;
        $search_path = $search_page->search_path;
      }
      $form['#action'] = url($search_path);
      // Remove the form value since it will include
      // the destination directive and force a search submit button loop
      // If not reset properly, the resulting search form will have a
      // destination pointing back to the broken page that triggered the 404.
      $form['basic']['get']['#value'] = json_encode(array());
    }
    else {
      // Get the default search form.
      $form = drupal_get_form('search_form', NULL, $keys, $type_search);
    }
    $output = render($form) . render($results);
    // Add custom text before the search form and
    // results if custom text has been set.
    $search404_page_text = filter_xss_admin(variable_get('search404_page_text', ''));
    if (!empty($search404_page_text)) {
      $output = '<div id="search404-page-text">' . $search404_page_text . '</div>' . $output;
    }
  }
  if (variable_get('search404_do_custom_search', FALSE) && !variable_get('search404_skip_auto_search', FALSE)) {
    $custom_search_path = variable_get('search404_custom_search_path', 'search/@keys');
    // Remove query parameters before checking whether the search path exists or
    // the user has access rights.
    $custom_search_path_no_query = preg_replace('/\?.*/', '', $custom_search_path);
    if (drupal_valid_path($custom_search_path_no_query)) {
      search404_error_message($keys);
      $custom_search_path = str_replace('@keys', $keys, $custom_search_path);
      search404_goto($custom_search_path);
    }
    else {
      // Get the search results.
      $results = search404_results($keys, $type_search);
    }
  }

  // If the user does not have search permissions $output would be empty.
  if ($output == '') {
    $output = t('The page you requested does not exist.');
  }
  return $output;
}

/**
 * Get the results for a search.
 *
 * @param array $keys
 *   The search keys.
 * @param string $type_search
 *   The search module to search.
 *
 * @return array $results
 *   Renderable array of search results.
 */
function search404_results($keys, $type_search) {
  // Called for apache solr, lucene, xapian and core search.
  $results = search_data($keys, $type_search);
  // Apache Solr puts the results in $results['search_results'].
  if (isset($results['search_results'])) {
    $results = $results['search_results'];
  }
  // Some modules like ds_search (#1253426) returns its own results format
  // and may not have $results['#results'].
  if (isset($results['#results'])) {
    // Jump to first result if there are results and
    // if there is only one result and if jump to first is selected or
    // if there are more than one results and force jump to first is selected.
    if (is_array($results['#results']) &&
      (
        (count($results['#results']) == 1 && variable_get('search404_jump', FALSE))
        || (count($results['#results']) >= 1 && variable_get('search404_first', FALSE))
      )
    ) {
      if (!variable_get('search404_disable_error_message', FALSE)) {
        search404_error_message($keys);
      }
      if (isset($results['#results'][0]['node']->path)) {
        $result_path = $results['#results'][0]['node']->path;
      }
      else {
        $result_path = 'node/' . $results['#results'][0]['node']->nid;
      }
      search404_goto($result_path);
    }
    else {
      if (!variable_get('search404_disable_error_message', FALSE)) {
        search404_error_message($keys);
      }
      if (isset($results['#results']) && count($results['#results']) >= 1) {
        drupal_add_css(drupal_get_path('module', 'search') . '/search.css', 'module', 'all', FALSE);
      }
      else {
        $results = search_help('search#noresults', drupal_help_arg());
      }
    }
  }
  else {
    // Normal $results['#results'] doesn't exist, we will not redirect
    // and just hope the strange search module knows how to render its output.
    search404_error_message($keys);
  }
  return $results;
}

/**
 * Search404 drupal_goto helper function.
 */
function search404_goto($path = '') {
  // Overwrite $_GET['destination'] because it is set by drupal_not_found().
  $_GET['destination'] = $path;

  if (variable_get('search404_no_redirect', FALSE)) {
    $options = drupal_parse_url($path);
    $_GET += $options['query'];
    menu_set_active_item($options['path']);
    menu_execute_active_handler();
    exit();
  }

  // Set 301 redirect if so specified in settings else do default 302 redirect.
  if (variable_get('search404_redirect_301', FALSE)) {
    $http_status = 301;
  }
  else {
    $http_status = 302;
    if (variable_get('search404_do_custom_search')) {
      $meta_search404_noindex = array(
        '#tag' => 'meta',
        '#attributes' => array(
          'name' => 'robots',
          'content' => 'noindex',
        ),
      );
      drupal_add_html_head($meta_search404_noindex, 'meta_search404_noindex');
    }
  }
  drupal_goto($path, array(), $http_status);
}
