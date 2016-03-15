#!/bin/sh
set -e

# ---------------------------------------------------------------------------- #
#
# Install task runners & their dependencies.
#
# ---------------------------------------------------------------------------- #


# No need for taskrunners if profile is not installed.
if [ $INSTALL_PROFILE != 1 ]; then
 exit 0;
fi


# Update npm
npm install -g npm@2

# Install Grunt.
npm install -g grunt-cli

# Install Bower.
npm install -g bower
