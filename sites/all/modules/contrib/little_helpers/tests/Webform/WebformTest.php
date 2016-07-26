<?php

namespace Drupal\little_helpers\Webform;

class WebformTest extends \Drupal\Tests\DrupalUnitTestCase {
  public static function nodeStub() {
    $webform['redirect_url'] = 'node/167';
    $webform['components'][1] = array(
      'cid' => '1',
      'form_key' => 'first_name',
      'name' => 'First name',
      'type' => 'textfield',
      'value' => '%get[p3]',
      'extra' => array(),
    );
    $webform['components'][2] = array(
      'cid' => '2',
      'form_key' => 'last_name',
      'name' => 'Last name',
      'type' => 'textfield',
      'value' => '%get[p4]',
      'extra' => array(),
    );
    $webform['components'][3] = array(
      'cid' => '3',
      'pid' => '0',
      'form_key' => 'email',
      'name' => 'Mail ',
      'type' => 'email',
      'value' => '%get[p5]',
      'extra' => array(),
    );
    $webform['components'][4] = array(
      'cid' => '4',
      'pid' => '0',
      'form_key' => 'your_message',
      'name' => 'Your message',
      'type' => 'fieldset',
      'value' => '',
      'extra' => array(),
    );
    $webform['components'][6] = array(
      'cid' => '6',
      'pid' => '4',
      'form_key' => 'email_subject',
      'name' => 'Subject',
      'type' => 'textfield',
      'value' => 'subject default value',
      'extra' => array(),
    );
    $webform['components'][7] = array(
      'cid' => '7',
      'pid' => '4',
      'form_key' => 'email_body',
      'name' => 'Your email',
      'type' => 'textarea',
      'value' => 'body default value',
      'extra' => array(),
    );
    return (object) array('webform' => $webform);
  }

  public function testComponent_ReturnsComponentArray() {
    $node = self::nodeStub();
    $webform = new Webform($node);
    $component = $webform->component(6);
    $this->assertEqual('email_subject', $component['form_key']);
  }
  
  public function testComponent_ReturnsNULLForUnknownComponent() {
    $node = self::nodeStub();
    $webform = new Webform($node);
    $this->assertNull($webform->component(12));
  }
}
