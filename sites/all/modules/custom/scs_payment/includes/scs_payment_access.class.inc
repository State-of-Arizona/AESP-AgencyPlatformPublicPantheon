<?php

/*
 * Generates our XML string for posting
 *
 *
 */
class SCSPaymentXML {

  var $xml;
  var $indent;
  var $stack = array();

  function __construct() {
    // @TODO: Pass in our drupal configuration for debugging?  Maybe create a new one for XML testing?
    $this->indent = variable_get('', FALSE) ? '   ' : '';
    $this->xml = '<?xml version="1.0" encoding="UTF-8"?>' . "\n";
  }

  /*
   * Indents our XML to make it more readable for debugging
   */
  function _indent() {
    for ($i = 0, $j = count($this->stack); $i < $j; $i++) {
      $this->xml .= $this->indent;
    }
  }

  /*
   * Pushes a new element onto the xml stack
   */
  function push($element, $attributes = array()) {
    $this->_indent();
    $this->xml .= '<' . $element;
    foreach ($attributes as $key => $value) {
      $this->xml .= ' ' . $key . '="' . htmlentities($value, ENT_NOQUOTES,'ISO-8859-1', false) . '"';
    }
    $this->xml .= ">\n";
    $this->stack[] = $element;
  }

  /*
   * Creates an xml element and appends it to our variable.
   */
  function element($element, $content, $attributes = array()) {
    if ($content != '') {
      $this->_indent();
      $this->xml .= '<' . $element;
      foreach ($attributes as $key => $value) {
        $this->xml .= ' ' . $key . '="' . htmlentities($value, ENT_NOQUOTES, 'ISO-8859-1', false) . '"';
      }
      $this->xml .= '>' . htmlentities($content, ENT_NOQUOTES, 'ISO-8859-1', false).'</'. $element .'>' . "\n";
    }
  }

  /*
   * Creates an empty element.
   */
  function emptyelement($element, $attributes = array()) {
    $this->_indent();
    $this->xml .= '<' . $element;
    foreach ($attributes as $key => $value) {
      $this->xml .= ' ' . $key.'="'.htmlentities($value, ENT_NOQUOTES, 'ISO-8859-1', false) . '"';
    }
    $this->xml .= " />\n";
  }

  /*
   * Closes our tag and pops out of the current stack
   */
  function pop() {
    $element = array_pop($this->stack);
    $this->_indent();
    $this->xml .= "</$element>\n";
  }

  /*
   * Appends to the end of our xmlstring.
   */
  function append($xmlString) {
    $this->xml .= "$xmlString";
  }

  /*
   * Returns our xml for use.
   */
  function getXml() {
    return $this->xml;
  }
}