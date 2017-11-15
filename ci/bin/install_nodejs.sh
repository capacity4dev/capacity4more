#!/bin/sh
set -e

# ---------------------------------------------------------------------------- #
#
# Install && configure node.js.
#
# ---------------------------------------------------------------------------- #

curl -sL https://deb.nodesource.com/setup_6.x | sudo -E bash -
sudo apt-get install -y nodejs
