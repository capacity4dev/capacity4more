#!/bin/sh
set -e

# ---------------------------------------------------------------------------- #
#
# Installs the Apache server on Travis-CI
#
# ---------------------------------------------------------------------------- #


# No need for Apache if the profile is not installed.
if [ $INSTALL_PROFILE != 1 ]; then
 exit 0;
fi

# Install necesary php packages.
sudo apt-get install -y --force-yes php5-cgi php5-mysql

# Install Apache.
sudo apt-get install apache2 libapache2-mod-fastcgi
sudo a2enmod rewrite actions fastcgi alias

# Config php-fpm.

php_version=$(phpenv version-name)

if [ "$php_version" = 7.0 ]; then
    sudo cp ~/.phpenv/versions/$(phpenv version-name)/etc/php-fpm.d/php-fpm.conf.default ~/.phpenv/versions/$(phpenv version-name)/etc/php-fpm.d/php-fpm.conf
else
    sudo cp ~/.phpenv/versions/$(phpenv version-name)/etc/php-fpm.conf.default ~/.phpenv/versions/$(phpenv version-name)/etc/php-fpm.conf
fi

echo "cgi.fix_pathinfo = 1" >> ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini
~/.phpenv/versions/$(phpenv version-name)/sbin/php-fpm

# Set sendmail so php doesn't throw an error while trying to send out email.
echo "sendmail_path='true'" >> `php --ini | grep "Loaded Configuration" | awk '{print $4}'`

# Create the www folder as we need it for the vhost config.
mkdir $TRAVIS_BUILD_DIR/web

# Create the default vhost config file.
if [ "$php_version" = 7.0 ]; then
    sudo cp -f $TRAVIS_BUILD_DIR/ci/config/apache-70.conf /etc/apache2/sites-available/default
else
    sudo cp -f $TRAVIS_BUILD_DIR/ci/config/apache.conf /etc/apache2/sites-available/default
fi

sudo sed -e "s?%TRAVIS_BUILD_DIR%?$TRAVIS_BUILD_DIR?g" --in-place /etc/apache2/sites-available/default

# Restart Apache
sudo service apache2 restart
