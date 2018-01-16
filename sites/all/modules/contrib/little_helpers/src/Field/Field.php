<?php

namespace Drupal\little_helpers\Field;

/**
 * OOP-wrapper for the data-structure used by field_*_field() functions.
 */
class Field {
  public $id = NULL;
  public $entity_types = array();
  public $field_name;
  public $type;
  public $module;
  public $active = 1;
  public $storage = array();
  public $locked = FALSE;
  public $cardinality = 1;
  public $translatable = FALSE;
  public $deleted = 0;
  public $settings = array();

  /**
   * Get a list of fields by their type.
   */
  public static function byType($type) {
    $fields = [];
    foreach (\field_read_fields(['type' => $type]) as $info) {
      $fields[$info['field_name']] = new static($info);
    }
    return $fields;
  }

  public static function byName($name) {
    if ($data = \field_read_field($name)) {
      return new static($data);
    }
    return FALSE;
  }

  public static function fromType($type, $name = NULL) {
    $class = \get_called_class();
    $new = new $class(array('field_name' => $name));
    $new->setType($type);
    return $new;
  }

  public function __construct($data) {
    foreach ($data as $k => $v) {
      $this->$k = $v;
    }
  }

  /**
   * Load default data for this field-type.
   *
   * @see \field_create_field()
   */
  public function setType($type) {
    $field_type = \field_info_field_types($type);
    $this->settings += \field_info_field_settings($type);
    $this->module = $field_type['module'];
    $this->type = $type;
  }

  /**
   * Save field configuration to database.
   *
   * @see \field_update_field()
   * @see \field_create_field()
   */
  public function save() {
    if (isset($this->id)) {
      \field_update_field((array) $this);
    }
    else {
      foreach (\field_create_field((array) $this) as $k => $v) {
        $this->$k = $v;
      }
    }
    return $this;
  }

  /**
   * Delete an existing field.
   *
   * @see \field_delete_field()
   */
  public function delete() {
    field_delete_field($this->field_name);
  }

  /**
   * Change the machine name of an existing field.
   *
   * @param $newName string
   *
   *   NOTE: This might need additional adjustments for contrib modules
   *   that store field_names (ie. views, context, cck_blocks).
   */
  public function rename($newName) {
    $o = $this->field_name;
    $n = $newName;
    db_query("UPDATE field_config SET field_name='$n' WHERE field_name='$o'");
    db_query("UPDATE field_config_instance SET field_name='$n' WHERE field_name='$o'");
    db_query("RENAME TABLE `field_data_$o` TO `field_data_$n`;");
    db_query("RENAME TABLE `field_revision_$o` TO `field_revision_$n`;");
    \module_load_install($this->module);
    $function = $this->module . '_field_schema';
    $schema = $function(array('type' => $this->type));
    foreach ($schema['columns'] as $column => $specs) {
      db_change_field("field_data_$n", "{$o}_{$column}", "{$n}_{$column}", $specs);
      db_change_field("field_revision_$n", "{$o}_{$column}", "{$n}_{$column}", $specs);
    }
    $this->field_name = $n;
  }

}
