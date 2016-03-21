################################################################################
# List files and directories that should be deleted before a reset is performed.
# All PATHS are relative to the root of Drupal or are fully prefixed using the
# script path variables (see bin/src/bootstrap.sh).
################################################################################


# Files to be deleted before the script is run.
CLEANUP_FILES=(
  "$DIR_WEB/sites/default/settings.php"
)

# Directories to be deleted before the script is run.
CLEANUP_DIRECTORIES=(
  "$DIR_WEB/sites/default/files"
)
