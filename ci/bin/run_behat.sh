#!/bin/bash

# ---------------------------------------------------------------------------- #
#
# Run the behat tests.
#
# ---------------------------------------------------------------------------- #

# No need for Behat if the profile is not installed.
if [ "$INSTALL_PROFILE" != 1 ]; then
 exit 0;
fi

# Do we have a tag to run?
if [ "$BEHAT_TAG" = "" ]; then
  exit 0
fi

cd $TRAVIS_BUILD_DIR/project/profiles/capacity4more/behat

# Run tests for the api tag.
if [ "$BEHAT_TAG" = "api" ]; then
  ./bin/behat --tags='@api&&~@wip'
fi

# Run tests for the javascript tag.
if [ "$BEHAT_TAG" = "javascript" ]; then
  ./bin/behat -p phantomjs --tags='@javascript&&~@wip'
fi

cd $TRAVIS_BUILD_DIR
