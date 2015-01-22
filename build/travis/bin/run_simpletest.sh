#!/bin/sh

# ---------------------------------------------------------------------------- #
#
# Run the Simpletest tests.
#
# ---------------------------------------------------------------------------- #


# Do we have a tag to run?
if [ $SIMPLETEST != 1 ]; then
  exit 0
fi

# Enable the simpletest module.
drush @capacity4more -y en simpletest

# Run all tests tagged with the distribution name.
drush @capacity4more test-run "capacity4more"
