#!/bin/bash

################################################################################
#
# Helper functions so we can reuse code indifferent scripts!
#
################################################################################

##
# Load the configuration file.
# Will exit with an error message if the configuration file does not exists!
##
function load_config_file {

  # Check if the config file exists.
  if [ ! -f $ROOT/config.sh ]; then
    echo
      echo -e  "${BGRED}                                                                 ${RESTORE}"
      echo -e "${BGLRED}  ERROR: No configuration file found!                            ${RESTORE}"
      echo -e  "${BGRED}  > Check if the ${BGLRED}config.sh${BGRED} file exists in the same               ${RESTORE}"
      echo -e  "${BGRED}    directory of the ${BGLRED}install.sh${BGRED} script.                          ${RESTORE}"
      echo -e  "${BGRED}  > If not create one by creating a copy of ${BGLRED}default.config.sh${BGRED}.   ${RESTORE}"
      echo -e  "${BGRED}                                                                 ${RESTORE}"
      echo
      exit 1
  fi

  # Include the configuration file.
  source $ROOT/config.sh
}



##
# Cleanup the sites/default/ directory
# - Removes the files directory
# - Removes the settings.php file
#
# Uses (requests) sudo powers if needed!
##
function delete_sites_default_content {
  # Cleanup the www/sites/default content.
  if [ -d $ROOT/www/sites ]; then
    echo -e "${LBLUE}> Cleaning up the sites/default directory${RESTORE}"

    chmod 777 $ROOT/www/sites/default
    rm -rf $ROOT/www/sites/default/files
    rm -f $ROOT/www/sites/default/settings.php

    echo
  fi

  # Backup in case of we need sudo powers to get rid of the files directory.
  if [ -d $ROOT/www/sites/default/files ]; then
    echo -e "${LBLUE}> Cleaning up the sites/default/files directory with sudo power!${RESTORE}"

    sudo rm -rf $ROOT/www/sites/default/files

    echo
  fi

  # Backup in case of we need sudo powers to get rid of the settings.php directory.
  if [ -f $ROOT/www/sites/default/settings.php ]; then
    echo -e "${LBLUE}> Cleaning up the sites/default/settings.php file with sudo power!${RESTORE}"

    sudo rm -rf $ROOT/www/sites/default/settings.php

    echo
  fi
}

##
# Cleanup the profile/ directory
# - Remove contributed modules (modules/contrib)
# - Remove development modules (modules/development)
# - Remove contributed themes (themes/contrib)
# - Remove libraries (libraries)
##
function delete_profile_contrib {
  # Cleanup the contrib modules
  if [ -d $ROOT/$PROFILE_NAME/modules/contrib ]; then
    echo -e "${LBLUE}> Cleaning up the $PROFILE_NAME/modules/contrib directory${RESTORE}"

    rm -rf $ROOT/$PROFILE_NAME/modules/contrib

    echo
  fi

  # Cleanup the development modules
  if [ -d $ROOT/$PROFILE_NAME/modules/development ]; then
    echo -e "${LBLUE}> Cleaning up the $PROFILE_NAME/modules/development directory${RESTORE}"

    rm -rf $ROOT/$PROFILE_NAME/modules/development

    echo
  fi

  # Cleanup the contrib themes
  if [ -d $ROOT/$PROFILE_NAME/themes/contrib ]; then
    echo -e "${LBLUE}> Cleaning up the $PROFILE_NAME/themes/contrib directory${RESTORE}"

    rm -rf $ROOT/$PROFILE_NAME/themes/contrib

    echo
  fi

  # Cleanup the libraries folder
  if [ -d $ROOT/$PROFILE_NAME/libraries ]; then
    echo -e "${LBLUE}> Cleaning up the $PROFILE_NAME/libraries directory${RESTORE}"

    rm -rf $ROOT/$PROFILE_NAME/libraries

    echo
  fi
}

##
# Delete all the content within the /www folder
##
function delete_www_content {
  if [ -d $ROOT/www/sites/default ]; then
    chmod 777 $ROOT/www/sites/default
  fi

  if [ -d $ROOT/www/sites ]; then
    echo -e "${LBLUE}> Cleaning up the www directory${RESTORE}"

    rm -rf $ROOT/www/

    echo
  fi

  # Create the www directory if necessary
  if [ ! -d $ROOT/www ]; then
    echo -e "${LBLUE}> Creating an empty www directory${RESTORE}"

    mkdir $ROOT/www

    echo
  fi
}






##
# Install the profile as configured in the config.sh file
##
function install_drupal_profile {
  echo -e "${LBLUE}> Install Drupal with the $PROFILE_NAME install profile${RESTORE}"

  cd $ROOT/www
  drush si -y $PROFILE_NAME \
    --locale=en \
    --account-name=$ADMIN_USERNAME \
    --account-pass=$ADMIN_PASSWORD \
    --account-mail=$ADMIN_EMAIL \
    --db-url=mysql://$MYSQL_USERNAME:$MYSQL_PASSWORD@$MYSQL_HOSTNAME/$MYSQL_DB_NAME \
    --uri=$BASE_DOMAIN_URL

  cd $ROOT

  echo
}


##
# Create (if not exists) and set the proper file permissions
# on the sites/default/files directory
##
function create_sites_default_files_directory {
  if [ ! -d $ROOT/www/sites/default/files ]; then
    echo -e "${LBLUE}> Create the files directory (sites/default/files directory)${RESTORE}"

    mkdir -p $ROOT/www/sites/default/files
  fi

  echo -e "${LBLUE}> Set the file permissions on the sites/default/files directory${RESTORE}"

  chmod -R 775 $ROOT/www/sites/default/files
  umask 002 $ROOT/www/sites/default/files
  chmod -R g+s $ROOT/www/sites/default/files

  echo
}


##
# Enable the development modules
##
function enable_development_modules {
  echo -e "${LBLUE}> Enabling the development modules${RESTORE}"

  cd $ROOT/www
  drush en -y devel views_ui field_ui migrate_ui
  cd $ROOT

  echo
}

