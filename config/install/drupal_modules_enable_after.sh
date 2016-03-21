################################################################################
# Use this file to add custom script steps that should run after the
# installation of Drupal and its contrib modules has finished.
################################################################################

# Make sure that we are in the Drupal root.
cd "$DIR_WEB"

# Make the default directory and its content writable.
markup_h1 "Make the sites/default directory and its content writable."
drupal_sites_default_unprotect
echo

# Set the administration theme.
markup_h1 "Set the administration menu"
drush vset admin_theme adminimal
echo
