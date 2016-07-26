<?php
/**
 * @file
 */

namespace Drupal\little_helpers\Webform;

/**
 * Class for making webform component values before an submission is saved.
 */
class FormState {
  protected $node;
  protected $formState;
  protected $values;
  public $webform;

  public function __construct($node, $form, array &$form_state) {
    $this->node = $node;
    $this->webform = new Webform($node);
    $this->formState = &$form_state;
    // Assume webform_client_form_pages() has already been run.
    $this->values = &$form_state['values']['submitted'];
  }

  public function getNode() {
    return $this->node;
  }

  public function valueByCid($cid) {
    if (isset($this->values[$cid])) {
      if (is_array($this->values[$cid])) {
        reset($this->values[$cid]);
        return current($this->values[$cid]);
      }
      return $this->values[$cid];
    }
  }

  public function valuesByCid($cid) {
    if (isset($this->values[$cid])) {
      if (is_array($this->values[$cid])) {
        return $this->values[$cid];
      }
      return array($this->values[$cid]);
    }
    return array();
  }

  public function valueByKey($form_key) {
    if ($component = $this->webform->componentByKey($form_key)) {
      return $this->valueByCid($component['cid']);
    }
  }

  public function valuesByKeys(array $keys) {
    $result = array();
    foreach ($keys as $key) {
      if (($res = $this->valueByKey($key))) {
        $result[$key] = $res;
      }
    }
    return $result;
  }

  public function valuesByType($type) {
    $result = array();
    $components = $this->webform->componentsByType($type);
    foreach ($components as $component) {
      $result[$component['form_key']] = $this->valueByCid($component['cid']);
    }

    return $result;
  }

  public function getSubmission() {
    if (isset($this->formState['values']['details']['sid'])) {
      return Submission::load($this->node->nid, $this->formState['values']['details']['sid']);
    }
  }

  public function __sleep() {
    throw new Exception('FormState objects cannot be serialized as they would lose their reference to the form_state.');
  }
}
