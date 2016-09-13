#!/bin/sh
set -e

# No need for special config if the profile is not installed.
if [ $INSTALL_PROFILE -ne 1 ]; then
 exit 0;
fi

if [ -d "$TRAVIS_BUILD_DIR/project/profiles/capacity4more/behat/features/dump" ]; then
  date

  cd $TRAVIS_BUILD_DIR/project/profiles/capacity4more/behat/features/dump

  NOW=$(date +"%Y%m%d-%H%M%s")
  FILE="behat.$NOW.tar.gz"

  tar -czf behat.$NOW.tar.gz *

  # Send archive as mail attachment.
  curl -s --user 'api:key-6b112d148c86bff26881f380a1488414' \
    https://api.mailgun.net/v3/sandboxf927d954c8414f9992d4118762a74eda.mailgun.org/messages \
    -F from='Mailgun Sandbox <postmaster@sandboxf927d954c8414f9992d4118762a74eda.mailgun.org>' \
    -F to='capacity4more admin <capfourdev.amplexor@gmail.com>' \
    -F subject='Behat reporting - Error dumps' \
    -F text='Attached you can find the behat error dumps!' \
    -F attachment=@behat.$NOW.tar.gz
fi