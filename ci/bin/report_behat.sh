#!/bin/sh
set -e

#if [ -d "$TRAVIS_BUILD_DIR/project/profiles/capacity4more/behat/dump" ]; then
  cd $TRAVIS_BUILD_DIR/project/profiles/capacity4more/behat

  tar -czf behat.tar.gz *

  mutt -s "Travis report for behat dumps" climacon@gmail.com < behat.tar.gz

  # Make archive of all files in this directory.

#fi