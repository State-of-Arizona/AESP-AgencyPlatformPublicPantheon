<?php

namespace Drupal\little_helpers\Field;

class Instance {
  public $id = NULL;
  public $field;
  // @TODO: replace these with a bundle class
  public $bundle;
  
  public $settings = array();
  public $display = array('default' => array());
  public $widget = array();
  public $required = FALSE;
  public $label = '';
  public $description = '';
  public $deleted = 0;

  public function __construct($data) {
    foreach ($data as $k => $v) {
      $this->$k = $v;
    }
    if (isset($data['field_name']) && !isset($this->field)) {
      $this->field = Field::byName($data['field_name']);
    }
    if (isset($this->field)) {
      $this->setField($this->field);
    }
    if (empty($this->label)) {
      $this->label = $this->field->field_name;
    }
  }

  public static function load($field_name, $entity_type, $bundle) {
    $data = \field_read_instance($entity_type, $field_name, $bundle);
    $class = \get_called_class();
    return new $class($data);
  }

  public static function fromField(Field $field, BundleInterface $bundle = NULL, $data = array()) {
    $data = array('field' => $field, 'bundle' => $bundle) + $data;
    $class = \get_called_class();
    $instance = new $class($data);
    return $instance;
  }
  
  public static function fromNames($fieldname, $entity_type, $bundle, $data = array()) {
    return self::fromField(Field::byName($fieldname), new Bundle($entity_type, $bundle), $data);
  }
  
  /**
   * Set field and update default values accordingly.
   *
   * @see _field_write_instance().
   */
  public function setField(Field $field) {
    $this->field = $field;
    $this->settings += \field_info_instance_settings($field->type);
    $field_type = \field_info_field_types($field->type);
    if (!isset($this->widget['type'])) {
      $this->setWidget($field_type['default_widget']);
    }
    foreach ($this->display as $view_mode => &$settings) {
      if (!isset($settings['type'])) {
        $this->setFormatter($view_mode, isset($field_type['default_formatter']) ? $field_type['default_formatter'] : 'hidden');
      }
    }
  }
  
  /**
   * Set formatter type and update defaults accordingly.
   *
   * @see _field_write_instance().
   */
  public function setFormatter($view_mode, $formatter_name, $settings = array()) {
    $this->display[$view_mode] = $settings;
    $display = &$this->display[$view_mode];
    $display += array(
      'label' => 'above',
      'type' => $formatter_name,
      'settings' => array(),
    );
    if ($formatter_name != 'hidden') {
      $formatter_type = \field_info_formatter_types($display['type']);
      $display['module'] = $formatter_type['module'];
      $display['settings'] += \field_info_formatter_settings($display['type']);
    }
  }
  
  /**
   * Set widget type and update defaults accordingly.
   *
   * @see _field_write_instance().
   */
  public function setWidget($widget_type_name, $settings = array()) {
    $this->widget['type'] = $widget_type_name;
    $this->widget['settings'] = $settings;
    $widget_type = \field_info_widget_types($widget_type_name);
    $this->widget['module'] = $widget_type['module'];
    $this->widget['settings'] += \field_info_widget_settings($widget_type_name);
  }
  
  /**
   * Convert this object to an array suitable
   * for the Drupal Field-API.
   */
  public function export() {
    $data = (array) $this;
    if (isset($data['field'])) {
      unset($data['field']);
      $data['field_name'] = $this->field->field_name;
      $data['field_id'] = $this->field->id;
    }
    if (isset($data['bundle'])) {
      unset($data['bundle']);
      $data['bundle'] = $this->bundle->getBundleName();
      $data['entity_type'] = $this->bundle->getEntityType();
    }
    return $data;
  }
  
  /**
   * Save field instance to database.
   * 
   * @see \field_update_instance().
   * @see \field_create_instance().
   */
  public function save() {
    if (isset($this->id)) {
      \field_update_instance($this->export());
    } else {
      foreach (\field_create_instance($this->export()) as $k => $v) {
        $this->$k = $v;
      }
    }
    return $this;
  }

  /**
   * Delete an existing field instance.
   *
   * @see \field_delete_instance().
   */
  public function delete() {
    \field_delete_instance($this->export());
  }
}
