<?php

namespace Drupal\little_helpers\Webform;

class FormStateTest extends \Drupal\Tests\DrupalWebTestCase {
  protected $webformNode = NULL;

  /*
  public function __construct($test_id = NULL) {
    parent::__construct($test_id);
  }
  */

  public static function getInfo() {
    return array(
      'name'        => t('FormState class'),
      'description' => t('Checks several methods of the little_helpers\FormState class with different $form_state setups.'),
      'group'       => t('little_helpers'),
    );
  }
  public function setUp() {
    // Enable any modules required for the test. This should be an array of
    // module names.
    parent::setUp(array('little_helpers'));
    $this->nodeStub();
  }
  /**
   * Implemenation of tearDown().
   */
  public function tearDown() {
    node_delete($this->webformNode->nid);
  }

  protected function formStub() {
    $form = array(
      '#form_id' => 'webform_client_form',
    );
    return $form;
  }

  protected function formStateFirstPageUnprocessedStub() {
    $form_state = array(
      'values' => array(
        'submitted' => array(
          'first_test_fieldset' => array(
            'first_name' => 'Myfirstname',
            'email' => 'myemail@address.at',
          ),
          'phone_number' => '01/1234568',
        ),
        'details' => array(
          'nid' => $this->webformNode->nid,
          'sid' => NULL,
          'uid' => '1',
          'page_num' => 1,
          'page_count' => 3,
          'finished' => 0,
        ),
        'op' => 'Next',
      ),
      'webform' => array(
        'component_tree' => array(
          'children' => array(),
        ),
        'page_num' => 1,
        'page_count' => 3,
        'preview' => FALSE,
      ),
      'clicked_button' => array(
        '#parents' => array(
          0 => 'next',
        ),
      ),
    );
    $this->nodeStubAddWebform($form_state['webform']['component_tree']['children']);

    return $form_state;
  }
  protected function formStateFirstPageProcessedStub() {
    $form_state = array(
      'values' => array(
        'details' => array(
          'nid' => $this->webformNode->nid,
          'sid' => NULL,
          'uid' => '1',
          'page_num' => 1,
          'page_count' => 3,
          'finished' => 0,
        ),
        'submitted' => array(
          1 => 'Myfirstname',
          3 => 'myemail@address.at',
          15 => '01/1234568',
        ),
        'op' => 'Next',
      ),
      'webform' => array(
        'component_tree' => array(
          'children' => array(),
        ),
        'page_num' => 1,
        'page_count' => 3,
      ),
      'clicked_button' => array(
        '#parents' => array(
          0 => 'next',
        ),
      ),
    );
    $this->nodeStubAddWebform($form_state['webform']['component_tree']['children']);

    return $form_state;
  }
  protected function formStateSecondPageUnprocessedStub() {
    $form_state = array(
      'values' => array(
        'submitted' => array(
          'new_1400574048840' => 'Page break',
          'second_test_fieldset' => array(
            'third_test_fieldset' => array(
              'new_1400576593706' => '987654321',
            ),
            'last_name' => 'Mylastname',
          ),
          'new_1400574602889' => 'some text for the textfield',
        ),
        'details' => array(
          'nid' => $this->webformNode->nid,
          'sid' => NULL,
          'uid' => '1',
          'page_num' => 2,
          'page_count' => 3,
          'finished' => 0,
        ),
        'op' => 'Next',
      ),
      'webform' => array(
        'component_tree' => array(
          'children' => array(),
        ),
        'page_num' => 1,
        'page_count' => 3,
      ),
      'clicked_button' => array(
        '#parents' => array(
          0 => 'next',
        ),
      ),
    );

    return $form_state;
  }
  protected function formStateSecondPageProcessedStub() {
    $form_state = array(
      'values' => array(
        'details' => array(
          'nid' => $this->webformNode->nid,
          'sid' => NULL,
          'uid' => '1',
          'page_num' => 2,
          'page_count' => 3,
          'finished' => 0,
        ),
        'op' => 'Next',
        'submitted' => array(
          1 => 'Myfirstname',
          3 => 'myemail@address.at',
          15 => '01/1234568',
          7 => 'Page break',
          18 => '987654321',
          14 => 'Mylastname',
          13 => 'some text for the textfield',
        ),
      ),
      'webform' => array(
        'component_tree' => array(
          'children' => array(),
        ),
        'page_num' => 1,
        'page_count' => 3,
      ),
      'clicked_button' => array(
        '#parents' => array(
          0 => 'next',
        ),
      ),
    );

    return $form_state;
  }
  protected function nodeStubAddWebform(array &$settings) {
    $settings = array(
      6 => array(
        'cid' => '6',
        'pid' => '0',
        'form_key' => 'first_test_fieldset',
        'name' => 'First Test Fieldset',
        'type' => 'fieldset',
        'value' => '',
        'extra' => array(
          'title_display' => 0,
          'private' => 0,
          'collapsible' => 0,
          'collapsed' => 0,
          'conditional_operator' => '=',
          'exclude_cv' => 0,
          'line_items' => NULL,
          'description' => '',
          'conditional_component' => '',
          'conditional_values' => '',
        ),
        'mandatory' => '0',
        'weight' => '0',
        'page_num' => 1,
      ),
      1 => array(
        'cid' => '1',
        'pid' => '6',
        'form_key' => 'first_name',
        'name' => 'First name',
        'type' => 'textfield',
        'value' => '%get[p3]',
        'extra' => array(
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'disabled' => 0,
          'unique' => false,
          'title_display' => 'before',
          'description' => '',
          'attributes' => array(),
          'private' => 0,
          'conditional_component' => '',
          'conditional_operator' => '=',
          'conditional_values' => '',
          'line_items' => NULL,
        ),
        'mandatory' => '1',
        'weight' => '0',
        'page_num' => 1,
      ),
      3 => array(
        'cid' => '3',
        'pid' => '6',
        'form_key' => 'email',
        'name' => 'Email address',
        'type' => 'email',
        'value' => '%get[p5]',
        'extra' => array(
          'width' => '',
          'unique' => true,
          'disabled' => 0,
          'title_display' => 'before',
          'description' => '',
          'attributes' => array(),
          'private' => 0,
          'conditional_component' => '',
          'conditional_operator' => '=',
          'conditional_values' => '',
          'line_items' => NULL,
        ),
        'mandatory' => '1',
        'weight' => '1',
        'page_num' => 1,
      ),
      15 => array(
        'cid' => '15',
        'pid' => '0',
        'form_key' => 'phone_number',
        'name' => 'Phone number',
        'type' => 'textfield',
        'value' => '%get[p11]',
        'extra' => array(
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'disabled' => 0,
          'unique' => false,
          'title_display' => 'before',
          'description' => '',
          'attributes' => 
          array (),
          'private' => 0,
          'line_items' => NULL,
          'conditional_component' => '',
          'conditional_operator' => '=',
          'conditional_values' => '',
        ),
        'mandatory' => '0',
        'weight' => '1',
        'page_num' => 1,
      ),
      7 => array(
        'cid' => '7',
        'pid' => '0',
        'form_key' => 'new_1400574048840',
        'name' => 'Page break',
        'type' => 'pagebreak',
        'value' => '',
        'extra' => array(
          'private' => false,
          'next_page_label' => '',
          'prev_page_label' => '',
          'line_items' => NULL,
          'conditional_component' => '',
          'conditional_operator' => '=',
          'conditional_values' => '',
        ),
        'mandatory' => '0',
        'weight' => '2',
        'page_num' => 2,
      ),
      16 => array(
        'cid' => '16',
        'pid' => '0',
        'form_key' => 'second_test_fieldset',
        'name' => 'Second Test Fieldset',
        'type' => 'fieldset',
        'value' => '',
        'extra' => array(
          'title_display' => 0,
          'private' => 0,
          'collapsible' => 0,
          'collapsed' => 0,
          'conditional_component' => '1',
          'conditional_operator' => '=',
          'exclude_cv' => 0,
          'line_items' => NULL,
          'description' => '',
          'conditional_values' => '',
        ),
        'mandatory' => '0',
        'weight' => '3',
        'page_num' => 2,
      ),
      17 => array(
        'cid' => '17',
        'pid' => '16',
        'form_key' => 'third_test_fieldset',
        'name' => 'Third Test Fieldset',
        'type' => 'fieldset',
        'value' => '',
        'extra' => array(
          'title_display' => 0,
          'private' => 0,
          'collapsible' => 0,
          'collapsed' => 0,
          'conditional_component' => '1',
          'conditional_operator' => '=',
          'exclude_cv' => 0,
          'line_items' => NULL,
          'description' => '',
          'conditional_values' => '',
        ),
        'mandatory' => '0',
        'weight' => '0',
        'page_num' => 2,
      ),
      18 => array(
        'cid' => '18',
        'pid' => '17',
        'form_key' => 'new_1400576593706',
        'name' => 'New number',
        'type' => 'number',
        'value' => '',
        'extra' => array(
          'type' => 'textfield',
          'field_prefix' => '',
          'field_suffix' => '',
          'disabled' => 0,
          'unique' => false,
          'title_display' => 'before',
          'description' => '',
          'attributes' => array(),
          'private' => 0,
          'min' => '',
          'max' => '',
          'step' => '',
          'decimals' => '',
          'point' => '.',
          'separator' => ',',
          'integer' => 0,
          'excludezero' => 0,
          'line_items' => NULL,
          'conditional_component' => '',
          'conditional_operator' => '=',
          'conditional_values' => '',
        ),
        'mandatory' => '0',
        'weight' => '0',
        'page_num' => 2,
      ),
      14 => array(
        'cid' => '14',
        'pid' => '16',
        'form_key' => 'last_name',
        'name' => 'Last name',
        'type' => 'textfield',
        'value' => '%get[p4]',
        'extra' => array(
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'disabled' => 0,
          'unique' => false,
          'title_display' => 'before',
          'description' => '',
          'attributes' => array(),
          'private' => 0,
          'line_items' => NULL,
          'conditional_component' => '',
          'conditional_operator' => '=',
          'conditional_values' => '',
        ),
        'mandatory' => '0',
        'weight' => '1',
        'page_num' => 2,
      ),
      13 => array(
        'cid' => '13',
        'pid' => '0',
        'form_key' => 'new_1400574602889',
        'name' => 'New textfield',
        'type' => 'textfield',
        'value' => '',
        'extra' => array(
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'disabled' => 0,
          'unique' => false,
          'title_display' => 'before',
          'description' => '',
          'attributes' => array(),
          'private' => 0,
          'line_items' => NULL,
          'conditional_component' => '',
          'conditional_operator' => '=',
          'conditional_values' => '',
        ),
        'mandatory' => '0',
        'weight' => '4',
        'page_num' => 2,
      ),
      10 => array(
        'cid' => '10',
        'pid' => '0',
        'form_key' => 'new_1400574093875',
        'name' => 'Page break',
        'type' => 'pagebreak',
        'value' => '',
        'extra' => array(
          'private' => false,
          'next_page_label' => '',
          'prev_page_label' => '',
          'line_items' => NULL,
          'conditional_component' => '',
          'conditional_operator' => '=',
          'conditional_values' => '',
        ),
        'mandatory' => '0',
        'weight' => '5',
        'page_num' => 3,
      ),
      19 => array(
        'cid' => '19',
        'pid' => '0',
        'form_key' => 'date_of_birth',
        'name' => 'Date of birth',
        'type' => 'textfield',
        'value' => '%get[p6]',
        'extra' => array(
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'disabled' => 0,
          'unique' => false,
          'title_display' => 'before',
          'description' => 'Bitte folgendermaßen eintragen: 16/9/1983',
          'attributes' => array(),
          'private' => 0,
          'line_items' => NULL,
          'conditional_component' => '',
          'conditional_operator' => '=',
          'conditional_values' => '',
        ),
        'mandatory' => '0',
        'weight' => '6',
        'page_num' => 3,
      ),
    );
  }
  protected function nodeStub() {
    $settings = array(
     'type' => 'webform',
     'language'  => LANGUAGE_NONE,
     'uid' => '1',
     'status' => '1',
     'promote' => '1',
     'moderate' => '0',
     'sticky' => '0',
     'tnid' => '0',
     'translate' => '0',
     'title' => 'FormState class unit test',
     'body' => array(LANGUAGE_NONE => array(array('value' => 'Donec placerat. Nullam nibh dolor, blandit sed, fermentum id, imperdiet sit amet, neque. Nam mollis ultrices justo. Sed tempor. Sed vitae tellus. Etiam sem arcu, eleifend sit amet, gravida eget, porta at, wisi. Nam non lacus vitae ipsum viverra pretium. Phasellus massa. Fusce magna sem, gravida in, feugiat ac, molestie eget, wisi. Fusce consectetuer luctus ipsum. Vestibulum nunc. Suspendisse dignissim adipiscing libero. Integer leo. Sed pharetra ligula a dui. Quisque ipsum nibh, ullamcorper eget, pulvinar sed, posuere vitae, nulla. Sed varius nibh ut lacus. Curabitur fringilla. Nunc est ipsum, pretium quis, dapibus sed, varius non, lectus. Proin a quam. Praesent lacinia, eros quis aliquam porttitor, urna lacus volutpat urna, ut fermentum neque mi egestas dolor.'))),
     'teaser' => array(LANGUAGE_NONE => array(array('value' => 'Donec placerat. Nullam nibh dolor, blandit sed, fermentum id, imperdiet sit amet, neque. Nam mollis ultrices justo. Sed tempor. Sed vitae tellus. Etiam sem arcu, eleifend sit amet, gravida eget, porta at, wisi. Nam non lacus vitae ipsum viverra pretium. Phasellus massa. Fusce magna sem, gravida in, feugiat ac, molestie eget, wisi. Fusce consectetuer luctus ipsum. Vestibulum nunc. Suspendisse dignissim adipiscing libero. Integer leo. Sed pharetra ligula a dui. Quisque ipsum nibh, ullamcorper eget, pulvinar sed, posuere vitae, nulla. Sed varius nibh ut lacus. Curabitur fringilla.'))),
     'log' => '',
     'format' => '1',
     'webform' => array(
        'confirmation' => 'Thanks!',
        'confirmation_format' => filter_default_format(),
        'redirect_url' => '<confirmation>',
        'teaser' => '0',
        'allow_draft' => '1',
        'submit_text' => '',
        'submit_limit' => '-1',
        'submit_interval' => '-1',
        'submit_notice' => '1',
        'roles' => array('1', '2'),
        'components' => array(),
        'emails' => array(),
        'preview' => FALSE,
      ),
    );
    $this->nodeStubAddWebform($settings['webform']['components']);

    $this->webformNode = $this->drupalCreateNode($settings);
  }

