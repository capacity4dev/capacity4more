#!/bin/bash

# ---------------------------------------------------------------------------- #
#
# Install task runners & their dependencies.
#
# ---------------------------------------------------------------------------- #

# No need for taskrunners if profile is not installed.
if [ "$INSTALL_PROFILE" -ne 1 ]; then
 exit 0;
fi

gem install sass

# Output node version.
npm -v

# Update npm.
npm install -g npm@latest

# Install Grunt.
npm install -g grunt-cli

# Install Gulp.
npm install -g gulp

# Install Bower.
npm install -g bower
