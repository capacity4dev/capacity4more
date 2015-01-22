#!/bin/sh

# ---------------------------------------------------------------------------- #
#
# Updates composer and make sure that the .composer/vendor/bin path is
# available for the travis user.
#
# ---------------------------------------------------------------------------- #


# Update composer.
composer self-update

# Make sure the composer/vendor/bin path is availabe for all.
sed -i '1i export PATH="$HOME/.composer/vendor/bin:$PATH"' $HOME/.bashrc
source $HOME/.bashrc
