
################################################################################
# Use this file to add custom script steps that should run after the
# installation of Drupal and its contrib modules has finished.
################################################################################

# Make sure that we are in the Drupal root.
cd "$DIR_WEB"


# Make the default directory and its content writable.
markup_h1 "Make the sites/default directory and its content writable."
chmod -R u+w "$DIR_WEB/sites/default"
echo


# Enable the theme debugging.
markup_h1 "Enable theme debugging"
drupal_drush vset theme_debug 1
echo
