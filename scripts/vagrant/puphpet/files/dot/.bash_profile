#!/bin/bash

##
# Add the composer bin directory to the $PATH variable so commands provided by
# composer packages can be run without using the full path.
##
export PATH="$HOME/.composer/vendor/bin:$PATH"
