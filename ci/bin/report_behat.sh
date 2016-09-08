#!/bin/sh
set -e

#if [ -d "$TRAVIS_BUILD_DIR/project/profiles/capacity4more/behat/dumps" ]; then
  date

#  cd $TRAVIS_BUILD_DIR/project/profiles/capacity4more/behat/dumps

# Debug feedback.
  pwd
  ls -al

#  tar -czf behat.tar.gz *

echo "Hello world" > ./testfile.txt
cat ./testfile.txt

  # Send archive as mail attachment.
  curl -s --user 'api:key-6b112d148c86bff26881f380a1488414' \
    https://api.mailgun.net/v3/sandboxf927d954c8414f9992d4118762a74eda.mailgun.org/messages \
    -F from='Mailgun Sandbox <postmaster@sandboxf927d954c8414f9992d4118762a74eda.mailgun.org>' \
    -F to='Kevin <capfourdev.amplexor@gmail.com>' \
    -F subject='Behat reporting - Error dumps' \
    -F text='Attached you can find the behat error dumps!' \
    -F attachment=testfile.txt

#fi