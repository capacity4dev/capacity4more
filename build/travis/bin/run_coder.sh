#!/bin/sh
set -e

# ---------------------------------------------------------------------------- #
#
# Run the coder review.
#
# ---------------------------------------------------------------------------- #


# Do we have a tag to run?
if [ $CODE_REVIEW != 1 ]; then
  exit 0
fi


# Review custom modules.
drush coder --major --no-empty $TRAVIS_BUILD_DIR/capacity4more/modules/c4m

# Review custom themes.
drush coder --major --no-empty $TRAVIS_BUILD_DIR/capacity4more/themes/c4m
