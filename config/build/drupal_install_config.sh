################################################################################
# This script will copy the Drupal configuration files to the sites folder.
################################################################################

##
# Create settings.php with appropriate includes.
##
function drupal_sites_default_create_settings {
  if [ -d "$DIR_WEB/sites/default" ]; then
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
  fi
}

##
# Copy the config.inc and the config.ENVIRONMENT.inc files.
##
function drupal_sites_default_config_copy {
  if [ -d "$DIR_WEB/sites/default" ]; then
    if [ -f "$DIR_CONFIG/drupal/config.inc" ]; then
      cp -f "$DIR_CONFIG/drupal/config.inc" "$DIR_WEB/sites/default/config.inc"
    fi

    if [ -f "$DIR_CONFIG/drupal/config.$ENVIRONMENT.inc" ]; then
      cp -f "$DIR_CONFIG/drupal/config.$ENVIRONMENT.inc" "$DIR_WEB/sites/default/config.local.inc"
    fi
  fi
}

##
# Restore the protection of the config files in the sites/default directory.
##
function drupal_sites_default_config_protect {
  if [ -f "$DIR_WEB/sites/default/config.inc" ]; then
    chmod a-w "$DIR_WEB/sites/default/config.inc"
  fi

  if [ -f "$DIR_WEB/sites/default/config.local.inc" ]; then
    chmod a-w "$DIR_WEB/sites/default/config.local.inc"
  fi
}
