#!/usr/bin/env bash

# DigitalOcean - How To Install Solr on Ubuntu 14.04
# https://www.digitalocean.com/community/tutorials/how-to-install-solr-on-ubuntu-14-04

sudo apt-get update

# Download Java
sudo apt-get -y install openjdk-7-jdk
sudo mkdir /usr/java
sudo ln -s /usr/lib/jvm/java-7-openjdk-amd64 /usr/java/default

# Download Solr 5.3.1
cd /opt
sudo wget http://archive.apache.org/dist/lucene/solr/5.3.1/solr-5.3.1.tgz
sudo tar -xvf solr-5.3.1.tgz
sudo cp -R solr-5.3.1 /opt/solr

# Create user
sudo useradd -d /opt/solr -s /sbin/false solr
sudo chown solr:solr -R /opt/solr

# Start Solr
sudo /opt/solr/bin/solr start

# Core replication
sudo chmod a+x /vagrant/core.sh
sudo /vagrant/core.sh
