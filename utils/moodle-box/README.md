# Capacity4more Moodle Vagrant box

A [Vagrant](https://www.vagrantup.com/) box to speed up the setup of an environment with a Moodle platform installation.

## Setup Vagrant box

Run the following command in the root of this folder to setup the Vagrant box with it's dependencies:

```
$ vagrant up
```

Wait until the installation process is complete.

## Local environment preparation

The Vagrant box will run at IP address `192.168.50.98`, create therefore the following entry in your local hosts file.

```
192.168.50.98   moodle.cap4more.dev
```

This way you will be able to access the Moodle environment using `http://moodle.cap4more.dev`.
In case you want to use another URL, use your preferred URL in your hosts file and don't forget to alter
the variable `PROJECT_SERVER_NAME` in the file `bootstrap.sh` accordingly.

## Moodle platform installation

The Moodle platform installation is also automatically initiated when the Vagrant box is provisioned.
Also the DrupalServices plugin for Moodle is downloaded and extracted in the right folder.
Normally the Moodle platform installation also installs the DrupalServices module right away.

However, the DrupalServices plugin still needs to be configured manually.

### DrupalServices plugin configuration

In case the DrupalServices plugin is not available in the Plugin overview to be found at 
`Site administration >︎ Plugins >︎ Authentication >︎ Manage authentication`, please install the DrupalServices plugin first.

Go to `Site administration >︎ Plugins >︎ Authentication >︎ Manage authentication` and click on the `Settings`-link to go
to the configuration page of the DrupalServices plugin.

By default the 'Drupal Website URL' settings will be set to the URL of the Moodle platform,
but of course this is not correct in our case.
Update the 'Drupal Website URL' to the Capacity4more development website running on your local machine and
click 'Save changes'.
