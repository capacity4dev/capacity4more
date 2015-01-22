#!/bin/sh
set -e

# ---------------------------------------------------------------------------- #
#
# Installs && configure MySQL server & database(s).
#
# ---------------------------------------------------------------------------- #


echo -e "[server]\nmax_allowed_packet=64M" | sudo tee -a /etc/mysql/conf.d/drupal.cnf
echo -e "\nwait_timeout=300" | sudo tee -a /etc/mysql/conf.d/drupal.cnf
echo -e "\nmax_connections=250" | sudo tee -a /etc/mysql/conf.d/drupal.cnf
sudo service mysql restart
