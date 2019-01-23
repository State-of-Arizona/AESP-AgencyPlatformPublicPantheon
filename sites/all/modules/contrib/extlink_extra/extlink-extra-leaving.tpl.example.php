<?php
/* 
If you would rather use the tpl than the text box in the UI, you can reconstruct a facsimile here.
Save this file as extlink-extra-leaving.tpl.php to use it.

The following variables correspond to the tokens descibed on the External Link module's settings page:
$back_url
$external_url
$timer

The alert text itself (with token replacements applied, so omit them if you plan to deploy the tokens in the tpl)
$alert_text

The page title as entered on the External Links settings page (Drupal will set this on the now-leaving page, but you can access it here anyway)
$page_title

Tip for themers: The javascript renders the automatic timer like this:
<div class="automatic-redirect-countdown">
  <span class="extlink-timer-text">Automatically redirecting in: </span>
  <span class="extlink-count">'+count+'</span>
  <span class="extlink-timer-text"> seconds.</span>
</div>

Don't remove any CSS classes if you want them to function correctly, but add any that you need.
*/

$site_name = (theme_get_setting('toggle_name') ? filter_xss_admin(variable_get('site_name', 'Drupal')) : '');

?>
<div class="extlink-extra-leaving">
  <h2>You are leaving the <?php $site_name; ?> website</h2>
  <p>You are being directed to a third-party website:</p>
  <p><strong><?php print $external_url; ?></strong></p>
  <p>This link is provided for your convenience. Please note that this third-party website is not controlled by <?php $site_name; ?> or subject to our privacy policy.</p>
  <p>Thank you for visiting our site. We hope your visit was informative and enjoyable.</p>
  
  <div class="extlink-extra-actions">
    <div class="extlink-extra-back-action"><a title="Cancel" href="<?php print $back_url; ?>">Cancel</a></div>
    <div class="extlink-extra-go-action"><a class="ext-override" title="Go to link" href="<?php print $external_url; ?>">Go to link</a></div>
  </div>
  <br/><br/>
  <?php print $timer; ?>
</div>
