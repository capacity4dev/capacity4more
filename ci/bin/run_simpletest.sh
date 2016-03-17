#!/bin/sh
set -e

# ---------------------------------------------------------------------------- #
#
# Run the Simpletest tests.
#
# ---------------------------------------------------------------------------- #


# No need for SimpleTest if the profile is not installed.
if [ $INSTALL_PROFILE != 1 ]; then
 exit 0;
fi

# Do we have a tag to run?
if [ $SIMPLETEST != 1 ]; then
  exit 0
fi


# Enable the simpletest module.
drush @capacity4more -y en simpletest

# Run all tests tagged with the distribution name.
php $TRAVIS_BUILD_DIR/web/scripts/run-tests.sh "capacity4more"
