#!/bin/bash

# No need for special config if the profile is not installed.
if [ "$INSTALL_PROFILE" -ne 1 ]; then
 exit 0;
fi

drush @capacity4more watchdog-show --severity=error --count=100
