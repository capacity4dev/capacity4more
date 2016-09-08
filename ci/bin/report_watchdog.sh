#!/bin/sh
set -e

drush @capacity4more watchdog-show --severity=error --count=100
