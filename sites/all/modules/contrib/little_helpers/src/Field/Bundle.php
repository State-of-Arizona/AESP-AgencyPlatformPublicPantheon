<?php

namespace Drupal\little_helpers\Field;

class Bundle implements BundleInterface {
  protected $entity_type;
  protected $bundle;
  public function __construct($entity_type, $bundle) {
    $this->entity_type = $entity_type;
    $this->bundle = $bundle;
  }
  public function getBundleName() { return $this->bundle; }
  public function getEntityType() { return $this->entity_type; }
}
