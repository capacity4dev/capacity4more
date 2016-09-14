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

  tar -czf behat.$TRAVIS_BUILD_ID.$TRAVIS_BUILD_NUMBER--$NOW.tar.gz *

  # Send archive as mail attachment.
  curl -s --user "api:$MAILGUN_API" \
    $MAILGUN_MESSAGES_URL \
    -F from=$MAILGUN_FROM \
    -F to=$MAILGUN_TO \
    -F subject="Behat reporting - Error dumps for build $TRAVIS_BUILD_ID / $TRAVIS_BUILD_NUMBER" \
    -F text="Attached you can find the behat error dumps for build $TRAVIS_BUILD_ID / $TRAVIS_BUILD_NUMBER!" \
    -F attachment=@$FILE
fi