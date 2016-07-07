# Solr Vagrant box

A [Vagrant](https://www.vagrantup.com/) box to speed up the setup of an environment with [Apache Solr](http://lucene.apache.org/solr/) version 5 installed.

## Configuration

By default, a Solr core will be created with the name which is configured in `/core/core.properties`.
Update this if you want to use another name for this core.

## Setup Vagrant box

Run the following command in the root of this folder to setup the Vagrant box with it's dependencies:

```
$ vagrant up
```

Wait until the installation process is complete.

## Usage

The Solr instance will be available at `http://localhost:4567`.
The name of the core will be the one which is configured in `/core/core.properties`, see Configuration step above.
