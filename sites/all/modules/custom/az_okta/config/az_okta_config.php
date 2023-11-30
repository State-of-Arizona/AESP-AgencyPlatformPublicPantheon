<?php

$az_okta_array = array (
  'entity_id' => 'az_aset_okta',
  'environment' => 'development',
  'assertion_url' => 'https://dev-az-aset:443/simplesaml/module.php/saml/sp/saml2-acs.php/default-sp',
  'xml_data' => '<?xml version="1.0" encoding="UTF-8"?><md:EntityDescriptor xmlns:md="urn:oasis:names:tc:SAML:2.0:metadata" entityID="http://www.okta.com/exk1g3zjvnI1RxZY4297"><md:IDPSSODescriptor WantAuthnRequestsSigned="false" protocolSupportEnumeration="urn:oasis:names:tc:SAML:2.0:protocol"><md:KeyDescriptor use="signing"><ds:KeyInfo xmlns:ds="http://www.w3.org/2000/09/xmldsig#"><ds:X509Data><ds:X509Certificate>MIIDlDCCAnygAwIBAgIGAWEGR7Z9MA0GCSqGSIb3DQEBCwUAMIGKMQswCQYDVQQGEwJVUzETMBEG
A1UECAwKQ2FsaWZvcm5pYTEWMBQGA1UEBwwNU2FuIEZyYW5jaXNjbzENMAsGA1UECgwET2t0YTEU
MBIGA1UECwwLU1NPUHJvdmlkZXIxCzAJBgNVBAMMAmF6MRwwGgYJKoZIhvcNAQkBFg1pbmZvQG9r
dGEuY29tMB4XDTE4MDExNzIyMzkxOFoXDTI4MDExNzIyNDAxN1owgYoxCzAJBgNVBAYTAlVTMRMw
EQYDVQQIDApDYWxpZm9ybmlhMRYwFAYDVQQHDA1TYW4gRnJhbmNpc2NvMQ0wCwYDVQQKDARPa3Rh
MRQwEgYDVQQLDAtTU09Qcm92aWRlcjELMAkGA1UEAwwCYXoxHDAaBgkqhkiG9w0BCQEWDWluZm9A
b2t0YS5jb20wggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQC0OczVU6i/Hb1Fjjce0rwp
BxYUDeTjCEiVAKBtnz8ZK+SdNblu/wAuyiPHsH7MyJgU5n8QMSGmv9Flv41b71ZUj0yGX6Uzlrgd
yHz2jj665G0rGDNW98wMXVLzUM3+ZKdHsQWbigvuEVrhIggqeubGMx6xtFLkdSgKz74ly7tnnFwV
qBt1mxg4MFgykvn8TY+bZ0hBKwHycPoHgB2g3Kj31eMe25yj+04MisZ1ibvrH9YGgonXaTGsZ8cn
AJp8CoKHGbY+zl0MKQuil5U3kqPjXDlZebd5u3hyl5X3Gx58qL2dQ9w/9aboq34+BD7Jft8Ai8hw
IIfQHLSFSxdueLEDAgMBAAEwDQYJKoZIhvcNAQELBQADggEBAGlaN3jh3dR9gtACny9opEsUeOuE
SYxPmk+k6kxSyRi+KeS5i1ZlDmHYDtY+PJK/4iX4d57N9PHERm7TV+/8yiGWGVjX2haEMFBafAuq
/LhzZaJjGWH0UH18jSESKPty7TXnVfjoJpFKNf8sKpPNe3ALZX124jWjB5NYUnvuMAVj+IhCQ5P1
32jLKepdR262LV6EYnLsaa3sNtV3N/JWBCcOLGOQjETtP1NrskEfDr2kUeZJACZHxehzD5Fy4+YD
stFULxx5lozR8iyG02x1rUo2zDnVlnpy3KrW6oeM8L2btBYcgh0tqFmquu10cfrG0rZ/8ABXOqKB
V2E8K7T3QIc=</ds:X509Certificate></ds:X509Data></ds:KeyInfo></md:KeyDescriptor><md:NameIDFormat>urn:oasis:names:tc:SAML:1.1:nameid-format:unspecified</md:NameIDFormat><md:NameIDFormat>urn:oasis:names:tc:SAML:1.1:nameid-format:emailAddress</md:NameIDFormat><md:SingleSignOnService Binding="urn:oasis:names:tc:SAML:2.0:bindings:HTTP-POST" Location="https://az.okta.com/app/stateofarizonaprod_agencyplatformasetazgovdev_1/exk1g3zjvnI1RxZY4297/sso/saml"/><md:SingleSignOnService Binding="urn:oasis:names:tc:SAML:2.0:bindings:HTTP-Redirect" Location="https://az.okta.com/app/stateofarizonaprod_agencyplatformasetazgovdev_1/exk1g3zjvnI1RxZY4297/sso/saml"/></md:IDPSSODescriptor></md:EntityDescriptor>',
);

$az_okta_xml = array (
  'EntityDescriptor' =>
  array (
    '@entityID' => 'http://www.okta.com/exk1g3zjvnI1RxZY4297',
    'md:IDPSSODescriptor' =>
    array (
      '@WantAuthnRequestsSigned' => 'false',
      '@protocolSupportEnumeration' => 'urn:oasis:names:tc:SAML:2.0:protocol',
      'md:KeyDescriptor' =>
      array (
        '@use' => 'signing',
      ),
      'md:NameIDFormat' =>
      array (
        0 => 'urn:oasis:names:tc:SAML:1.1:nameid-format:unspecified',
        1 => 'urn:oasis:names:tc:SAML:1.1:nameid-format:emailAddress',
      ),
      'md:SingleSignOnService' =>
      array (
        0 =>
        array (
          '@Binding' => 'urn:oasis:names:tc:SAML:2.0:bindings:HTTP-POST',
          '@Location' => 'https://az.okta.com/app/stateofarizonaprod_agencyplatformasetazgovdev_1/exk1g3zjvnI1RxZY4297/sso/saml',
        ),
        1 =>
        array (
          '@Binding' => 'urn:oasis:names:tc:SAML:2.0:bindings:HTTP-Redirect',
          '@Location' => 'https://az.okta.com/app/stateofarizonaprod_agencyplatformasetazgovdev_1/exk1g3zjvnI1RxZY4297/sso/saml',
        ),
      ),
    ),
  ),
);

