#!/bin/sh

# ---------------------------------------------------------------------------- #
#
# Install Behat dependencies.
#
# ---------------------------------------------------------------------------- #

cd $TRAVIS_BUILD_DIR/capacity4more/behat

# Copy the travis specific behat config file.
cp $TRAVIS_BUILD_DIR/build/travis/config/behat.local.yml.travis ./behat.local.yml

# Install the behat dependencies.
composer install --prefer-source

cd $TRAVIS_BUILD_DIR
