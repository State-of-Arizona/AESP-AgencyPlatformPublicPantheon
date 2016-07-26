<?php

namespace Drupal\little_helpers\DB;

abstract class Model {
  protected static $table = '';
  protected static $key = array();
  protected static $values = array();
  protected static $serial = TRUE;
  protected static $serialize = array();

  protected $new = FALSE;

  public function __construct($data = array(), $new = TRUE) {
    foreach ($data as $k => $v) {
      $this->$k = (is_string($v) && !empty(static::$serialize[$k])) ? unserialize($v) : $v;
    }
    $this->new = $new;
  }

  public function isNew() {
    if (!$this->new) {
      return FALSE;
    }
    if (static::$serial) {
      foreach (static::$key as $key) {
        if (isset($this->{$key})) {
          return FALSE;
        }
      }
    }
    return TRUE;
  }

  public function save() {
    if ($this->isNew()) {
      $this->insert();
    } else {
      $this->update();
    }
    $this->new = FALSE;
  }

  protected function update() {
    $stmt = db_update(static::$table);
    foreach (static::$key as $key) {
      $stmt->condition($key, $this->{$key});
    }
    $stmt->fields($this->values(static::$values))
      ->execute();
  }

  protected function insert() {
    $cols = static::$values;
    if (!static::$serial) {
      $cols = array_merge($cols, static::$key);
    }
    $ret = db_insert(static::$table)
      ->fields($this->values($cols))
      ->execute();
    if (static::$serial) {
      $this->{static::$key[0]} = $ret;
    }
  }

  public function delete() {
    $query = db_delete(static::$table);
    foreach ($this->values(static::$key) as $field => $value) {
      $query->condition($field, $value);
    }
    $query->execute();
    $this->new = TRUE;
  }

  protected function values($keys) {
    $data = array();
    foreach ($keys as $k) {
      $data[$k] = isset($this->{$k}) ? (empty(static::$serialize[$k]) ? $this->{$k} : serialize($this->{$k})) : NULL;
    }
    return $data;
  }
}
