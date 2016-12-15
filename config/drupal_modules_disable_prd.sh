################################################################################
# Modules that need to be disabled after the installation for the
# production environment.
#
# Some profiles (like default) enable more modules then realy needed.
# List their names so they will be disabled after the installation has finished.
################################################################################

MODULES_DISABLE=(
  "admin_menu"
  "context_ui"
  "field_ui"
  "views_ui"
)