  /* ------------------------------ Tests ------------------------- */

  /**
   * Tests of FormState class with a form_state on the first page
   * of a multi page webform before the webform module processed it */

  public function testFormStateFirstPageUnprocessed_returnsValueByKey() {
    $form_state = $this->formStateFirstPageUnprocessedStub();
    $form       = $this->formStub();
    $formState  = new FormState($this->webformNode, $form, $form_state);
    $this->assertEqual('Myfirstname', $formState->valueByKey('first_name'));
  }
  public function testFormStateFirstPageUnprocessed_returnsValueByCid() {
    $form_state = $this->formStateFirstPageUnprocessedStub();
    $form       = $this->formStub();
    $formState  = new FormState($this->webformNode, $form, $form_state);
    $this->assertEqual('01/1234568', $formState->valueByCid(15));
  }
  public function testFormStateFirstPageUnprocessed_returnsValueByKeys() {
    $form_state = $this->formStateFirstPageUnprocessedStub();
    $form       = $this->formStub();
    $formState  = new FormState($this->webformNode, $form, $form_state);
    $value_reference = array(
      'first_name'   => 'Myfirstname',
      'email'        => 'myemail@address.at',
      'phone_number' => '01/1234568',
    );
    $this->assertEqual($value_reference, $formState->valuesByKeys(array_keys($value_reference)));
  }
  public function testFormStateFirstPageUnprocessed_returnsValueByType() {
    $form_state = $this->formStateFirstPageUnprocessedStub();
    $form       = $this->formStub();
    $formState  = new FormState($this->webformNode, $form, $form_state);
    $value_reference = array(
      'first_name'        => 'Myfirstname',
      'phone_number'      => '01/1234568',
      'last_name'         => NULL,
      'new_1400574602889' => NULL,
      'date_of_birth'     => NULL,
    );
    $this->assertEqual($value_reference, $formState->valuesByType('textfield'));
  }
}