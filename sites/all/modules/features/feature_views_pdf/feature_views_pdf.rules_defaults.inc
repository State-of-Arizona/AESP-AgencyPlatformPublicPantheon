<?php
/**
 * @file
 * feature_views_pdf.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function feature_views_pdf_default_rules_configuration() {
  $items = array();
  $items['rules_permit_renewal_event'] = entity_import('rules_config', '{ "rules_permit_renewal_event" : {
      "LABEL" : "Permit Renewal Event",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "webform_config_helper" ],
      "ON" : { "renewal_reminder_event" : [] },
      "DO" : [
        { "mail" : {
            "to" : "[submitter-email:value]",
            "subject" : "Your Permit is about to expired",
            "message" : "Your Permit is about to expired on [permit-expired-date:value]",
            "from" : "noreply@azland.gov",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_send_pdf_permit_to_buyer'] = entity_import('rules_config', '{ "rules_send_pdf_permit_to_buyer" : {
      "LABEL" : "Send PDF Permit to Buyer",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "payment", "rules", "mimemail" ],
      "ON" : { "payment_status_change" : [] },
      "IF" : [
        { "payment_rules_condition_payment_status_is" : {
            "payment" : [ "payment" ],
            "payment_statuses" : { "value" : { "payment_status_success" : "payment_status_success" } }
          }
        }
      ],
      "DO" : [
        { "mimemail" : {
            "key" : "SendPermit",
            "to" : "[payment:submitted_user_email]",
            "from_mail" : "noreply@azland.gov",
            "reply_to" : "noreply@azland.gov",
            "subject" : "Thank you for your purchase of the Arizona State Land Department Recreational Permit.",
            "body" : "Thank you for your purchase of the Arizona State Land Department Recreational Permit.\\r\\n \\r\\nPlease print the Recreational Permit and Parking Pass.  The Recreational Permit shall stay on your person at all times while recreating on State Trust land.  The Parking Pass shall remain in the vehicle parked on State Trust land.\\r\\n",
            "attachments" : "[payment:confirmation_pdf_uri]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
