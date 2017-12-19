# Update settings file ---------------------------------------------------------
markup_h1 "Update settings.php file"

# Write Apache Solr config to settings file.
markup_debug "SOLR Host : ${SOLR_HOST}"
markup_debug "SOLR Port : ${SOLR_PORT}"
markup_debug "SOLR Path : ${SOLR_PATH}"

if [ "$SOLR_HOST" != "" ] && [ "$SOLR_PORT" != "" ] && [ "$SOLR_PATH" != "" ]; then
  drupal_sites_default_unprotect
  cat << EOF >> "$DIR_WEB/sites/default/settings.php"

/**
 * Solr config settings.
 */
\$conf["c4m_search_server_overrides"] = array(
  'c4m_solr' => array(
    'name' => t('Solr Server'),
    'options' => array(
      'host' => "$SOLR_HOST",
      'port' => "$SOLR_PORT",
      'path' => "$SOLR_PATH",
    ),
  ),
);
EOF
  drupal_sites_default_protect
  message_success "Solr configuration added."
else
  message_warning "No Solr configuration to write."
fi

# Write TIKA config to the settings file.
markup_debug "File path : ${TIKA_PATH}"
markup_debug "File file : ${TIKA_FILE}"

if [ "$TIKA_PATH" != "" ] && [ "$TIKA_FILE" != "" ]; then
  drupal_sites_default_unprotect
  cat << EOF >> "$DIR_WEB/sites/default/settings.php"

/**
 * TIKA config settings.
 */
\$conf["search_api_attachments_tika_path"] = "$TIKA_PATH";
\$conf["search_api_attachments_tika_jar"] = "$TIKA_FILE";

EOF
  drupal_sites_default_protect
  message_success "TIKA configuration added."
else
  message_warning "No TIKA configuration to write."
fi

# Write Memchached settings to config file.
markup_debug "HOST : ${MEMCACHE_HOST}"
markup_debug "PORT : ${MEMCACHE_PORT}"

if [ "$MEMCACHE_HOST" != "" ] && [ "$MEMCACHE_PORT" != "" ]; then
  drupal_sites_default_unprotect
  cat << EOF >> "$DIR_WEB/sites/default/settings.php"
/**
 * Memcache settings
 */
// Memcache settings.
\$conf["cache_backends"][] = "sites/all/modules/contrib/memcache/memcache.inc";
\$conf["lock_inc"] = "sites/all/modules/contrib/memcache/memcache-lock.inc";
\$conf["memcache_stampede_protection"] = TRUE;
\$conf["cache_default_class"] = "MemCacheDrupal";

// The "cache_form" bin must be assigned to non-volatile storage.
\$conf["cache_class_cache_form"] = "DrupalDatabaseCache";

// Don\'t bootstrap the database when serving pages from the cache.
\$conf["page_cache_without_database"] = TRUE;
\$conf["page_cache_invoke_hooks"] = FALSE;

// Memcache servers.
\$conf["memcache_servers"] = array("${MEMCACHE_HOST}:${MEMCACHE_PORT}" => "default");

EOF
  drupal_sites_default_protect
  message_success "Memcache configuration added."
else
  message_warning "No memcache configuration to write."
fi

markup

# Write migration config to settings file.
if [ "$MIGRATION_DB" != "" ] && [ "$MIGRATION_HOST" != "" ] && [ "$MIGRATION_USER" != "" ] && [ "$MIGRATION_PASS" != "" ] && [ "$MIGRATION_FILES" != "" ]; then
  drupal_sites_default_unprotect
  cat << EOF >> "$DIR_WEB/sites/default/settings.php"

/**
 * Migration settings (c4d source).
 */
\$conf["c4d_migrate_db_hostname"] = "${MIGRATION_HOST}";
\$conf["c4d_migrate_db_database"] = "${MIGRATION_DB}";
\$conf["c4d_migrate_db_username"] = "${MIGRATION_USER}";
\$conf["c4d_migrate_db_password"] = "${MIGRATION_PASS}";
\$conf["c4d_migrate_files_root"] = "${MIGRATION_FILES}";

EOF
  drupal_sites_default_protect
  message_success "Migration configuration added."
else
  message_warning "No migration configuration to write."
fi

markup

# /END Update settings file ----------------------------------------------------

drupal_drush vset file_public_path "$FILE_PATH_PUBLIC"
drupal_drush vset file_private_path "$FILE_PATH_PRIVATE"
drupal_drush vset file_temporary_path "$FILE_PATH_TEMP"
drupal_drush vset file_default_scheme "$FILE_PATH_DEFAULT_METHOD"

# Execute dummy content migration.
migrate_content=$( option_is_set "--migrate-content" )
if [ $migrate_content -eq 1 ]; then
  markup_h1 "Install migrated content."
  source "$DIR_CONFIG_SRC/migrate.sh"
  migrate_content
fi

# Execute dummy content migration.
dummy_content=$( option_is_set "--dummy-content" )
if [ $dummy_content -eq 1 ]; then
  markup_h1 "Install dummy demo content."
  source "$DIR_CONFIG_SRC/dummy.sh"
  dummy_content
fi

if [ "$CAMPAIGNMONITOR_CLIENT_ID" != "" ] && [ "$CAMPAIGNMONITOR_API_KEY" != "" ]; then
  # Set campaign monitor related variables.
  markup_h1 "Set campaign monitor related variables"
  php -r "print json_encode(array('client_id' => '$CAMPAIGNMONITOR_CLIENT_ID', 'api_key' => '$CAMPAIGNMONITOR_API_KEY'));" | drupal_drush vset --format=json campaignmonitor_account -
  drupal_drush vset campaignmonitor_list_title "$CAMPAIGNMONITOR_LIST_TITLE"
  echo
fi

if [ "$LDAP_URL" != "" ] && [ "$LDAP_API" != "" ]; then
  # Set LDAP configuration.
  markup_h1 "Set LDAP configuration"
  php -r "print json_encode(array('client_id' => '$LDAP_URL', 'api_key' => '$LDAP_API'));"
  drupal_drush vset c4m_ldap_url "$LDAP_URL"
  drupal_drush vset c4m_ldap_apikey "$LDAP_API"
  echo
fi

if [ "$PIWIK_SITE_ID" != "" ] && [ "$PIWIK_SITE_PATH" != "" ] && [ "$PIWIK_SITE_INSTANCE" != "" ]; then
  # Set Piwik Web Analytics related variables.
  markup_h1 "Set Piwik Web Analytics related variables"
  php -r "print json_encode(array('piwik_site_id' => '$PIWIK_SITE_ID', 'piwik_site_path' => '$PIWIK_SITE_PATH', 'piwik_site_instance' => '$PIWIK_SITE_INSTANCE'));"
  drupal_drush vset nexteuropa_piwik_site_id "$PIWIK_SITE_ID"
  drupal_drush vset nexteuropa_piwik_site_path "$PIWIK_SITE_PATH"
  drupal_drush vset nexteuropa_piwik_site_instance "$PIWIK_SITE_INSTANCE"

  echo
fi
