################################################################################
# Functionality to migrate the migrate content.
################################################################################

##
# Migrate migrate content.
##
function migrate_content {
  pre_migrate
  migrate_content_migrate
  post_migrate
}

##
# Enable migration modules.
##
function pre_migrate {
  drupal_drush --uri="$SITE_URL" dis -y c4m_demo
  drupal_drush --uri="$SITE_URL" dis -y admin_menu
  drupal_drush --uri="$SITE_URL" en -y c4d_migrate
  drupal_drush --uri="$SITE_URL" en -y toolbar
  drupal_drush --uri="$SITE_URL" search-api-disable -y c4m_search_nodes
  drupal_drush --uri="$SITE_URL" search-api-disable -y c4m_search_users
}

function post_migrate {
  drupal_drush --uri="$SITE_URL" search-api-enable -y c4m_search_nodes
  drupal_drush --uri="$SITE_URL" search-api-enable -y c4m_search_users
  drupal_drush --uri="$SITE_URL" drush vset maintenance_mode 1
  drupal_drush --uri="$SITE_URL" vset restful_skip_basic_auth 1
  mv "$DIR_WEB/cron.php" "$DIR_WEB/cron-disabled.php"
  drupal_drush --uri="$SITE_URL" search-api-index c4m_search_nodes && drupal_drush --uri="$SITE_URL" search-api-index c4m_search_users
  mv "$DIR_WEB/cron-disabled.php" "$DIR_WEB/cron.php"
  drupal_drush --uri="$SITE_URL" vset maintenance_mode 0
}

##
# Execute migrate migration.
##
function migrate_content_migrate {
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

  # Comments
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportCommentArticle
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportCommentOGDocument
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportCommentOGMinisite
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportCommentOGDiscussion
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportCommentOGEvent
  drupal_drush --uri="$SITE_URL" mi --instrument --feedback="30 seconds" C4dMigrateImportCommentOGPhotoalbum
}