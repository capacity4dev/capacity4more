#!/bin/bash

# ---------------------------------------------------------------------------- #
#
# Installs Drush.
#
# ---------------------------------------------------------------------------- #

# Install Drush.
cd $TRAVIS_BUILD_DIR
composer global require drush/drush 8.*
phpenv rehash

# Create the Drush alias.
mkdir -p ~/.drush
cp $TRAVIS_BUILD_DIR/ci/config/aliases.drushrc.php ~/.drush/

# Verify.
drush --version
