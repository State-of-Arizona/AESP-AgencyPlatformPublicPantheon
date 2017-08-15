<?php
/**
 * @file
 * Administration page specific functions.
 */

/**
 * Search404 administration settings.
 */
function search404_settings() {
  $form['search404_jump'] = array(
    '#type' => 'checkbox',
    '#title' => t('Jump directly to the search result when there is only one result'),
    '#description' => t('Works only with Core, Apache Solr, Lucene and Xapian searches. An HTTP status of 301 or 302 will be returned for this redirect.'),
    '#default_value' => variable_get('search404_jump', FALSE),
  );
  $form['search404_first'] = array(
    '#type' => 'checkbox',
    '#title' => t('Jump directly to the first search result even when there are multiple results'),
    '#description' => t('Works only with Core, Apache Solr, Lucene and Xapian searches. An HTTP status of 301 or 302 will be returned for this redirect.'),
    '#default_value' => variable_get('search404_first', FALSE),
  );
  $form['search404_first_on_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Jump directly to the first search result only on the listed paths.'),
    '#description' => t('Enter one path per line. The "*" character is a wildcard. Example paths are blog for the blog page and blog/* for every personal blog.'),
    '#default_value' => variable_get('search404_first_on_paths', ''),
  );
  $form['search404_do_google_cse'] = array(
    '#type' => 'checkbox',
    '#title' => t('Do a Google CSE Search instead of a Drupal Search when a 404 occurs'),
    '#description' => t('Requires Google CSE and Google CSE Search modules to be enabled.'),
    '#attributes' => module_exists('google_cse') ? array() : array('disabled' => 'disabled'),
    '#default_value' => variable_get('search404_do_google_cse', FALSE),
  );
  $form['search404_do_google_cse_adv'] = array(
    '#type' => 'checkbox',
    '#title' => t('Do a "Google CSE Advanced" search instead of a Drupal Search when a 404 occurs'),
    '#description' => t('Requires Google CSE Advanced Search Module to be Enabled.'),
    '#attributes' => module_exists('google_cse_adv') ? array() : array('disabled' => 'disabled'),
    '#default_value' => variable_get('search404_do_google_cse_adv', FALSE),
  );
  $form['search404_do_search_by_page'] = array(
    '#type' => 'checkbox',
    '#title' => t('Do a "Search by page" Search instead of a Drupal Search when a 404 occurs'),
    '#description' => t('Requires "Search by page" module to be enabled.'),
    '#attributes' => module_exists('search_by_page') ? array() : array('disabled' => 'disabled'),
    '#default_value' => variable_get('search404_do_search_by_page', FALSE),
  );
  // Custom search path implementation (for Search API integration #1076190)
  $form['search404_do_custom_search'] = array(
    '#type' => 'checkbox',
    '#title' => t('Do a "Search" with custom path instead of a Drupal Search when a 404 occurs'),
    '#description' => t('Redirect the user to a Custom search path to be entered below. Can be used to open a view with path parameter.'),
    '#default_value' => variable_get('search404_do_custom_search', FALSE),
  );
  $form['search404_custom_search_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom search path'),
    '#description' => t('The custom search path: example: myownsearch/@keys or myownsearch?txt_s=@keys. The token "@keys" will be replaced with the search keys from the URL.'),
    '#default_value' => variable_get('search404_custom_search_path', 'search/@keys'),
    '#states' => array(
      'visible' => array(
        ':input[name="search404_do_custom_search"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['search404_no_redirect'] = array(
    '#type' => 'checkbox',
    '#title' => t('Execute the callback directly instead of redirecting'),
    '#description' => t('This experimental feature notably allows to force 404 when using a custom search path.'),
    '#default_value' => variable_get('search404_no_redirect', FALSE),
  );
  // Added for having a 301 redirect instead of the standard 302
  // (offered by the drupal_goto).
  $form['search404_redirect_301'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use a 301 Redirect instead of 302 Redirect'),
    '#description' => t('This applies when the option to jump to first result is enabled and also for search404 results pages other than for Core, Apache Solr, Lucene and Xapian.'),
    '#default_value' => variable_get('search404_redirect_301', FALSE),
  );
  // Added for preventing automatic search for large sites.
  $form['search404_skip_auto_search'] = array(
    '#title' => t('Disable auto search'),
    '#description' => t('Disable automatically searching for the keywords when a page is not found and instead show the populated search form with the keywords. Useful for large sites to reduce server loads.'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('search404_skip_auto_search', FALSE),
  );
  // Disable the drupal error message when showing search results.
  $form['search404_disable_error_message'] = array(
    '#title' => t('Disable error message'),
    '#type' => 'checkbox',
    '#description' => t('Disable the Drupal error message when search results are shown on a 404 page.'),
    '#default_value' => variable_get('search404_disable_error_message', FALSE),
  );
  $form['search404_search_message'] = array(
    '#title' => t('Custom error message'),
    '#type' => 'textfield',
    '#description' => t('A custom error message that should be displayed when search results are shown on a 404 page, use "@keys" to insert the searched key value.'),
    '#default_value' => variable_get('search404_search_message', ''),
  );
  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['advanced']['search404_use_or'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use OR between keywords when searching'),
    '#default_value' => variable_get('search404_use_or', FALSE),
  );

  $form['advanced']['search404_use_search_engine'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use auto-detection of keywords from search engine referer'),
    '#description' => t('This feature will conduct a search based on the query string got from a search engine if the URL of the search result points to a 404 page in the current website. Currently supported search engines: Google, Yahoo, Altavista, Lycos, Bing and AOL.'),
    '#default_value' => variable_get('search404_use_search_engine', FALSE),
  );
  $form['advanced']['search404_ignore'] = array(
    '#type' => 'textarea',
    '#title' => t('Words to ignore'),
    '#description' => t('These words will be ignored from the search query. Separate words with a space, e.g.: "and or the".'),
    '#default_value' => variable_get('search404_ignore', t('and or the')),
  );
  $form['advanced']['search404_ignore_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Specific paths to ignore'),
    '#description' => t('These paths will be ignored. Site default "Page not found" page will be displayed. Enter one path per line. The "*" character is a wildcard. Example paths are blog for the blog page and blog/* for every personal blog.'),
    '#default_value' => variable_get('search404_ignore_paths', ''),
  );
  $form['advanced']['search404_ignore_extensions'] = array(
    '#type' => 'textfield',
    '#title' => t('Extensions to ignore'),
    '#description' => t('These extensions will be ignored from the search query, e.g.: http://www.example.com/invalid/page.php will only search for "invalid page". Separate extensions with a space, e.g.: "htm html php". Do not include leading dot.'),
    '#default_value' => variable_get('search404_ignore_extensions', 'htm html php'),
  );
  $form['advanced']['search404_ignore_query'] = array(
    '#type' => 'textfield',
    '#title' => t('Extensions to abort search'),
    '#description' => t('A search will not be performed for a query ending in these extensions. Separate extensions with a space, e.g.: "gif jpg jpeg bmp png". Do not include leading dot.'),
    '#default_value' => variable_get('search404_ignore_query', 'gif jpg jpeg bmp png'),
  );
  $form['advanced']['search404_regex'] = array(
    '#type' => 'textfield',
    '#title' => t('PCRE filter'),
    '#description' => t('This regular expression will be applied to filter all queries. The parts of the path that match the expression will be EXCLUDED from the search. You do NOT have to enclose the regex in forward slashes when defining the PCRE. e.g.: use "[foo]bar" instead of "/[foo]bar/". On how to use a PCRE Regex please refer <a href="http://php.net/pcre">PCRE pages in the PHP Manual</a>.'),
    '#default_value' => variable_get('search404_regex', ''),
  );
  // Show custom title for the 404 search results page.
  $form['advanced']['search404_page_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom page title'),
    '#description' => t('You can enter a value that will displayed at the title of the webpage e.g. "Page not found".'),
    '#default_value' => variable_get('search404_page_title', t('Page not found')),
  );
  // Show custom text below the search form for the 404 search results page.
  $form['advanced']['search404_page_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Custom page text'),
    '#default_value' => variable_get('search404_page_text', ''),
    '#description' => t('You can enter a custom text message that can be displayed at the top of the search results, HTML formatting can be used.'),
  );
  // Helps reset the site_404 variable to search404 in case the user changes
  // it manually.
  $form['site_404'] = array(
    '#type' => 'hidden',
    '#value' => 'search404',
  );
  // Tell the user about the site_404 issue.
  $form['search404_variable_message'] = array(
    '#type' => 'markup',
    '#prefix' => '<p>',
    '#suffix' => '</p>',
    '#value' => t('Saving this form will revert the 404 handling on the site to this module.'),
  );

  return system_settings_form($form);
}
