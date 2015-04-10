#!/bin/bash

# Configure SOLR.
cd /tmp
wget --quiet http://ftp.drupal.org/files/projects/search_api_solr-7.x-1.6.tar.gz
tar -xzf search_api_solr-7.x-1.6.tar.gz
sudo rsync -av search_api_solr/solr-conf/4.x/ /opt/solr/solr-4.10.2/example/solr/collection1/conf/

# Capacity4More SOLR core.
sudo cp -r /opt/solr/solr-4.10.2/example/solr/collection1 /opt/solr/solr-4.10.2/example/solr/capacity4more
sudo rm -f /opt/solr/solr-4.10.2/example/solr/capacity4more/core.properties
echo "name:capacity4more" | sudo tee --append /opt/solr/solr-4.10.2/example/solr/capacity4more/core.properties

# Capacity4Dev SOLR core.
sudo cp -r /opt/solr/solr-4.10.2/example/solr/collection1 /opt/solr/solr-4.10.2/example/solr/capacity4dev
sudo rm -f /opt/solr/solr-4.10.2/example/solr/capacity4dev/core.properties
echo "name:capacity4dev" | sudo tee --append /opt/solr/solr-4.10.2/example/solr/capacity4dev/core.properties
