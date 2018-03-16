#!/bin/bash

# No need for special config if the profile is not installed.
if [ "$INSTALL_PROFILE" -ne 1 ]; then
 exit 0;
fi

if [ -d "$TRAVIS_BUILD_DIR/project/profiles/capacity4more/behat/features/dump" ]; then
  date

  cd $TRAVIS_BUILD_DIR/project/profiles/capacity4more/behat/features/dump

  ls -al

  NOW=$(date +"%Y%m%d-%H%M%s")
  FILE="behat.{$TRAVIS_BUILD_ID}.{$TRAVIS_BUILD_NUMBER}--{$NOW}.tar.gz"

  tar -czvf $FILE *

  # Send archive as mail attachment.
  curl -s --user "api:$MAILGUN_API" \
    $MAILGUN_MESSAGES_URL \
    -F from=$MAILGUN_FROM \
    -F to=$MAILGUN_TO \
    -F subject="Behat reporting - Error dumps (${TRAVIS_BRANCH})" \
    -F text="Attached you can find the behat error dumps for ${TRAVIS_BRANCH} on http://www.github.com/${TRAVIS_REPO_SLUG}/commit/${TRAVIS_COMMIT}" \
    -F attachment=@$FILE
fi
