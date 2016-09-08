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
  curl -s --user 'api:key-6b112d148c86bff26881f380a1488414' \
    https://api.mailgun.net/v3/sandboxf927d954c8414f9992d4118762a74eda.mailgun.org/messages \
    -F from='Mailgun Sandbox <postmaster@sandboxf927d954c8414f9992d4118762a74eda.mailgun.org>' \
    -F to='Kevin <capfourdev.amplexor@gmail.com>' \
    -F subject='Hello Kevin' \
    -F text='Congratulations Kevin, you just sent an email with Mailgun!  You are truly awesome!'

#fi