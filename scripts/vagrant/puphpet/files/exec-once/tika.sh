#!/bin/bash

# Install TIKA.
cd /tmp
wget --quiet http://archive.apache.org/dist/tika/tika-app-1.5.jar
sudo mkdir /opt/tika
sudo mv tika-app-1.5.jar /opt/tika/tika-app.jar
