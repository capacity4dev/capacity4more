#!/bin/sh

# ---------------------------------------------------------------------------- #
#
# Installs Drush.
#
# ---------------------------------------------------------------------------- #


# Install Drush.
cd $TRAVIS_BUILD_DIR
export PATH="$HOME/.composer/vendor/bin:$PATH"
composer global require drush/drush 6.*
phpenv rehash

# Everybody should be able to use drush.
ln -s $HOME/.composer/vendor/bin/drush /usr/bin/drush

# Create the Drush alias.
mkdir -p ~/.drush
cp $TRAVIS_BUILD_DIR/build/travis/config/aliases.drushrc.php ~/.drush/

drush --version
