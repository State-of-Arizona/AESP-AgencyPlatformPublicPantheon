<?php

namespace Drupal\little_helpers\Field;

class FieldCollection extends Field implements BundleInterface {
  public function getBundleName() { return $this->field_name; }
  public function getEntityType() { return 'field_collection'; }
}
