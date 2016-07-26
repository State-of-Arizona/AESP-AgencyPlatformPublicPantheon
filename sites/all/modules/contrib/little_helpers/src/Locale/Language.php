<?php

namespace Drupal\little_helpers\Locale;

/**
 * Model object for the {languages} table
 */
class Language {
  /**
   * Language code.
   */
  public $language;
  /**
   * English name of the language.
   */
  public $name;
  /**
   * Name of the language in the language itself.
   */
  public $native;
  /**
   * LTR (0) or RTL (1)
   */
  public $direction = 0;
  public $enabled = 0;
  public $plurals = 0;
  public $formula = '';
  public $domain = '';
  public $prefix = '';
  public $weight = 0;
  public $javascript = '';
  public function __construct($data = array()) {
    foreach ($data as $k => $v) {
      $this->$k = $v;
    }
  }

  /**
   * Create new language object from predefined languages.
   *
   * @param string iso language code of the language to load.
   */
  public static function fromPredefined($langcode) {
    include_once DRUPAL_ROOT . '/includes/iso.inc';
    $predefined = _locale_get_predefined_list();
    $predefined = &$predefined[$langcode];
    $class = get_called_class();
    $instance = new $class(array('language' => $langcode));
    $instance->name      = $predefined[0];
    $instance->native    = isset($predefined[1]) ? $predefined[1] : $predefined[0];
    $instance->direction = isset($predefined[2]) ? $predefined[2] : LANGUAGE_LTR;
    return $instance;
  }

  /**
   * Load language from database.
   * 
   * @param string language code of the language to load from DB.
   * @return Language object if there is such a language in the database, else NULL.
   */
  public static function load($langcode) {
    $row = \db_select('languages', 'l')
      ->fields('l')
      ->condition('language', $langcode)
      ->execute()
      ->fetch();
    if ($row) {
      $class = get_called_class();
      return new $class($row);
    }
  }

  /**
   * Save language to the database and call hooks as needed.
   * @return $this for chaining
   */
  public function save() {
    $count_up = 0;
    $data = (array) $this;
    $update = FALSE;
    if (empty($this->native)) {
      $this->native = $this->name;
    }
    if ($old = self::load($this->language)) {
      unset($data['language']);
      db_update('languages')
        ->fields($data)
        ->condition('language', $this->language)
        ->execute();
      if ($this->enabled != $old->enabled) {
        $count_up = $this->enabled ? 1 : -1;
      }
      if (\language_default()->language == $this->language) {
        $this->setAsDefault();
      }
      $update = TRUE;
    } else {
      \db_insert('languages')
        ->fields($data)
        ->execute();
      $count_up = $this->enabled ? 1 : 0;
    }
    if ($count_up != 0) {
      \variable_set('language_count', \variable_get('language_count', 1) + $count_up);
    }
    if (!$update) {
      // Kill the static cache in language_list().
      \drupal_static_reset('language_list');
      // Force JavaScript translation file creation for the newly added language.
      \_locale_invalidate_js($this->language);
      \watchdog('locale', 'The %language language (%code) has been created.', array('%language' => $this->name, '%code' => $this->language));
      \module_invoke_all('multilingual_settings_changed');
    }
    return $this;
  }

  /**
   * Set this language as the default language
   * @return $this for chaining
   */
  public function setAsDefault() {
    \variable_set('language_default', (object)(array) $this);
    return $this;
  }
}
