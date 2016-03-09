################################################################################
# When the bin/init command is run, the config variables are collected and
# written to the config.sh file.
#
# This file is used to load the current config variables and store them in
# temporary script variables.
#
# Prefix the variable to store the loaded value with **INIT_CONFIG_**!
#
# INIT_CONFIG_CUSTOM_VARIABLE="${CUSTOM_VARIABLE}"
#
# You can set a default value (if no value is found in the config file) by
# adding `:-default_value` (variable substitution see
# http://tldp.org/LDP/abs/html/parameter-substitution.html) to the
# assignment:
#
# INIT_CONFIG_CUSTOM_VARIABLE="${CUSTOM_VARIABLE:-no value yet}"
#
################################################################################

#INIT_CONFIG_CUSTOM_VARIABLE="${CUSTOM_VARIABLE}"
