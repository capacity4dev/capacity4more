################################################################################
# List files and directories that should be deleted before a new installation.
# All PATHS are relative to the root of Drupal or are fully prefixed using the
# script path variables (see bin/src/bootstrap.sh).
################################################################################


# Files to be deleted before the script is run.
CLEANUP_FILES=(
)

# Directories to be deleted before the script is run.
CLEANUP_DIRECTORIES=(
  "$DIR_WEB"
)
