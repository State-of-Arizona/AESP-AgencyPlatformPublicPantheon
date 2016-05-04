<?php

function parentgov_theme() {
$items = array();
// create custom user-login.tpl.php
$items['user_login'] = array(
'render element' => 'form',
'path' => drupal_get_path('theme', 'az_gov') . '/templates',
'template' => 'user-login',
'preprocess functions' => array(
'az_gov_preprocess_user_login'
),
);
return $items;
}