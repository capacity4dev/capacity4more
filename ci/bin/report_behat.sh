#!/bin/sh
set -e

#if [ -d "$TRAVIS_BUILD_DIR/project/profiles/capacity4more/behat/dumps" ]; then
  date

  cd $TRAVIS_BUILD_DIR/project/profiles/capacity4more/behat/dumps

# Debug feedback.
  pwd
  ls -al

  tar -czf behat.tar.gz *

  # Send archive as mail attachment.
  mutt -s "Travis report for behat dumps" climacon@gmail.com < behat.tar.gz

#fi