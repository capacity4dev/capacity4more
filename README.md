[![Build Status](https://img.shields.io/travis/capacity4dev/capacity4more/develop.svg?style=flat-square)](https://travis-ci.org/capacity4dev/capacity4more)
[![Quality Score](https://img.shields.io/scrutinizer/g/capacity4dev/capacity4more.svg?style=flat-square)](https://scrutinizer-ci.com/g/capacity4dev/capacity4more/)



# capacity4more

A Drupal 7 powered distribution providing a community platform to share
knowledge.



## Installation

**Warning:** you need to setup [Drush](https://github.com/drush-ops/drush)
first or the installation and update scripts will not work.

Clone the project from [GitHub](https://github.com/capacity4dev/capacity4more).

#### Create config file

Copy the example configuration file to config.sh:

	$ cp default.config.sh config.sh 

Edit the configuration file, fill in the blanks.


#### Run the install script

Run the install script from within the root of the repository:

	$ ./install

The profile has a module to load demo data in to the platform.
Loading that data during install can be requested by adding -d top the command:

  $ ./install -d
	
	
#### Configure web server

Create a vhost for your webserver, point it to the `REPOSITORY/ROOT/www` folder.  
(Restart/reload your webserver).

Add the local domain to your ```/etc/hosts``` file.

Open the URL in your favorite browser.



## Reinstall

You can Reinstall the platform any type by running the install script.

	$ ./install

	
#### The install script will perform following steps:

1. Delete the /www folder.
2. Recreate the /www folder.
3. Download and extract all contrib modules, themes & libraries to the proper
   subfolders of the profile.
4. Download and extract Drupal 7 core in the /www folder
5. Create an empty sites/default/files directory
6. Makes a symlink within the /www/profiles directory to the /capacity4more
   directory.
7. Run the Drupal installer (Drush) using the capacity4more profile.

#### Warning!

* The install script will not preserve the data located in the
  sites/default/files directory.
* The install script will clear the database during the installation.

**You need to take backups before you run the install script!**



## Upgrade

It is also possible to upgrade Drupal core and contributed modules and themes
without destroying the data in tha database and the sites/default directory.

Run the update script:

	$ ./upgrade

The profile has a module to load demo data in to the platform.
Loading or updating that data during an upgrade can be requested by
adding -d top the command:

  $ ./upgrade -d

	
#### The upgrade script will perform following steps:

1. Create a backup of the sites/default folder.
2. Delete the /www folder.
3. Recreate the /www folder.
4. Download and extract all contrib modules, themes & libraries to the proper
   subfolders of the profile.
5. Download and extract Drupal 7 core in the /www folder.
6. Makes a symlink within the /www/profiles directory to the
   /capacity4more 7. directory.
7. Restore the backup of the sites/default folder.



## Unit testing
   
### Install requirements

For testing use Behat with PhantomJS.

#### Install Behat 

To run our tests, we need behat (and some extensions). With composer installed, we can quickly install the right versions: 

```
$ cd /PATH/TO/capacity4more/capacity4more/behat
$ composer install
```

This will download the right versions of all dependencies into the behat/bin folder.

#### Install PhantomJS

To test javascript behaviour we need to install PhantomJs:

```
$ sudo npm install -g phantomjs
```

You need to start the webdriver before you start the tests:

```
$ cd /PATH/TO/capacity4more/capacity4more/behat
$ phantomjs --webdriver=4444
```


### Configure Behat

Behat needs a configuration file. Copy the example file and fill in the local configuration parameters.

```
$ cd /PATH/TO/capacity4more/capacity4more/behat
$ cp behat.local.yml.example behat.local.yml
$ vi behat.local.yml
```


### Run tests

Executing behat is as simple as running

```
$ cd /PATH/TO/capacity4more/capacity4more/behat
$ ./bin/behat
```

This will run all tests.

#### Run specific tests

If you only want to test the API and don't need the JavaScript tests (or you don't have PhantomJS installed/running), you can add tags to our scenarios and only execute them.

There are 2 default tags in use:

**@api** : Run all tests that **don't require** PhantomJs:

```
$ cd /PATH/TO/capacity4more/capacity4more/behat
$ ./bin/behat --tags=@api
```

**@javascript** : Run only the tests that **require** PhantomJs:

```
$ cd /PATH/TO/capacity4more/capacity4more/behat
$ ./bin/behat --tags=@javascript
```
