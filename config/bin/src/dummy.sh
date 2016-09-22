################################################################################
# Functionality to migrate the dummy content.
################################################################################

##
# Migrate dummy content.
##
function dummy_content {
  dummy_content_modules
  dummy_content_migrate
}

##
# Enable migration modules.
##
function dummy_content_modules {
  drupal_drush --uri="$SITE_URL" en -y migrate c4m_demo_content
}

##
# Execute dummy migration.
##
function dummy_content_migrate {
  drupal_drush --uri="$SITE_URL" mi --force --update --group=c4m_demo_content
}
