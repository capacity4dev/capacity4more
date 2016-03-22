################################################################################
# Set of CI environment make files that need to be run before the installation.
# These are run after the files in the make.sh file.
#
# The make files in this array will only be installed if the environment = ci.
################################################################################

MAKE_FILES=(
  "migrate.make"
  "c4d_migrate.make"
)
