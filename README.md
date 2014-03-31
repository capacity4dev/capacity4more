[![Build Status](https://travis-ci.org/capacity4dev/capacity4more.png?branch=master)](https://travis-ci.org/capacity4dev/capacity4more)

## Installation

Checkout the project from GitHub.

#### Create config file

Copy the configuration file to config.sh:

	$ cp default.config.sh config.sh 

Edit the configuration file, fill in the blanks.


#### Run the install script

Run the install script from within the root of the repository:

	$ ./install
	
	
#### Configure web server

Create a vhost for your webserver, point it to the `REPOSITORY/ROOT/www` folder.  
(Restart/reload your webserver).

Add the local domain to your ```/etc/hosts``` file.

Open the URL in your favorite browser.



## Update/reinstall

You can update/reinstall the platform any type by running the install script.

	$ ./install
	
#### The install script will perform following steps:

1. Delete the /www folder.
2. Recreate the /www folder.
3. Download and extract all contrib modules, themes & libraries to the proper subfolders of the profile.
4. Download and extract Drupal 7 core in the /www folder
5. Create an empty sites/default/files directory
6. Makes a symlink within the /www/profiles directory to the /capacity4more directory.

#### Warning!

* The install script will not preserve the data located in the sites/default/files directory.
* The insstall script will clear the database during the installation.

**You need to take backups before you run the install script!**





