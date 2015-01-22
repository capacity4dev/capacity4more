#!/bin/sh
set -e

# ---------------------------------------------------------------------------- #
#
# Installs && configure MySQL server & database(s).
#
# ---------------------------------------------------------------------------- #


# Copy the proper config file.
sudo cp -f $TRAVIS_BUILD_DIR/build/travis/config/drupal.cnf /etc/mysql/conf.d/drupal.cnf

# Restart the mysql service.
sudo service mysql restart
