DESCRIPTION:
------------
Instead of showing a standard "404 Page not found", this module
performs a search on the keywords in the URL.

INSTALLATION:
-------------
1. Extract the tar.gz into your 'modules' or directory.
2. Enable the module at 'administer >> site building >> modules'.
3. The module will automatically replace the path to your 404 page with
   "search404".

CONFIGURATION
-------------
1. Visit 'administer >> site configuration >> search 404 settings'
2. For multilingual sites, enable i18n, i18n_variable and its dependencies.
3. Visit admin/config/regional/i18n/variable and enable the 2 variables for
   multilingual.
4. Translate the variables from step 1.

UNINSTALLATION:
--------------
1. Disable the module.
2. Uninstall the module, which will blank the the 404 page.

CREDITS:
--------
Written by Lars Sehested Geisler <drupal@larsgeisler.dk>
Maintained by Zyxware, http://www.zyxware.com/
Some code from Steven (found at http://drupal.org/node/12668)
Originally maintained by Johan Forngren, http://johan.forngren.com/
