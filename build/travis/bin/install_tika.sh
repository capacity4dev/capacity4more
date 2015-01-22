#!/bin/sh

# ---------------------------------------------------------------------------- #
#
# Installs TIKA script to extract the content of documents.
#
# ---------------------------------------------------------------------------- #

VERSION="$1"
DOWNLOAD_URL="http://archive.apache.org/dist/tika/tika-app-$VERSION.jar"

mkdir -p $TRAVIS_BUILD_DIR/tika

cd $TRAVIS_BUILD_DIR/tika
wget $DOWNLOAD_URL
chmod +x ./tika-app-*.jar

cd $TRAVIS_BUILD_DIR
