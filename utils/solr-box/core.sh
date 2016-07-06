#!/usr/bin/env bash

CORE_DIRECTORY="/opt/solr/server/solr/core"
CORE_CONF_DIRECTORY="${CORE_DIRECTORY}/conf"
CORE_VAGRANT_DIRECTORY="/vagrant/core"
CORE_VAGRANT_CONF_DIRECTORY="${CORE_VAGRANT_DIRECTORY}/conf"

if [ ! -d ${CORE_DIRECTORY} ]; then
  sudo rm -rf ${CORE_DIRECTORY}
  sudo cp -R ${CORE_VAGRANT_DIRECTORY} ${CORE_DIRECTORY}
  sudo chown solr:solr -R ${CORE_DIRECTORY}
fi

sudo rm -r ${CORE_CONF_DIRECTORY}
sudo ln -s ${CORE_VAGRANT_CONF_DIRECTORY} ${CORE_CONF_DIRECTORY}

sudo /opt/solr/bin/solr restart
