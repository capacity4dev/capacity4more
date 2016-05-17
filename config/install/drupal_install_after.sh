source "$DIR_CONFIG/install/drupal_install_config.sh"

markup_h1 "Create settings.php file."
drupal_sites_default_create_settings

markup_h1 "Copy config files and protect them."
drupal_sites_default_config_link
drupal_sites_default_config_protect
echo

drupal_sites_default_protect

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
