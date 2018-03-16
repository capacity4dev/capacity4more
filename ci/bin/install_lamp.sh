#!/bin/bash

# No need for special config if the profile is not installed.
if [ "$INSTALL_PROFILE" -ne 1 ]; then
 exit 0;
fi

# Create directory so apache can start.
mkdir -p ${TRAVIS_BUILD_DIR}/web

sudo apt-get install apache2 libapache2-mod-fastcgi

# Enable php-fpm.
sudo cp ~/.phpenv/versions/$(phpenv version-name)/etc/php-fpm.conf.default ~/.phpenv/versions/$(phpenv version-name)/etc/php-fpm.conf
sudo cp ~/.phpenv/versions/$(phpenv version-name)/etc/php-fpm.d/www.conf.default ~/.phpenv/versions/$(phpenv version-name)/etc/php-fpm.d/www.conf

# Enable apache modules.
sudo a2enmod rewrite actions fastcgi alias

# Config + permissions.
echo "cgi.fix_pathinfo = 1" >> ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini
sudo sed -i -e "s,www-data,travis,g" /etc/apache2/envvars
sudo chown -R travis:travis /var/lib/apache2/fastcgi
~/.phpenv/versions/$(phpenv version-name)/sbin/php-fpm

# Configure apache virtual hosts.
sudo cp -f ${TRAVIS_BUILD_DIR}/ci/config/travis-ci-apache /etc/apache2/sites-available/000-default.conf
sudo sed -e "s?%TRAVIS_BUILD_DIR%?$(pwd)?g" --in-place /etc/apache2/sites-available/000-default.conf
sudo service apache2 restart

# Copy the proper config file.
sudo cp -f $TRAVIS_BUILD_DIR/ci/config/drupal.cnf /etc/mysql/conf.d/drupal.cnf

# Restart the mysql service.
sudo service mysql restart
