<?
/**
*Implements hook_preprocess_node().
*/

function moderngov_preprocess_node(&$variables)
{
	drupal_add_http_header('X-UA-Compatible', 'IE=edge,chrome=1');
}
