################################################################################
# Functionality to deploy the website to a remote location.
################################################################################

##
# Run the deploy init function to check and create variables.
##
function deploy_init {
  # Check first if the configuration is set.
  deploy_check_config

  # Create the variables used by the build script.
  deploy_variables
}

##
# Show the deploy info block.
##
function deploy_info {
  echo
  markup_h1_divider
  markup_h1 " ${LWHITE}Deploy${LBLUE} website ${WHITE}$SITE_NAME${LBLUE} ($ENVIRONMENT)"
  markup_h1_divider
  markup_h1 " The site will be upgraded from:"
  markup_h1_li "${WHITE}${DEPLOY_VERSION_CURRENT}"
  markup_h1
  markup_h1 " The site will be upgraded using:"
  markup_h1_li "Branch : ${WHITE}${DEPLOY_BRANCH}"
  markup_h1_li "Commit : ${WHITE}${DEPLOY_HASH_LONG}${LBLUE} (${DEPLOY_HASH_SHORT})"
  markup_h1_divider
  echo
}

##
# Show the confirmation dialogue.
##
function deploy_confirm {
  if [ $CONFIRMED -ne 1 ]; then
    read -p "Are you sure? (y/N) " -n 1 -r
    echo

    if [[ ! $REPLY =~ ^[Yy]$ ]]; then
      markup_warning "! Deployment aborted"
      echo
      exit 1
    fi
    echo
  fi
}

##
# Deploy the website.
##
function deploy_run {
  # Build the platform.
  deploy_build

  # Move the build package to the remote environment.
  deploy_package

  # Deploy the website.
  deploy_site
}



## CONFIG & VARIABLES ##########################################################

