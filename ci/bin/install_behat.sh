#!/bin/bash

# ---------------------------------------------------------------------------- #
#
# Install Behat dependencies.
#
# ---------------------------------------------------------------------------- #

# Behat has no use if the profile is not installed.
if [ "$INSTALL_PROFILE" != 1 ]; then
 exit 0;
fi

# Check first if we need behat.
if [ "$BEHAT_TAG" = "" ]; then
  exit 0;
fi

cd $TRAVIS_BUILD_DIR/project/profiles/capacity4more/behat

# Copy the travis specific behat config file.
cp $TRAVIS_BUILD_DIR/ci/config/behat.local.yml.travis ./behat.local.yml

# Install the behat dependencies.
composer install --prefer-source

cd $TRAVIS_BUILD_DIR
