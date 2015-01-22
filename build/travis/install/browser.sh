#!/bin/sh

# ---------------------------------------------------------------------------- #
#
# Instals & runs the environment to do headless browser tests.
#
# ---------------------------------------------------------------------------- #


# Create display.
export DISPLAY=:99.0
sh -e /etc/init.d/xvfb start
sleep 3

# Run selenium.
cd $TRAVIS_BUILD_DIR/capacity4more/behat
wget http://selenium-release.storage.googleapis.com/2.40/selenium-server-standalone-2.40.0.jar
java -jar selenium-server-standalone-2.40.0.jar -p 4444 &
sleep 5

# Run phantomJs.
phantomjs --webdriver=8643 > ~/phantomjs.log 2>&1 &
