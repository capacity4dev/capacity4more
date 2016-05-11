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

markup_h2 "Solr server configuration"
prompt "Core name" "$INIT_CONFIG_SOLR_NAME"
INIT_CONFIG_SOLR_NAME="${REPLY}"
prompt "Hostname" "$INIT_CONFIG_SOLR_HOST"
INIT_CONFIG_SOLR_HOST="${REPLY}"
prompt "Port number" "$INIT_CONFIG_SOLR_PORT"
INIT_CONFIG_SOLR_PORT="${REPLY}"
prompt "Path" "$INIT_CONFIG_SOLR_PATH"
INIT_CONFIG_SOLR_PATH="${REPLY}"
markup

markup_h2 "TIKA configuration ${GREY}(extract document content)"
prompt "Path to jar file" "$INIT_CONFIG_TIKA_PATH"
INIT_CONFIG_TIKA_PATH="${REPLY}"
prompt "Jar file name" "$INIT_CONFIG_TIKA_FILE"
INIT_CONFIG_TIKA_FILE="${REPLY}"

markup_h2 "LDAP configuration"
prompt "Path to jar file" "$INIT_CONFIG_LDAP_URL"
INIT_CONFIG_LDAP_URL="${REPLY}"
prompt "Jar file name" "$INIT_CONFIG_LDAP_API"
INIT_CONFIG_LDAP_API="${REPLY}"

markup_h2 "Memcached server ${GREY}(Leave values empty if no memcache in use)"
prompt "Host name" "$INIT_CONFIG_MEMCACHE_HOST"
INIT_CONFIG_MEMCACHE_HOST="${REPLY}"
prompt "Port number" "$INIT_CONFIG_MEMCACHE_PORT"
INIT_CONFIG_MEMCACHE_PORT="${REPLY}"
markup

markup_h2 "Migration paths ${GREY}(Leave values empty if no migration should be configured)"
prompt "Migration module" "$INIT_CONFIG_MIGRATION_MODULE"
INIT_CONFIG_MIGRATION_MODULE="${REPLY}"
prompt "Migration script" "$INIT_CONFIG_MIGRATION_SCRIPT"
INIT_CONFIG_MIGRATION_SCRIPT="${REPLY}"
markup

markup_h2 "Migration D6 configuration ${GREY}(Leave values empty if no migration should be configured)"
prompt "Migration source database host" "$INIT_CONFIG_MIGRATION_HOST"
INIT_CONFIG_MIGRATION_HOST="${REPLY}"
prompt "Migration source database name" "$INIT_CONFIG_MIGRATION_DB"
INIT_CONFIG_MIGRATION_DB="${REPLY}"
prompt "Migration source database user" "$INIT_CONFIG_MIGRATION_USER"
INIT_CONFIG_MIGRATION_USER="${REPLY}"
prompt "Migration source database password" "$INIT_CONFIG_MIGRATION_PASS"
INIT_CONFIG_MIGRATION_PASS="${REPLY}"
prompt "Migration source files directory" "$INIT_CONFIG_MIGRATION_FILES"
INIT_CONFIG_MIGRATION_FILES="${REPLY}"
markup
