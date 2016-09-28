#!/bin/sh
set -e

# ---------------------------------------------------------------------------- #
#
# Installs && configure node.js 4.x
#
# ---------------------------------------------------------------------------- #

curl -sL https://deb.nodesource.com/setup_4.x | sudo -E bash -
sudo apt-get install -y build-essential
sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt-get install g++-5