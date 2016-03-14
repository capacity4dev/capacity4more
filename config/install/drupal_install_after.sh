# Build the theme files.
markup_h1 "Build the Theme."
source "$DIR_CONFIG_SRC/theme_build.sh"
theme_build build
echo

# Build the Angular app.
markup_h1 "Build the Angular app."
source "$DIR_CONFIG_SRC/angular_build.sh"
angular_build build
echo

# Update settings file ---------------------------------------------------------
markup_h1 "Update settings.php file"

# Write Apache Solr config to settings file.
markup_debug "SOLR Host : ${SOLR_HOST}"
markup_debug "SOLR Port : ${SOLR_PORT}"
markup_debug "SOLR Path : ${SOLR_PATH}"

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
# /END Update settings file ----------------------------------------------------

# Write reCaptcha config to settings file.
if [ "$RECAPTCHA_SITE_KEY" != "" ] && [ "$RECAPTCHA_SECRET_KEY" != "" ]; then
  drupal_sites_default_unprotect
  cat << EOF >> "$DIR_WEB/sites/default/settings.php"

/**
 * reCapthca settings.
 */
\$conf["recaptcha_site_key"] = "${RECAPTCHA_SITE_KEY}";
\$conf["recaptcha_secret_key"] = "${RECAPTCHA_SECRET_KEY}";

EOF
  drupal_sites_default_protect
  message_success "reCaptcha configuration added."
else
  message_warning "No reCaptcha configuration to write."
fi
