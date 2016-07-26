<?php

namespace Drupal\little_helpers\Locale;

class LanguageApi {
  public function currentLanguage() {
    return $GLOBALS['language']->language;
  }
  public function defaultLanguage() {
    return \language_default()->language;
  }
  public function redirect($path, $language) {
    \drupal_goto($path, array('language' => $language));
  }
  public function switchLinks($path) {
    $links = \language_negotiation_get_switch_links('language', $path);
    return $links ? $links->links : NULL;
  }
  /**
   * Check if the current logged-in user has access to a path.
   */
  public function checkAccess($path, $langCode) {
    // Extra handling for front-page.
    if (empty($path)) {
      if (module_exists('i18n_variable')) {
        $path = \i18n_variable_get('site_frontpage', $langCode, $path);
      } else {
        $path = \variable_get('site_frontpage', $path);
      }
    }
    return ($router_item = \menu_get_item($path)) && $router_item['access'];
  }
  /**
   * Give paths to all (or a subset) of the available translations
   */
  public function languageLinks($languages = NULL, $path = NULL) {
    if (!$languages) {
      $languages = \language_list();
    }
    if (!$path) {
      $path = \current_path();
    }
    $currentLanguage = $this->currentLanguage();
    $links = array();
    $switchLinks = $this->switchLinks($path);
    foreach ($languages as $code => $language) {
      if ($code == $currentLanguage)
        continue;

      if (isset($switchLinks[$code]) && isset($switchLinks[$code]['href']) && $this->checkAccess($switchLinks[$code]['href'], $code)) {
        $links[$code] = $switchLinks[$code];
      }
    }
    return $links;
  }
}
