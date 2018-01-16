<?php

namespace Drupal\little_helpers\Webform;

module_load_include('inc', 'webform', 'includes/webform.submissions');

/**
 * A useful wrapper for webform submission objects.
 */
class Submission {
  public $node;
  protected $submission;
  public $webform;

  protected $data;

  /**
   * Load a submission object based on it's $nid and $sid.
   *
   * @param int $nid
   *   Node ID of the submission.
   * @param int $sid
   *   Submission ID.
   * @param bool $reset
   *   Whether to reset the static cache from webform_get_submission(). Pass
   *   this if you are batch-processing submissions.
   *
   * @return \Drupal\little_helpers\Webform\Submission
   *   The submission or NULL if the no submission could be loaded.
   */
  public static function load($nid, $sid, $reset = FALSE) {
    // Neither node_load() nor webform_get_submission() can handle invalid IDs.
    if (!$nid || !$sid) {
      return NULL;
    }
    $node = node_load($nid);
    $submission = webform_get_submission($nid, $sid, $reset);
    if ($node && $submission) {
      return new static($node, $submission);
    }
  }

  /**
   * Constructor.
   *
   * @param object $node_or_webform
   *   Either a node-object or a Webform instance.
   * @param object $submission
   *   A submission object as created by webform.
   */
  public function __construct($node_or_webform, $submission) {
    $this->submission = $submission;
    if ($node_or_webform instanceof Webform) {
      $this->node = $node_or_webform->node;
      $this->webform = $node_or_webform;
    }
    else {
      $this->node = $node_or_webform;
      $this->webform = new Webform($node_or_webform);
    }
    $this->data = array();

    if (!isset($submission->tracking)) {
      $submission->tracking = (object) [];
    }
    // Some components like checkboxes and fieldsets may have no values
    // We want to return NULL in that case instead of throwing a notice.
    $webform4 = Webform::is_webform4();
    foreach (array_keys($this->node->webform['components']) as $cid) {
      if (isset($this->submission->data[$cid])) {
        $this->data[$cid] = $webform4 ?
                            $this->submission->data[$cid] :
                            $this->submission->data[$cid]['value'];
      }
      else {
        $this->data[$cid] = array(NULL);
      }
    }
  }

  /**
   * Retrieve a single value by a component's form_key.
   *
   * @param string $form_key
   *   The form_key to look for.
   *
   * @return mixed
   *   A value if possible or NULL otherwise.
   */
  public function valueByKey($form_key) {
    if ($component = &$this->webform->componentByKey($form_key)) {
      return $this->valueByCid($component['cid']);
    }
    elseif (isset($this->submission->tracking->$form_key)) {
      return $this->submission->tracking->$form_key;
    }
  }

  /**
   * Retrieve all values for a component by it's form_key.
   *
   * @param string $form_key
   *   The form_key to look for.
   *
   * @return array
   *   An array of values.
   */
  public function valuesByKey($form_key) {
    if ($component = &$this->webform->componentByKey($form_key)) {
      return $this->valuesByCid($component['cid']);
    }
    elseif (isset($this->submission->tracking->$form_key)) {
      return $this->submission->tracking->$form_key;
    }
  }

  public function valuesByType($type) {
    $values = array();
    foreach (array_keys($this->webform->componentsByType($type)) as $cid) {
      $values[$cid] = $this->valueByCid($cid);
    }
    return $values;
  }

  public function valueByCid($cid) {
    reset($this->data[$cid]);
    return current($this->data[$cid]);
  }

  public function valuesByCid($cid) {
    return $this->data[$cid];
  }

  /**
   * Get the original webform object.
   */
  public function unwrap() {
    return $this->submission;
  }

  public function ids() {
    return array(
      'nid' => $this->node->nid,
      'sid' => $this->submission->sid,
    );
  }

  /**
   * All submission properties are accessible directly.
   */
  public function __get($name) {
    return $this->submission->$name;
  }

  /**
   * @deprecated Serializing submission objects is not a good idea especially
   *   for long term storage.
   */
  public function __sleep() {
    $this->nid = $this->node->nid;
    $this->sid = $this->submission->sid;
    return array('nid', 'sid');
  }

  /**
   * @deprecated Serializing submission objects is not a good idea especially
   *   for long term storage.
   */
  public function __wakeup() {
    if (!($node = node_load($this->nid))) {
      throw new \UnexpectedValueException('Tried to __wakeup with non-existing node.');
    }
    if (!($submission = webform_get_submission($this->nid, $this->sid))) {
      throw new \UnexpectedValueException('Tried to __wakeup with non-existing submission.');
    }
    $this->__construct($node, $submission);
  }

  public function getNode() {
    return $this->node;
  }

}
