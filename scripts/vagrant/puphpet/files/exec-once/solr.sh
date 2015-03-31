#!/bin/bash

# Configure SOLR
cd /tmp
wget --quiet http://ftp.drupal.org/files/projects/search_api_solr-7.x-1.6.tar.gz
tar -xzf search_api_solr-7.x-1.6.tar.gz
sudo rsync -av search_api_solr/solr-conf/4.x/ /opt/solr/solr-4.10.2/example/solr/collection1/conf/
