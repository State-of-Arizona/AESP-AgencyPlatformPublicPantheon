<?php

/**
 * React when a webform submission is completed and email confirmation is done.
 *
 * This hook is invoked in two cases:
 * - A submission that doesn't need confirmation is saved as complete for the
 *   its first time.
 * - A submission needing email confirmation is confirmed.
 *
 * @param \Drupal\little_helpers\Webform\Submission $submission_o
 *  The submission just having been confirmed / saved.
 */

function hook_webform_submission_confirmed($submission_o) {
}
