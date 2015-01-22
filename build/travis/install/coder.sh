#!/bin/sh

# ---------------------------------------------------------------------------- #
#
# Installs The coder library so we can use t for code reviews.
#
# ---------------------------------------------------------------------------- #

cd $TRAVIS_BUILD_DIR
composer global require drupal/coder:\>7
drush pm-download coder-7.x-2.x-dev --destination=$HOME/.drush
phpenv rehash
drush cache-clear drush
