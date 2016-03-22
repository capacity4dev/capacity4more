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

# Load the SOLR config.
INIT_CONFIG_SOLR_NAME="${SOLR_NAME}"
INIT_CONFIG_SOLR_HOST="${SOLR_HOST}"
INIT_CONFIG_SOLR_PORT="${SOLR_PORT}"
INIT_CONFIG_SOLR_PATH="${SOLR_PATH}"

# Load the TIKA config.
INIT_CONFIG_TIKA_PATH="${TIKA_PATH}"
INIT_CONFIG_TIKA_FILE="${TIKA_FILE}"

# Load the memcached config.
INIT_CONFIG_MEMCACHE_HOST="${MEMCACHE_HOST}"
INIT_CONFIG_MEMCACHE_PORT="${MEMCACHE_PORT}"

# Load the migration config.
INIT_CONFIG_MIGRATION_MODULE="${MIGRATION_MODULE}"
INIT_CONFIG_MIGRATION_SCRIPT="${MIGRATION_SCRIPT}"

INIT_CONFIG_MIGRATION_HOST="${MIGRATION_HOST}"
INIT_CONFIG_MIGRATION_DB="${MIGRATION_DB}"
INIT_CONFIG_MIGRATION_USER="${MIGRATION_USER}"
INIT_CONFIG_MIGRATION_PASS="${MIGRATION_PASS}"
INIT_CONFIG_MIGRATION_FILES="${MIGRATION_FILES}"