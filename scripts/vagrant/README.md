# Vagrant Box
## Dependencies
### Vagrant
Download and install Vagrant from [http://www.vagrantup.com/downloads](http://www.vagrantup.com/downloads).

```
# OSX/Linux users only.
vagrant plugin install vagrant-bindfs
```

### VirtualBox
Download and install VirtualBox from [http://www.virtualbox.org/](http://www.virtualbox.org/). Don’t forget to install the extension pack.

## Installation
### Configure hosts file
```
# Add an entry to your `hosts` file.
192.168.55.101  capacity4more.eu.dev
```

### Clone project
```
# Clone the project from GitHub.
git clone https://github.com/capacity4dev/capacity4more
cd capacity4more
```
### config.sh
```
# Edit the installation configuration file, fill in the blanks.
# Copy the example configuration file to config.sh.
cp default-vagrant.config.sh config.sh
```

### config.yaml
```
# Create a config-custom.yaml file.
# Make sure to configure the proper paths (source).
cp config.yaml config-custom.yaml
# Note:
#   source
#     This is the path your files are stored on the host machine.
#     Replace the path in front of /www to the git checkout path.
#     Windows users: You must use forward-slash c:/c4m/www or double back-#slash c:\\c4m\\www
```

## Create Virtual Machine
```
# Create the virtual machine.
cd scripts/vagrant
vagrant up
```

## Finished
You can now visit the website on [http://capacity4more.eu.dev:5580](http://capacity4more.eu.dev:5580).
