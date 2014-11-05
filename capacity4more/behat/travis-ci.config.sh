#!/bin/bash

###############################################################################
#
# Configuration used in the install/update/reset scripts.
# 
# This file is used on the TravisCi environment.
#
###############################################################################


# The profile used to install the platform.
PROFILE_NAME="capacity4more"
# The human name of the install profile
PROFILE_TITLE="capacity4more"


# Modify the URL below to match your local domain the site will be accessible on.
BASE_DOMAIN_URL="127.0.0.1:8080"


# Modify the login details below to be the desired 
# login details for the Drupal Administrator account.
ADMIN_USERNAME="admin"
ADMIN_PASSWORD="admin"
ADMIN_EMAIL="capacity4more@local.dev"


# Modify the MySQL settings below so they will match your own.
MYSQL_USERNAME="root"
MYSQL_PASSWORD=""
MYSQL_HOSTNAME="127.0.0.1"
MYSQL_DB_NAME="drupal"
