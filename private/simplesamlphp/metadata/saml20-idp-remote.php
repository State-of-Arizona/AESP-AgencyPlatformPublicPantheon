<?php

//Including the configuration values
// include '../../../sites/default/files/private/az_okta_config.php';
// include '../../../sites/default/files/private/test_az_okta_config.php';
// include '../../../sites/default/files/private/live_az_okta_config.php';

$realpath = $_SERVER['DOCUMENT_ROOT'] . '/../files/private/';
//Including the configuration values
include $realpath . 'az_okta_config.php';
include $realpath . 'test_az_okta_config.php';
include $realpath . 'live_az_okta_config.php';

/**
 * SAML 2.0 remote IdP metadata for SimpleSAMLphp.
 *
 * Remember to remove the IdPs you don't use from this file.
 *
 * See: https://simplesamlphp.org/docs/stable/simplesamlphp-reference-idp-remote 
 */

//====================================== Metadata for live ===================================================
//============================================================================================================

if (isset($_SERVER['PANTHEON_ENVIRONMENT']) && $_SERVER['PANTHEON_ENVIRONMENT'] === 'live' ) {

  $live_entity_id = $live_az_okta_xml['EntityDescriptor']['@entityID'];
  $live_post_binding = $live_az_okta_xml['EntityDescriptor']['md:IDPSSODescriptor']['md:SingleSignOnService'][0]['@Binding'];
  $live_post_location = $live_az_okta_xml['EntityDescriptor']['md:IDPSSODescriptor']['md:SingleSignOnService'][0]['@Location'];
  $live_redirect_binding = $live_az_okta_xml['EntityDescriptor']['md:IDPSSODescriptor']['md:SingleSignOnService'][1]['@Binding'];
  $live_redirect_location = $live_az_okta_xml['EntityDescriptor']['md:IDPSSODescriptor']['md:SingleSignOnService'][1]['@Location'];
  $live_certifcate = $live_az_okta_array['certifcate'];

$metadata[$live_entity_id] = array (
  'entityid' => $live_entity_id,
  'contacts' => 
  array (
  ),
  'metadata-set' => 'saml20-idp-remote',
  'SingleSignOnService' => 
  array (
    0 => 
    array (
      'Binding' => $live_post_binding,
      'Location' => $live_post_location,
    ),
    1 => 
    array (
      'Binding' => $live_redirect_binding,
      'Location' => $live_redirect_location,
    ),
  ),
  'SingleLogoutService' => 
  array (
  ),
  'ArtifactResolutionService' => 
  array (
  ),
  'NameIDFormats' => 
  array (
    0 => 'urn:oasis:names:tc:SAML:1.1:nameid-format:unspecified',
    1 => 'urn:oasis:names:tc:SAML:1.1:nameid-format:emailAddress',
  ),
  'keys' => 
  array (
    0 => 
    array (
      'encryption' => false,
      'signing' => true,
      'type' => 'X509Certificate',
      'X509Certificate' => $live_certifcate,
    ),
  ),
);

} //end of live metadata


//====================================== Metadata for test ===================================================
//============================================================================================================

if (isset($_SERVER['PANTHEON_ENVIRONMENT']) && $_SERVER['PANTHEON_ENVIRONMENT'] === 'test' ) {

  $test_entity_id = $test_az_okta_xml['EntityDescriptor']['@entityID'];
  $test_post_binding = $test_az_okta_xml['EntityDescriptor']['md:IDPSSODescriptor']['md:SingleSignOnService'][0]['@Binding'];
  $test_post_location = $test_az_okta_xml['EntityDescriptor']['md:IDPSSODescriptor']['md:SingleSignOnService'][0]['@Location'];
  $test_redirect_binding = $test_az_okta_xml['EntityDescriptor']['md:IDPSSODescriptor']['md:SingleSignOnService'][1]['@Binding'];
  $test_redirect_location = $test_az_okta_xml['EntityDescriptor']['md:IDPSSODescriptor']['md:SingleSignOnService'][1]['@Location'];
  $test_certifcate = $test_az_okta_array['certifcate'];

$metadata[$test_entity_id] = array (
  'entityid' => $test_entity_id,
  'contacts' => 
  array (
  ),
  'metadata-set' => 'saml20-idp-remote',
  'SingleSignOnService' => 
  array (
    0 => 
    array (
      'Binding' => $test_post_binding,
      'Location' => $test_post_location,
    ),
    1 => 
    array (
      'Binding' => $test_redirect_binding,
      'Location' => $test_redirect_location,
    ),
  ),
  'SingleLogoutService' => 
  array (
  ),
  'ArtifactResolutionService' => 
  array (
  ),
  'NameIDFormats' => 
  array (
    0 => 'urn:oasis:names:tc:SAML:1.1:nameid-format:unspecified',
    1 => 'urn:oasis:names:tc:SAML:1.1:nameid-format:emailAddress',
  ),
  'keys' => 
  array (
    0 => 
    array (
      'encryption' => false,
      'signing' => true,
      'type' => 'X509Certificate',
      'X509Certificate' => $test_certifcate,
    ),
  ),
);

} //End of test metadata



//====================================== Metadata for dev  ===================================================
//============================================================================================================

if (isset($_SERVER['PANTHEON_ENVIRONMENT']) && $_SERVER['PANTHEON_ENVIRONMENT'] === 'dev' ) {

  //testing access to bootstrap data
  //$az_array = _az_okta_parse_xml ();
  //Initial array key = http://www.okta.com/exk1g3zjvnI1RxZY4297
  $dev_entity_id = $az_okta_xml['EntityDescriptor']['@entityID'];
  $dev_post_binding = $az_okta_xml['EntityDescriptor']['md:IDPSSODescriptor']['md:SingleSignOnService'][0]['@Binding'];
  $dev_post_location = $az_okta_xml['EntityDescriptor']['md:IDPSSODescriptor']['md:SingleSignOnService'][0]['@Location'];
  $dev_redirect_binding = $az_okta_xml['EntityDescriptor']['md:IDPSSODescriptor']['md:SingleSignOnService'][1]['@Binding'];
  $dev_redirect_location = $az_okta_xml['EntityDescriptor']['md:IDPSSODescriptor']['md:SingleSignOnService'][1]['@Location'];
  $dev_certifcate = $az_okta_array['certifcate'];
  

$metadata[$dev_entity_id] = array (
  'entityid' => $dev_entity_id,
  'contacts' => 
  array (
  ),
  'metadata-set' => 'saml20-idp-remote',
  'SingleSignOnService' => 
  array (
    0 => 
    array (
      'Binding' => $dev_post_binding,
      'Location' => $dev_post_location,
    ),
    1 => 
    array (
      'Binding' => $dev_redirect_binding,
      'Location' => $dev_redirect_location,
    ),
  ),
  'SingleLogoutService' => 
  array (
  ),
  'ArtifactResolutionService' => 
  array (
  ),
  'NameIDFormats' => 
  array (
    0 => 'urn:oasis:names:tc:SAML:1.1:nameid-format:unspecified',
    1 => 'urn:oasis:names:tc:SAML:1.1:nameid-format:emailAddress',
  ),
  'keys' => 
  array (
    0 => 
    array (
      'encryption' => false,
      'signing' => true,
      'type' => 'X509Certificate',
      'X509Certificate' => $dev_certifcate,
    ),
  ),
);

}



