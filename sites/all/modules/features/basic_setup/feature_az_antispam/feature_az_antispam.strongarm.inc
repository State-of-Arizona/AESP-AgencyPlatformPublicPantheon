<?php
/**
 * @file
 * feature_az_antispam.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_az_antispam_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'httpbl_accesskey';
  $strongarm->value = 'pfssixgoswug';
  $export['httpbl_accesskey'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'httpbl_blacklist_offset';
  $strongarm->value = '2419200';
  $export['httpbl_blacklist_offset'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'httpbl_black_threshold';
  $strongarm->value = '75';
  $export['httpbl_black_threshold'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'httpbl_cache';
  $strongarm->value = '1';
  $export['httpbl_cache'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'httpbl_check';
  $strongarm->value = '2';
  $export['httpbl_check'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'httpbl_footer';
  $strongarm->value = 0;
  $export['httpbl_footer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'httpbl_greylist_offset';
  $strongarm->value = '86400';
  $export['httpbl_greylist_offset'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'httpbl_grey_threshold';
  $strongarm->value = '1';
  $export['httpbl_grey_threshold'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'httpbl_link';
  $strongarm->value = '';
  $export['httpbl_link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'httpbl_log';
  $strongarm->value = '1';
  $export['httpbl_log'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'httpbl_message_black';
  $strongarm->value = 'Sorry, your IP address (%ip) has been blacklisted by <a href="%ipurl">http:BL</a>.%honeypot';
  $export['httpbl_message_black'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'httpbl_message_grey';
  $strongarm->value = '<p>We\'re sorry!<br /> We <strong>cannot</strong> let you access our website at this time.</p> <p>Your IP address (%ip) has been identified as a <em>possible</em> source of suspicious, robotic traffic and has been greylisted by <a href="%ipurl">Project Honeypot</a>.</p><p>If you are an actual human visitor who can read simple instructions,<br />you may try getting whitelisted on <a href="%whitelisturl">%whitelisturl</a>.</p>%honeypot';
  $export['httpbl_message_grey'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'httpbl_safe_offset';
  $strongarm->value = '10800';
  $export['httpbl_safe_offset'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'httpbl_stats';
  $strongarm->value = 1;
  $export['httpbl_stats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'httpbl_word';
  $strongarm->value = 'randomness';
  $export['httpbl_word'] = $strongarm;

  return $export;
}
