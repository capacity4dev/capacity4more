################################################################################
# When the bin/init command is run, the config variables are collected and
# written to the config.sh file.
#
# This file prints out the collected custom variables so the user can review
# them.
#
# Use the markup_li_value helper to list the config variable name and value.
#
# The helper has 2 parameters:
# - The variable name.
# - The value.
#
# Use variable substitution (see
# http://tldp.org/LDP/abs/html/parameter-substitution.html) to show a - when no
# value has been entered (variable is empty):
#
# markup_li_value "Custom variable" "${INIT_CONFIG_CUSTOM_VARIABLE:--}"
#
################################################################################

#markup_h2 "Custom variables"
#markup_li_value "Custom variable" "${INIT_CONFIG_CUSTOM_VARIABLE:--}"
