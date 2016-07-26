<?php
/**
 * @file
 * feature_search_scs_purchase.css_injector_rules.inc
 */

/**
 * Implements hook_css_injector_rule().
 */
function feature_search_scs_purchase_css_injector_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 1;
  $rule->name = 'Padding Region Content - Form submit buttons';
  $rule->admin_description = 'padding on the submit buttons';
  $rule->css = '#zone-content .region-content {
    padding: 0 5% 15px;
}
.webform-component--azl-use-only--scs-authorization-code, .form-item-submitted-azl-use-only-payment-payment-method-selector {
   display: none;
}';
  $rule->media = 'all';
  $rule->rule_themes = 'a:0:{}';
  $rule->preprocess = 0;
  $rule->inline = 0;
  $rule->page_visibility = 0;
  $rule->page_visibility_pages = '';
  $export['Padding Region Content - Form submit buttons'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 1;
  $rule->name = 'table responsive webform results page';
  $rule->admin_description = 'table responsive for webform results page';
  $rule->css = '.table-responsive {
    width: 100%;
    margin-bottom: 15px;
    overflow-x: auto;
    overflow-y: hidden;
    -webkit-overflow-scrolling: touch;
    -ms-overflow-style: -ms-autohiding-scrollbar;
    border: 1px solid #ddd;
}';
  $rule->media = 'all';
  $rule->rule_themes = 'a:0:{}';
  $rule->preprocess = 0;
  $rule->inline = 0;
  $rule->page_visibility = 1;
  $rule->page_visibility_pages = 'node/*/webform-results/*
node/*/webform-results
node/*/webform-search';
  $export['table responsive webform results page'] = $rule;

  return $export;
}
