#!/bin/sh
set -e

# ---------------------------------------------------------------------------- #
#
# Install task runners & their dependencies.
#
# ---------------------------------------------------------------------------- #

# Update npm
npm install -g npm@2

# Install Grunt.
npm install -g grunt-cli

# Install Bower.
npm install -g bower
