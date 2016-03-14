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

markup_h2 "Solr server configuration"
markup_li_value "Core name" "${INIT_CONFIG_SOLR_NAME:--}"
markup_li_value "Hostname" "${INIT_CONFIG_SOLR_HOST:--}"
markup_li_value "Port" "${INIT_CONFIG_SOLR_PORT:--}"
markup_li_value "Path" "${INIT_CONFIG_SOLR_PATH:--}"

markup_h2 "TIKA file configuration"
markup_li_value "File path" "${INIT_CONFIG_TIKA_PATH:--}"
markup_li_value "File name" "${INIT_CONFIG_TIKA_FILE:--}"

markup

markup_h2 "Memcached server configuration"
markup_li_value "Hostname" "${INIT_CONFIG_MEMCACHE_HOST:--}"
markup_li_value "Port number" "${INIT_CONFIG_MEMCACHE_PORT:--}"
