################################################################################
# Use this file to add custom script steps that should run before the
# installation of Drupal is started.
################################################################################

# Upgrade needs to symlink the same custom modules as the installation.
source "$DIR_CONFIG/install/drupal_make_after.sh"
