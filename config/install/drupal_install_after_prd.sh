# Update settings file ---------------------------------------------------------
markup_h1 "Update settings.php file"

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
\$conf["cache_backends"][] = "sites/all/modules/memcache/memcache.inc";
\$conf["lock_inc"] = "sites/all/modules/memcache/memcache-lock.inc";
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