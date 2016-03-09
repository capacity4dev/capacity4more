################################################################################
# This is the global configuration file.
#
# ! It contains sensitive data and should never be comitted to a repository.
#
# Copy this example to config/config.sh and fill in the values.
# You can add extra config variables if you need them in your scripts.
################################################################################

# The name of the site.
SITE_NAME="My Website"

# URL where the site is hosted.
SITE_URL="my-site.dev"

# The install profile that shouls be installed.
SITE_PROFILE="standard"

# Database connection parameters.
DB_USER=""
DB_PASS=""
DB_NAME="my_site_db"
DB_HOST="localhost"

# Administrator account (user 1).
ACCOUNT_NAME="admin"
ACCOUNT_PASS="drupal"
ACCOUNT_MAIL="$ACCOUNT_NAME@$SITE_URL"



################################################################################
# Druleton configuration.
################################################################################

# Composer is by default downloaded during the bin/init script.
# You can optionally use a global installed composer.
COMPOSER_USE_GLOBAL=0

# The Drush version to use.
#
# Options:
# - phar : use the drush.phar file as the local drush binary. This is the
#   default option.
# - branch or tag name : use a specific version by setting the variable to the
#   proper branch or tag name (eg. dev-master).
#   See https://github.com/drush-ops/drush.
# - global : use the globally installed drush command (outside druleton).
#
# If the variable is not set, phar will be used.
DRUSH_VERSION="phar"

# drupal/coder is installed by default as a dependency for the bin/coder
# command. The installation is not required on all environments.
# Disable installing it by setting the CODER_DISABLED variable to 1 (default 0).
CODER_DISABLED=0
