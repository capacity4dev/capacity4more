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
      echo -e  "${BGRED}    directory of the ${BGLRED}install${BGRED} script.                             ${RESTORE}"
      echo -e  "${BGRED}  > If not create one by creating a copy of ${BGLRED}default.config.sh${BGRED}.   ${RESTORE}"
      echo -e  "${BGRED}                                                                 ${RESTORE}"
      echo
      exit 1
  fi

  # Include the configuration file.
  source $ROOT/config.sh
}


##
# Cleanup the sites/default/ directory:
# - Removes the files directory.
# - Removes the settings.php file.
#
# Uses (requests) sudo powers if needed!
##
function delete_sites_default_content {
  NEEDS_SUDO=0

  # Cleanup the www/sites/default content.
  if [ -d $ROOT/www/sites ]; then
    echo -e "${LBLUE}> Cleaning up the sites/default directory${RESTORE}"
    chmod 777 $ROOT/www/sites/default
    rm -rf $ROOT/www/sites/default/files || { NEEDS_SUDO=1; }
    rm -f $ROOT/www/sites/default/settings.php || { NEEDS_SUDO=1; }
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
# Cleanup the profile/ directory:
# - Remove contributed modules (modules/contrib).
# - Remove development modules (modules/development).
# - Remove contributed themes (themes/contrib).
# - Remove libraries (libraries).
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
# Cleanup the profile/themes/c4m directory:
# - Remove bootstrap library
# - Remove sass cache
# - Remove node_modules (npm install)
# - Remove css folder
##
function delete_profile_dist {
  # Cleanup the bootstrap library.
  PATH_THEME_BOOTSTRAP="$ROOT/$PROFILE_NAME/themes/c4m/kapablo/bootstrap"
  if [ -d $PATH_THEME_BOOTSTRAP ]; then
    echo -e "${LBLUE}> Cleaning up the $PATH_THEME_BOOTSTRAP directory${RESTORE}"
    rm -rf $PATH_THEME_BOOTSTRAP
    echo
  fi

  # Cleanup the npm modules.
  PATH_THEME_NODE_MODULES="$ROOT/build/themes/kapablo/node_modules"
  if [ -d $PATH_THEME_NODE_MODULES ]; then
    echo -e "${LBLUE}> Cleaning up the $PATH_THEME_NODE_MODULES directory${RESTORE}"
    rm -rf $PATH_THEME_NODE_MODULES
    echo
  fi

  # Cleanup the sass cache.
  PATH_THEME_SASS_CACHE="$ROOT/build/themes/kapablo/.sass-cache"
  if [ -d $PATH_THEME_SASS_CACHE ]; then
    echo -e "${LBLUE}> Cleaning up the $PATH_THEME_SASS_CACHE directory${RESTORE}"
    rm -rf $PATH_THEME_SASS_CACHE
    echo
  fi

  # Cleanup the css folder.
  PATH_THEME_CSS="$ROOT/$PROFILE_NAME/themes/c4m/kapablo/css"
  if [ -d $PATH_THEME_CSS ]; then
    echo -e "${LBLUE}> Cleaning up the $PATH_THEME_CSS directory${RESTORE}"
    rm -rf $PATH_THEME_CSS
    echo
  fi
}



##
# Delete all the content within the /www folder.
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

  # Create the www directory if necessary.
  if [ ! -d $ROOT/www ]; then
    echo -e "${LBLUE}> Creating an empty www directory${RESTORE}"
    mkdir $ROOT/www
    echo
  fi
}


##
# Download & extract Drupal core + contrib based on the make files.
##
function drupal_make {
  echo -e "${LBLUE}> Run the build script (scripts/build)${RESTORE}"
  bash $ROOT/scripts/build
  echo
}

##
# Delete obsolete folders, like the plupload examples folder.
##
function delete_obsolete_folders {
  # Cleanup the sass cache
  if [ -d $ROOT/$PROFILE_NAME/libraries/plupload/examples ]; then
    echo -e "${LBLUE}> Delete obsoletely downloaded plupload/examples folder.${RESTORE}"
    rm -rf $ROOT/$PROFILE_NAME/libraries/plupload/examples
    echo
  fi
}

##
# Install the profile as configured in the config.sh file.
##
function install_drupal_profile {
  echo -e "${LBLUE}> Install Drupal with the $PROFILE_NAME install profile${RESTORE}"

  cd $ROOT/www
  drush si -y $PROFILE_NAME \
    --locale=en \
    --site-name=$PROFILE_NAME \
    --account-name=$ADMIN_USERNAME \
    --account-pass=$ADMIN_PASSWORD \
    --account-mail=$ADMIN_EMAIL \
    --db-url=mysql://$MYSQL_USERNAME:$MYSQL_PASSWORD@$MYSQL_HOSTNAME/$MYSQL_DB_NAME \
    --uri=$BASE_DOMAIN_URL
  echo

  echo -e "${LBLUE}> Disable the update module as it slows down admin access${RESTORE}"
  drush -y dis update
  echo

  cd $ROOT
}


