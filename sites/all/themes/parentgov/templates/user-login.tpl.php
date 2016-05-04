<?php
/**
 * Created by PhpStorm.
 * User: twilliams
 * Date: 3/22/2016
 * Time: 10:50 AM
 */
//  print '<pre>';
//  print drupal_render($form['name']);
//  print drupal_render($form['pass']);
//  print drupal_render($form['form_build_id']);
//  print drupal_render($form['form_id']);
//  print drupal_render($form['actions']);
//  print '</pre>';
print '<p>Notice to Users:</p>';
print '<p>You are accessing the State of Arizona local/wide area network and systems containing State of Arizona and U.S. Government information. This system is for authorized users only. All equipment, systems, services, and software connected to this network are intended only for the official business use of, and are the property of, the State of Arizona. </p>';
print '<p>The State of Arizona reserves the right to audit, inspect, and disclose all transactions and data sent over this medium in a manner consistent with state and federal laws. Users should have no expectation of privacy as to any communication on or information stored within the system. By using this system, you expressly consent to all such auditing, inspection and disclosure.</p>';
print '<p>Only software approved, scanned for virus, and licensed for State of Arizona use will be permitted on this network. Data accessible via state systems cannot be used for personal or commercial use unless specifically authorized in writing by the State of Arizona. Any illegal or unauthorized use of State of Arizona equipment, systems, or software by any person(s) may be subject to civil or criminal prosecution under state and federal laws, and may also result in disciplinary action where appropriate.</p>';
print drupal_render_children($form)

?>