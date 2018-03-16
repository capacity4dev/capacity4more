#!/bin/bash

# ---------------------------------------------------------------------------- #
#
# Installs TIKA script to extract the content of documents.
#
# ---------------------------------------------------------------------------- #


# No need for Solr if the profile is not installed.
if [ "$INSTALL_PROFILE" -ne 1 ]; then
 exit 0;
fi

VERSION="$1"
DOWNLOAD_URL="http://archive.apache.org/dist/tika/tika-app-$VERSION.jar"

mkdir -p $TRAVIS_BUILD_DIR/tika

cd $TRAVIS_BUILD_DIR/tika
wget -nv $DOWNLOAD_URL
chmod +x ./tika-app-*.jar

cd $TRAVIS_BUILD_DIR