##
# Create (if not exists) and set the proper file permissions
# on the sites/default/files directory.
##
function create_sites_default_files_directory {
  if [ ! -d $ROOT/www/sites/default/files ]; then
    echo -e "${LBLUE}> Create the files directory (sites/default/files directory)${RESTORE}"
    mkdir -p $ROOT/www/sites/default/files
  fi

  echo -e "${LBLUE}> Set the file permissions on the sites/default/files directory${RESTORE}"
  chmod -R 777 $ROOT/www/sites/default/files
  umask 000 $ROOT/www/sites/default/files
  chmod -R g+s $ROOT/www/sites/default/files
  echo
}


##
# Enable the development modules.
##
function enable_development_modules {
  echo -e "${LBLUE}> Enabling the development modules${RESTORE}"
  cd $ROOT/www
  drush en -y devel views_ui field_ui migrate_ui context_ui
  cd $ROOT
  echo
}


##
# Do dummy content migration.
##
function migrate_dummy_content {
  echo -e "${LBLUE}> Importing dummy data${RESTORE}"
  cd $ROOT/www
  drush en -y migrate migrate_ui c4m_demo_content
  drush --uri="http://$BASE_DOMAIN_URL" mi --force --update --group=c4m_demo_content
  cd $ROOT
  echo
}


##
# Fill string with spaces until required length.
#
# @param string The string.
# @param int The requested total length.
##
function fill_string_spaces {
  STRING="$1"
  STRING_LENGTH=${#STRING}
  SPACES_LENGTH=$(($2-$STRING_LENGTH))

  if [[ "0" -gt "SPACES_LENGTH" ]]; then
    SPACES_LENGTH=0
  fi

  printf -v SPACES '%*s' $SPACES_LENGTH
  echo "$STRING$SPACES"
}


##
# Login to Drupal as Administrator using the one time login link.
#
# This command does the login for you when the build script is done.
# It will open a new tab in your default browser and login to your project as
# the Administrator.
##
function drupal_login {
  cd www
  drush uli --uri=$BASE_DOMAIN_URL
  cd ..
}

##
# Symlink external folders into www folder.
#
# This will use the SYMLINKS array from the config.sh file and create
# the symlinks relative to the www folder in the folder structure.
##
function symlink_externals {
  echo -e "${LBLUE}> Symlinking external directories & files${RESTORE}"
  if [ ${#SYMLINKS[@]} -eq 0 ]; then
    echo "No directories or files to symlink."
    return 0
  fi

  # Loop trough the symlinks configuration.
  for SOURCETARGET in "${SYMLINKS[@]}"; do
    paths=($(echo $SOURCETARGET | tr ">" "\n"))
    path_source=${paths[0]}
    path_target="$ROOT/www/${paths[1]}"
    basepath_target=${path_target%/*}

    # check if the source exists
    if [ ! -e "$path_source" ] && [ ! -L "$path_source" ]; then
      echo "Source does not exists"
      echo "  ($path_source)"
      continue
    fi

    # Check if the target does not exist.
    if [ -e "$path_target" ] || [ -L "$path_target" ]; then
      echo "Target already exists"
      echo "  ($path_target)"
      continue
    fi

    # create basepath of the target if does not already exists.
    if [ ! -d "$basepath_target" ]; then
      mkdir -p "$basepath_target"
    fi

    # Create the symlink
    ln -s "$path_source" "$path_target"
    echo "Created symlink for $path_source"
    echo "  > as $path_target"

  done
  echo
}

##
# Helper to define if a function exists
#
# @see http://stackoverflow.com/questions/85880/determine-if-a-function-exists-in-bash
##
function fn_exists() {
  # appended double quote is an ugly trick to make sure we do get a string.
  # If $1 is not a known command, type does not output anything.
  [ `type -t $1`"" == 'function' ]
}

##
# Check if there is a post script and run it.
#
# @param string $1
#   The kind of post script to run.
##
function run_post_script {
  if [ ! "$1" ]; then
    return 0
  fi

  # Define post script name.
  POST_FUNCT_NAME="post_$1"

  # Check if the function is declared.
  if ! fn_exists $POST_FUNCT_NAME; then
    return 0
  fi

  # Run the post script.
  echo -e "${LBLUE}> Run $POST_FUNCT_NAME script.${RESTORE}"
  $POST_FUNCT_NAME
  echo
}

##
# Build the javascript dependencies
##
function build_angular_app {
  echo -e "${LBLUE}> Build dependencies & AngularJs App.${RESTORE}"

  # Build the dependencies.
  cd $ROOT/capacity4more/modules/c4m/restful/c4m_restful_quick_post/components/c4m-app
  npm install
  grunt build --show-parser-errors
  cd $ROOT

  # Install angular components via bower.
  bower cache clean
  bower install $ROOT/capacity4more/modules/c4m/restful/c4m_restful_quick_post/components/c4m-app

  echo
}

##
# Build the Kapablo theme dependencies
##
function build_kapablo_theme {
  echo -e "${LBLUE}> Build dependencies for Kapablo theme.${RESTORE}"

  # Build the dependencies.
  cd $ROOT/build/themes/kapablo
  bundle install
  npm install
  grunt build
  cd $ROOT

  echo
}

##
# Overwrite the TIKA config (if needed).
##
function install_tika_config {
  cd "$ROOT/www"

  if [ -n "$TIKA_PATH" ]; then
    drush vset search_api_attachments_tika_path "$TIKA_PATH"
  fi
  if [ -n "$TIKA_FILE" ]; then
    drush vset search_api_attachments_tika_jar "$TIKA_FILE"
  fi

  cd "$ROOT"
}