##
# Check if the necessary configuration variables are set.
##
function deploy_check_config {
  DEPLOY_CHECK_CONFIG_ERRORS=()

  markup_debug
  markup_debug "CONFIG VARIABLES"
  markup_debug "$(markup_divider)"

  # Environment
  DEPLOY_ENVIRONMENT="$(option_get_environment | awk '{print toupper($0)}')"
  markup_debug "ENVIRONMENT : ${DEPLOY_ENVIRONMENT}"

  # Connection
  DEPLOY_HOST=$(deploy_get_config_variable "HOST")
  deploy_check_config_variable "HOST" "$DEPLOY_HOST"
  markup_debug "HOST : ${DEPLOY_HOST}"

  DEPLOY_PORT=$(deploy_get_config_variable "PORT")
  deploy_check_config_variable "PORT" "$DEPLOY_PORT"
  markup_debug "PORT : ${DEPLOY_PORT}"

  DEPLOY_USER=$(deploy_get_config_variable "USER")
  deploy_check_config_variable "USER" "$DEPLOY_USER"
  markup_debug "USER : ${DEPLOY_USER}"

  # Paths.
  DEPLOY_PATH_BACKUPS=$(deploy_get_config_variable "PATH_BACKUPS")
  deploy_check_config_variable "PATH_BACKUPS" "$DEPLOY_PATH_BACKUPS"
  markup_debug "PATH_BACKUPS : ${DEPLOY_PATH_BACKUPS}"

  DEPLOY_PATH_DRUSH=$(deploy_get_config_variable "PATH_DRUSH")
  deploy_check_config_variable "PATH_DRUSH" "$DEPLOY_PATH_DRUSH"
  markup_debug "PATH_DRUSH : ${DEPLOY_PATH_DRUSH}"

  DEPLOY_PATH_HTDOCS=$(deploy_get_config_variable "PATH_HTDOCS")
  deploy_check_config_variable "PATH_HTDOCS" "$DEPLOY_PATH_HTDOCS"
  markup_debug "PATH_HTDOCS : ${DEPLOY_PATH_HTDOCS}"

  DEPLOY_PATH_SITES_DEFAULT=$(deploy_get_config_variable "PATH_SITES_DEFAULT")
  deploy_check_config_variable "PATH_SITES_DEFAULT" "$DEPLOY_PATH_SITES_DEFAULT"
  markup_debug "PATH_SITES_DEFAULT : ${DEPLOY_PATH_SITES_DEFAULT}"

  DEPLOY_PATH_RELEASES=$(deploy_get_config_variable "PATH_RELEASES")
  deploy_check_config_variable "PATH_RELEASES" "$DEPLOY_PATH_RELEASES"
  markup_debug "PATH_RELEASES : ${DEPLOY_PATH_RELEASES}"

  markup_debug "$(markup_divider)"
  markup_debug

  # Check for errors.
  if [ ${#DEPLOY_CHECK_CONFIG_ERRORS[@]} -ne 0 ]; then
    markup_error "Not all neccesary config variables are set:"
    for error in "${DEPLOY_CHECK_CONFIG_ERRORS[@]}"; do
      message_error "$error"
    done
    echo
    exit 1
  fi
}

##
# Function to check a single configuration variable.
#
# @param string
#   The variable to check.
##
function deploy_get_config_variable {
  local varname="DEPLOY_${DEPLOY_ENVIRONMENT}_$1"
  eval value="\$${varname}"
  echo "$value"
}

##
# Function to check a single config variable.
#
# @param string
#   The variable to check.
# @param value
#   The value to check.
##
function deploy_check_config_variable {
  if [ "$2" == "" ]; then
    DEPLOY_CHECK_CONFIG_ERRORS+=("Missing config variable \$DEPLOY_${DEPLOY_ENVIRONMENT}_$1.")
  fi
}

##
# Create the global variables needed for the build.
##
function deploy_variables {
  markup_debug
  markup_debug "BUILD VARIABLES"
  markup_debug "$(markup_divider)"

  # TimeStamp.
  DEPLOY_TIMESTAMP=$(date +"%Y%m%d%H%M%S")
  markup_debug "TIMESTAMP : ${DEPLOY_TIMESTAMP}"
  DEPLOY_DATE=$(date +"%Y-%m-%d %H:%M:%S")
  markup_debug "DATE : ${DEPLOY_DATE}"

  # Git info.
  DEPLOY_BRANCH=$(git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/\1 /')
  markup_debug "BRANCH : ${DEPLOY_BRANCH}"
  DEPLOY_HASH_LONG=$(git log -1 --format="%H")
  markup_debug "HASH LONG : ${DEPLOY_HASH_LONG}"
  DEPLOY_HASH_SHORT=$(git log --pretty=format:'%h' -n 1)
  markup_debug "HASH SHORT : ${DEPLOY_HASH_SHORT}"

  # Version. Will be used for tarball and directory.
  DEPLOY_VERSION="${DEPLOY_TIMESTAMP}_${DEPLOY_HASH_SHORT}"
  markup_debug "VERSION : ${DEPLOY_VERSION}"
  DEPLOY_PACKAGE="${DEPLOY_VERSION}.tar.gz"
  markup_debug "PACKAGE : ${DEPLOY_PACKAGE}"


  # Current version.
  DEPLOY_VERSION_CURRENT=$(deploy_remote_ssh "cd ${DEPLOY_PATH_HTDOCS} && basename \$(pwd -P)" 1)
  DEPLOY_VERSION_CURRENT=${DEPLOY_VERSION_CURRENT//[^a-zA-Z0-9_-]/}
  markup_debug "CURRENT VERSION : ${DEPLOY_VERSION_CURRENT}"

  markup_debug "$(markup_divider)"
  markup_debug
}



## DEPLOY BUILD ################################################################

##
# Build the website package locally.
##
function deploy_build {
  deploy_build_website
  deploy_build_info_file
  deploy_build_package
  deploy_build_cleanup
}

##
# Build the website files.
##
function deploy_build_website {
  markup_h1 "Build website"

  local option=""
  if [ $(option_is_set "--verbose") -eq 1 ] || [ $(option_is_set "--verbose") -eq 1 ]; then
    option="-v"
  fi

  "${DIR_BIN}/build" -y --env=prd --no-package "$option" "${DEPLOY_VERSION}"
  echo
}

##
# Create an info file with the build information.
##
function deploy_build_info_file {
  local info_file="${DIR_BUILD}/web/BUILD.txt"

  markup_h1 "Add build info"

  echo "BUILD INFO" > "${info_file}"
  echo "" >> "${info_file}"
  echo "Package : ${DEPLOY_VERSION}" >> "${info_file}"
  echo "Date    : ${DEPLOY_DATE}" >> "${info_file}"
  echo "Branch  : ${DEPLOY_BRANCH}" >> "${info_file}"
  echo "Commit  : ${DEPLOY_HASH_LONG} (${DEPLOY_HASH_SHORT})" >> "${info_file}"
  echo "" >> "${info_file}"
  echo "Upgrade from : ${DEPLOY_VERSION_CURRENT}" >> "${info_file}"
  echo "" >> "${info_file}"

  message_success "Added build info to BUILD.txt"
  echo
}

##
# Create the build package.
##
function deploy_build_package {
  markup_h1 "Create package"

  rm -R "${DIR_BUILD}/web/sites/default"
  cd "${DIR_BUILD}"
  mv "web" "${DEPLOY_VERSION}"
  tar -czf "${DEPLOY_PACKAGE}" "${DEPLOY_VERSION}"
  cd "${DIR_ROOT}"

  message_success "Created package ${DEPLOY_PACKAGE}"
  echo
}

##
# Cleanup the build.
##
function deploy_build_cleanup {
  markup_h1 "Cleanup build artifacts"

  rm -R "${DIR_BUILD}/${DEPLOY_VERSION}"

  message_success "Deleted ${DIR_BUILD}/${DEPLOY_VERSION}"
  echo
}



## DEPLOY PACKAGE ##############################################################

##
# Deploy the package to remote location.
##
function deploy_package {
  deploy_package_upload
  deploy_package_extract
  deploy_package_symlink_sites_default
}

##
# Upload the build package to the remote location.
##
function deploy_package_upload {
  markup_h1 "Upload package to remote location"
  deploy_remote_upload "${DIR_BUILD}/${DEPLOY_PACKAGE}" "${DEPLOY_PATH_RELEASES}"
  message_success "Package uploaded."
  echo
}

##
# Extract the package on the remte location.
##
function deploy_package_extract {
  markup_h1 "Extract package on remote location"
  deploy_remote_ssh "cd ${DEPLOY_PATH_RELEASES}; tar -xzf ${DEPLOY_PACKAGE}"
  deploy_remote_ssh "rm ${DEPLOY_PATH_RELEASES}/${DEPLOY_PACKAGE}"
  message_success "Package extracted."
  echo
}

##
# Add symlink to the sites/default directory.
##
function deploy_package_symlink_sites_default {
  markup_h1 "Symlink sites/default directory"
  deploy_remote_ssh "ln -s ${DEPLOY_PATH_SITES_DEFAULT} ${DEPLOY_PATH_RELEASES}/${DEPLOY_VERSION}/sites/default"
  message_success "Symlink created."
  echo
}



## DEPLOY SITE #################################################################

##
# Deploy the website by moving the symlink and updating the DB.
##
function deploy_site {
  deploy_site_maintenance_on
  deploy_site_backup
  deploy_site_symlink_htdocs
  deploy_site_update
  deploy_site_features_revert
  deploy_site_maintenane_off
}

##
# Put the site in maintenance mode.
##
function deploy_site_maintenance_on {
  markup_h1 "Put site in maintenance mode"
  deploy_remote_drush "vset maintenance_mode 1"
  message_success "Mainenance mode enabled."
  echo
}

##
# Take a backup before the upgrade.
##
function deploy_site_backup {
  markup_h1 "Create backup"
  local backup_name="${DEPLOY_VERSION_CURRENT}___${DEPLOY_VERSION}.tar"
  markup_debug "Backup name : ${backup_name}"
  deploy_remote_drush "ard --destination=${DEPLOY_PATH_BACKUPS}/${backup_name}"
  message_success "Backup ${backup_name} created."
  echo
}

##
# Put the symlink to the new release.
##
function deploy_site_symlink_htdocs {
  markup_h1 "Set htdocs symlink to new release"
  deploy_remote_ssh "unlink ${DEPLOY_PATH_HTDOCS}"
  deploy_remote_ssh "ln -s ${DEPLOY_PATH_RELEASES}/${DEPLOY_VERSION} ${DEPLOY_PATH_HTDOCS}"
  message_success "Symlink is updated."
  echo
}

##
# Update the drupal database (module update hooks).
##
function deploy_site_update {
  markup_h1 "Update website"

  # We need to disable exit on error as importing the translations can cause
  # errors.
  set +e
  deploy_remote_drush "-y updb"
  set -e
  
  deploy_remote_drush "cc all"
  message_success "Updates installed."
  echo
}

##
# Revert all features
##
function deploy_site_features_revert {
  markup_h1 "Revert all website features"
  deploy_remote_drush "-y fra"
  deploy_remote_drush "cc all"
  message_success "Features are reverted."
  echo
}

##
# Disable maintenance mode.
##
function deploy_site_maintenane_off {
  markup_h1 "Put site in production mode"
  deploy_remote_drush "vset maintenance_mode 0"
  message_success "Mainenance mode disabled."
  echo
}



## HELPER FUNCTIONS ############################################################

##
# Upload a file over SSH.
#
# @param string
#  The path to the local file.
# @param string
#  The path to the local directory where to upload the file to.
##
function deploy_remote_upload {
  local source="$1"
  local target="$2"

  markup_debug "scp -P${DEPLOY_PORT} ${source} ${DEPLOY_USER}@${DEPLOY_HOST}:${target}"
  scp -P${DEPLOY_PORT} \
    "${source}" \
    "${DEPLOY_USER}"@"${DEPLOY_HOST}":"${target}"
}

##
# Run a command remotely over SSH.
#
# @param string
#   The command and its options to run remotely.
# @param disable debugging
#   Disable debugging (1) to avoid captured output to be filled with debug info.
#   Default = 0.
##
function deploy_remote_ssh {
  if [ "$2" != "1" ]; then
    markup_debug "Run remote ssh:"
    markup_debug "ssh -t ${DEPLOY_USER}@${DEPLOY_HOST} -p${DEPLOY_PORT} -o StrictHostKeyChecking=no $1"
    markup_debug
  fi

  # Quit mode when no verbose is used.
  local options=""
  if [ $(option_is_set "--verbose") -ne 1 ] && [ $(option_is_set "--verbose") -ne 1 ]; then
    options="-q"
  fi

  ssh -t "${options}" \
    ${DEPLOY_USER}@${DEPLOY_HOST} \
    -p${DEPLOY_PORT} \
    -o StrictHostKeyChecking=no \
    "$1"
}

##
# Run a drush command remotely over SSH.
#
# @param string
#   The command and its options to run remotely.
# @param disable debugging
#   Disable debugging (1) to avoid captured output to be filled with debug info.
#   Default = 0.
##
function deploy_remote_drush {
  deploy_remote_ssh "${DEPLOY_PATH_DRUSH} --root=${DEPLOY_PATH_HTDOCS} $1" "$2"
}
