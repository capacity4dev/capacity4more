#!/usr/bin/env bash

PROJECT_FOLDER='cap4more-moodle'
PROJECT_SERVER_NAME='moodle.cap4more.dev'

DB_USER='cap4more_moodle'
DB_PASSWORD='c4p4city4m0re'
DB_NAME='capacity4more_moodle'

ADMIN_NAME='cap4more_moodle'
ADMIN_PASSWORD='c4p4m0re_m00dl3'
ADMIN_EMAIL="hello@${PROJECT_SERVER_NAME}"

# Update
sudo apt-get update

# Apache & PHP
sudo apt-get install apache2 -y
sudo apt-get install php5 php5-gd php5-curl -y

# MySQL
sudo debconf-set-selections <<< "mysql-server mysql-server/root_password password ${DB_PASSWORD}"
sudo debconf-set-selections <<< "mysql-server mysql-server/root_password_again password ${DB_PASSWORD}"
sudo apt-get install mysql-server -y
sudo apt-get install php5-mysql
# Create database and user
mysql -uroot -p${DB_PASSWORD} -e "CREATE USER '${DB_USER}'@'localhost' IDENTIFIED BY '${DB_PASSWORD}'"
mysql -uroot -p${DB_PASSWORD} -e "CREATE DATABASE ${DB_NAME}"
mysql -uroot -p${DB_PASSWORD} -e "GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'localhost'"
mysql -uroot -p${DB_PASSWORD} -e "FLUSH PRIVILEGES"

# VHost file
# setup hosts file
VHOST=$(cat <<EOF
<VirtualHost *:80>
  ServerAdmin webmaster@localhost

  # Change this your local domain name.
  # Don't forget to add it to the /etc/hosts file.
  ServerName	${PROJECT_SERVER_NAME}

  # Change the DocumentRoot to the root path of your project.
  # Do not add a trailing / to the path.
  DocumentRoot /var/www/${PROJECT_FOLDER}/web

  # Change the Directory to the root path of your project.
  # Do not forget to add the trailing / to the path.
  <Directory /var/www/${PROJECT_FOLDER}/web/>
    Options Indexes FollowSymLinks MultiViews

    AllowOverride All
    <IfModule mod_authz_core.c>
      Require all granted
    </IfModule>
    <IfModule !mod_authz_core.c>
      Order allow,deny
      Allow from all
    </IfModule>
  </Directory>

  # Change the name of the log files corresponding the domain name.
  ErrorLog /var/log/apache2/${PROJECT_SERVER_NAME}-http-error.log
  LogLevel warn
  CustomLog /var/log/apache2/${PROJECT_SERVER_NAME}-http-access.log combined

</VirtualHost>
EOF
)
echo "${VHOST}" > /etc/apache2/sites-available/${PROJECT_SERVER_NAME}.conf
sudo ln -s ../sites-available/${PROJECT_SERVER_NAME}.conf /etc/apache2/sites-enabled/${PROJECT_SERVER_NAME}.conf

# Enable mod_rewrite
sudo a2enmod rewrite

# Restart Apache
sudo service apache2 restart

# Git
sudo apt-get install git -y

# Project requirements
sudo apt-get install unzip -y

# Create project folder
sudo rm -Rf "/var/www/${PROJECT_FOLDER}"
sudo mkdir "/var/www/${PROJECT_FOLDER}"
sudo mkdir "/var/www/${PROJECT_FOLDER}/moodledata"

# Initiate the project
cd "/var/www/${PROJECT_FOLDER}"
# Clone the repository
git clone git://git.moodle.org/moodle.git web
# Go to repository folder
cd "/var/www/${PROJECT_FOLDER}/web"
# Checkout the correct branch
git branch --track MOODLE_29_STABLE origin/MOODLE_29_STABLE
git checkout MOODLE_29_STABLE
# Make sure the repository is up to date
git pull

# Install the DrupalServices Moodle plugin
cd "/var/www/${PROJECT_FOLDER}/web/auth"
wget https://github.com/cannod/moodle-drupalservices/archive/master.zip
unzip master.zip
mv moodle-drupalservices-master/ drupalservices/
rm master.zip

# Install Moodle via CLI
cd "/var/www/${PROJECT_FOLDER}/web"
php admin/cli/install.php \
  --chmod=2777 \
  --lang=en \
  --wwwroot="http://${PROJECT_SERVER_NAME}" \
  --dataroot="/var/www/${PROJECT_FOLDER}/moodledata" \
  --dbhost=localhost \
  --dbname=${DB_NAME} \
  --dbuser=${DB_USER} \
  --dbpass=${DB_PASSWORD} \
  --dbport=3306 \
  --dbsocket=1 \
  --fullname='Capacity4more Moodle' \
  --shortname='Capacity4more Moodle' \
  --adminuser=${ADMIN_NAME} \
  --adminpass=${ADMIN_PASSWORD} \
  --adminemail=${ADMIN_EMAIL} \
  --non-interactive \
  --agree-license
