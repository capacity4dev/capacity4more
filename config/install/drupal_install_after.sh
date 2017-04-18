# Write config to settings file.
markup_h1 "Write config to settings file."
drupal_sites_default_unprotect

cat << EOF >> "$DIR_WEB/sites/default/settings.php"

/**
 * Include configuration files to override or complement
 * the configuration above.
 ******************************************************************************/
\$settings_path = dirname(__FILE__);

\$files = array(
  \$settings_path . '/config.inc',
  \$settings_path . '/config.local.inc',
);

foreach (\$files as \$filename) {
  if (file_exists(\$filename)) {
    include \$filename;
  }
}

EOF

source "$DIR_CONFIG/install/drupal_install_config.sh"

markup_h1 "Copy config files and protect them."
drupal_sites_default_config_link
drupal_sites_default_config_protect
echo

drupal_sites_default_protect

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

if [ "$PIWIK_SITE_ID" != "" ] && [ "$PIWIK_URL_HTTP" != "" ]; then
  # Set Piwik Web Analytics related variables.
  markup_h1 "Set Piwik Web Analytics related variables"
  php -r "print json_encode(array('piwik_site_id' => '$PIWIK_SITE_ID', 'piwik_url_http' => '$PIWIK_URL_HTTP', 'piwik_url_https' => '$PIWIK_URL_HTTPS'));"
  drupal_drush vset piwik_site_id "$PIWIK_SITE_ID"
  drupal_drush vset piwik_url_http "$PIWIK_URL_HTTP"
  if [ "$PIWIK_URL_HTTPS" != "" ]; then
    drupal_drush vset piwik_url_https "$PIWIK_URL_HTTPS"
  fi
  echo
fi
