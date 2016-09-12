#!/bin/sh
set -e

# ---------------------------------------------------------------------------- #
#
# Installs Drupal with the profile.
#
# ---------------------------------------------------------------------------- #


if [ $INSTALL_PROFILE -ne 1 ]; then
 exit 0;
fi


cd $TRAVIS_BUILD_DIR

# Use the travis config file.
cp $TRAVIS_BUILD_DIR/ci/config/config.sh.travis config/config.sh

./bin/init -y

# Install the drupal platform based on the config file.
./bin/install -y --dummy-content --no-login --no-backup --env=ci

# Disable the dblog module to prevent overuse of the mysql server.
#echo "Disable dblog module to avoid extra stress on MySQL server"
#cd $TRAVIS_BUILD_DIR/web
#drush -y dis dblog

# Stay Calm and Clear the Cache!
echo "Clear all caches"
drush cc all --yes

cd $TRAVIS_BUILD_DIR
