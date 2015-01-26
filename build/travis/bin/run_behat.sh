#!/bin/sh
set -e

# ---------------------------------------------------------------------------- #
#
# Run the behat tests.
#
# ---------------------------------------------------------------------------- #


# Do we have a tag to run?
if [ "$BEHAT_TAG" = "" ]; then
  exit 0
fi


cd $TRAVIS_BUILD_DIR/capacity4more/behat

# Run tests for the api tag.
if [ "$BEHAT_TAG" = "api" ]; then
  ./bin/behat --tags=@api
fi

# Run tests for the javascript tag.
if [ "$BEHAT_TAG" = "javascript" ]; then
  ./bin/behat -p phantomjs --tags=@javascript
fi

cd $TRAVIS_BUILD_DIR
