[![Build Status](https://img.shields.io/travis/capacity4dev/capacity4more/develop.svg?style=flat-square)](https://travis-ci.org/capacity4dev/capacity4more)
[![Quality Score](https://img.shields.io/scrutinizer/g/capacity4dev/capacity4more.svg?style=flat-square)](https://scrutinizer-ci.com/g/capacity4dev/capacity4more/)

# capacity4more

A Drupal 7 powered distribution providing a community platform to share
knowledge.

## Requirements

- Bower (`npm install -g bower`)
- Grunt and grunt-cli (`npm install -g grunt grunt-cli`)
- Gulp (`npm install -g gulp`)
- Sass (`sudo gem install sass`)

## Installation

Clone the project from [GitHub](https://github.com/capacity4dev/capacity4more).

    $ git clone --recursive https://github.com/capacity4dev/capacity4more.git

### Initialize configuration

When we first clone the repository, we need to initialize it:

    $ bin/init
    
Keep in mind to configure the proper installation profile, which is "capacity4more" in our case!
    
This script will:
1. Create the config/config.sh file based on the config/config_example.sh file.
2. Ask you for the config variables (db credentials, website details, ...).
3. Install composer locally (bin/composer)
4. Install a local version of drush.
5. Detect any custom commands and add them to the bin directory.

### Run the install script

Run the install script from within the root of the repository:

	$ bin/install
	
The install command has a few optional options:

```
Options:
  --no-backup           Do not take a backup before the installation is run.
  --no-login            Do not open a webbrowser and login to the website when
                        the installation is finished.
  --dummy-content       Execute dummy content migration after installation.
  --env=<name>          The environment to run the script for (default : dev)
  --help (-h)           Show this help text.
  --hook-info           Show information about the available hooks.
  --no-color            Disable all colored output.
  --confirm (-y)        Skip the confirmation step when the script starts.
  --verbose (-v)        Verbose.
```
	
### Configure web server

Create a vhost for your webserver, point it to the `REPOSITORY/ROOT/web` folder.
(Restart/reload your webserver).

Add the local domain to your ```/etc/hosts``` file.

Open the URL in your favorite browser.

## Upgrade

It is also possible to upgrade Drupal core and contributed modules and themes
without destroying the data in tha database and the sites/default directory.

Run the update script:

	$ bin/upgrade

## Reset

Will destroy the database and install the capacity4more profile again.

Run the reset script:

    $ bin/reset

## Unit testing
   
### Install requirements

For testing use Behat with PhantomJS.

#### Install Behat 

To run our tests, we need behat (and some extensions). With composer installed, we can quickly install the right versions: 

```
$ cd /PATH/TO/project/profiles/capacity4more/behat
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
$ cd /PATH/TO/project/profiles/capacity4more/behat
$ phantomjs --webdriver=4444
```


### Configure Behat

Behat needs a configuration file. Copy the example file and fill in the local configuration parameters.

```
$ cd /PATH/TO/project/profiles/capacity4more/behat
$ cp behat.local.yml.example behat.local.yml
$ vi behat.local.yml
```


### Run tests

Executing behat is as simple as running

```
$ cd /PATH/TO/project/profiles/capacity4more/behat
$ ./bin/behat
```

This will run all tests.

#### Run specific tests

If you only want to test the API and don't need the JavaScript tests (or you don't have PhantomJS installed/running), you can add tags to our scenarios and only execute them.

There are 2 default tags in use:

**@api** : Run all tests that **don't require** PhantomJs:

```
$ cd /PATH/TO/project/profiles/capacity4more/behat
$ ./bin/behat --tags=@api
```

**@javascript** : Run only the tests that **require** PhantomJs:

```
$ cd /PATH/TO/project/profiles/capacity4more/behat
$ ./bin/behat --tags=@javascript
```
#### Running Coder Tests
In order to run Coder's sniffing tests, run the following command from the project's root directory:
```
$ CODE_REVIEW=1 TRAVIS_BUILD_DIR='.' ./ci/bin/run_coder.sh
```

## Powered by [druleton][link-druleton]

[![Powered by Druleton][icon-druleton]][link-druleton]

This project is using the [druleton][link-druleton] to support
storing it in version control without the need to store also core & contributed
modules, themes and libraries.

See the [druleton documentation][link-druleton-doc] as included in
this project.

[link-druleton]: https://github.com/druleton/druleton
[link-druleton-doc]: https://github.com/druleton/druleton/blob/master/docs/README.md

[icon-druleton]: https://img.shields.io/badge/powered%20by-druleton-blue.svg?style=flat-square
[link-druleton]: https://github.com/druleton/druleton
