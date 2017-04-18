################################################################################
# This script will copy the Drupal configuration files to the sites folder.
################################################################################

##
# Symlink the config.inc and the config.ENVIRONMENT.inc files.
##
function drupal_sites_default_config_link {
  if [ -d "$DIR_WEB/sites/default" ]; then
    if [ -f "$DIR_CONFIG/drupal/config.inc" ]; then
      ln -sf "$DIR_CONFIG/drupal/config.inc" "$DIR_WEB/sites/default/config.inc"
    fi

    if [ -f "$DIR_CONFIG/drupal/config.$ENVIRONMENT.inc" ]; then
      ln -sf "$DIR_CONFIG/drupal/config.$ENVIRONMENT.inc" "$DIR_WEB/sites/default/config.local.inc"
    fi
  fi
}

##
# Symlink the config.$ENVIRONMENT.override.inc file to config.local.override.inc in the WEB-directory.
##
function drupal_sites_default_config_override_link {
  if [ -d "$DIR_WEB/sites/default" ]; then
    if [ -f "$DIR_CONFIG/drupal/config.$ENVIRONMENT.override.inc" ]; then
      ln -sf "$DIR_CONFIG/drupal/config.$ENVIRONMENT.override.inc" "$DIR_WEB/sites/default/config.local.override.inc"
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

  if [ -f "$DIR_WEB/sites/default/config.local.override.inc" ]; then
    chmod a-w "$DIR_WEB/sites/default/config.local.override.inc"
  fi
}