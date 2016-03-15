#!/bin/sh
set -e

# ---------------------------------------------------------------------------- #
#
# Installs && configure node.js 4.x
#
# ---------------------------------------------------------------------------- #

curl -sL https://deb.nodesource.com/setup_4.x | sudo -E bash -
sudo apt-get install -y nodejs