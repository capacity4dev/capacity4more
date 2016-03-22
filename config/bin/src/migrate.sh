################################################################################
# Functionality to migrate the migrate content.
################################################################################

##
# Migrate migrate content.
##
function migrate_content {
  migrate_content_modules
  migrate_content_migrate
}

##
# Enable migration modules.
##
function migrate_content_modules {
  drupal_drush --uri="$SITE_URL" dis -y c4m_demo
  drupal_drush --uri="$SITE_URL" dis -y admin_menu
  drupal_drush --uri="$SITE_URL" en -y c4d_migrate
  drupal_drush --uri="$SITE_URL" en -y toolbar
}


##
# Execute migrate migration.
##
function migrate_content_migrate {
  if [ "$CODER_DISABLED" = "1" ]; then
    markup_warning "drupal/coder is disabled."
    markup_info "Enable it by setting CODER_DISABLED=0 in config/config.sh."
    echo
    return
  fi

  # Make sure that migrate detected all migration scripts.
  drupal_drush --uri="$SITE_URL" ms
  echo


  # Users & Roles
  echo "Users & Roles"
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportRoles
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportUsers
  echo

  # Topics
  echo "Topics"
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateCreateCSVTermTopic

  # Content outside groups
  echo "Content outside groups"
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportNodeArticle
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportNodeBookPage
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportNodeHelpPage

  # Organisations
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateCreateCSVNodeOrganisations

  # Groups & Projects
  echo "Groups & Projects"
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportNodeGroup
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportNodeProject
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportOGFeatures
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportOGMemberships
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportOGUserRoles

  # Group & Project vocabularies
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportVocabOGCategories
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportVocabOGTags

  # Topics nodes
  echo "Content types that need Groups"
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportNodeTopic
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportNodeFeed


  # Content inside groups
  echo "Content within Groups & Projects"
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportNodeOGDocument
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportNodeOGMinisite
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportNodeOGDiscussion
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportNodeOGEvent
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportNodeOGPhotoalbum
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportNodeOGPhoto
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportNodeOGTasklist
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportNodeOGTask

  # Comments
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportCommentArticle
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportCommentOGDocument
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportCommentOGMinisite
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportCommentOGDiscussion
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportCommentOGEvent
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportCommentOGPhotoalbum
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportCommentOGTask
}