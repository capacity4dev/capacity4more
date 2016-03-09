################################################################################
# When the bin/init command is run, the config variables are collected and
# written to the config.sh file.
#
# This file is used to prompt for custom configuration values.
#
# Use the "prompt" helper to ask the user for input.
# The helper has 2 parameters:
# - The question text.
# - An optional current value.
#
# Save the collected value by assigning the $REPLY value to the INIT_CONFIG_X
# variable:
#
# Example:
#
# markup_h2 "Custom variables"
# prompt "Custom variable" "$INIT_CONFIG_CUSTOM_VARIABLE"
# INIT_CONFIG_CUSTOM_VARIABLE="${REPLY}"
# echo
#
################################################################################

#markup_h2 "Custom variables"
#prompt "Custom variable" "$INIT_CONFIG_CUSTOM_VARIABLE"
#INIT_CONFIG_CUSTOM_VARIABLE="${REPLY}"
#echo
