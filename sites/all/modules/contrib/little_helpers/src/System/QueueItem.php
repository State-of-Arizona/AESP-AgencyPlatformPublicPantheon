<?php

namespace Drupal\little_helpers\System;

use \Drupal\little_helpers\DB\Model;

class QueueItem extends Model {
  protected static $table = 'queue';
  protected static $key = array('item_id');
  protected static $values = array('name', 'data', 'expire', 'created');
  protected static $serial = TRUE;
  protected static $serialize = array('data' => TRUE);

  public static function load($id) {
    if ($item = db_query('SELECT * FROM {queue} WHERE item_id=:id', array(':id' => $id))->fetch()) {
      return new static($item);
    }
  }
}
