#!/bin/bash

#########################################################################################
#
# Configuration used in the different scripts.
# 
# Copy this file in the same directory, the filename of the copy should be "config.sh".
#
#########################################################################################


# The profile used to install the platform.
PROFILE_NAME="capacity4more"
# The human name of the install profile
PROFILE_TITLE="capacity4more"


# Modify the URL below to match your local domain the site will be accessible on.
BASE_DOMAIN_URL=""


# Modify the login details below to be the desired 
# login details for the Drupal Administrator account.
ADMIN_USERNAME=""
ADMIN_PASSWORD=""
ADMIN_EMAIL=""


# Modify the MySQL settings below so they will match your own.
MYSQL_USERNAME=""
MYSQL_PASSWORD=""
MYSQL_HOSTNAME=""
MYSQL_DB_NAME=""


##
# External folders or files that need to be symlinked into the www folder
# AFTER the make files have been processed.
# The variable is an array, add each with an unique index number.
# Each line should contain the source path > target path.
# The target path needs to be relative to the www folder (Drupal root).
#
# Example:
#   SYMLINKS[0]="path/to/the/source/folder>subpath/of/the/www-folder"
##
#SYMLINKS[0]="/var/www/library/foldername>sites/all/library/foldername"
#SYMLINKS[1]="/var/www/shared/filename.php>sites/all/modules/filename.php"
