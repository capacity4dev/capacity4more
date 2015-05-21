#!/bin/sh
set -e

# ---------------------------------------------------------------------------- #
#
# Installs Drupal with the profile.
#
# ---------------------------------------------------------------------------- #


if [ $INSTALL_PROFILE != 1 ]; then
 exit 0;
fi


cd $TRAVIS_BUILD_DIR

# Use the travis config file.
cp $TRAVIS_BUILD_DIR/build/travis/config/config.sh.travis config.sh

# Install the drupal platform based on the config file.
./install -dy

# Disable the dblog module to prevent overuse of the mysql server.
echo "Disable dblog module to avoid extra stress on MySQL server."
cd $TRAVIS_BUILD_DIR/www
drush -y dis dblog

# Stay Calm and Clear the Cache!
#echo "Clear all caches"
#drush cc all --yes

cd $TRAVIS_BUILD_DIR
