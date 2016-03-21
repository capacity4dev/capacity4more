################################################################################
# Modules that need to be enabled after the installation.
#
# Do not list dependencies of modules you want to enable,
# they will be automatically enabled when the depending module is installed.
################################################################################

MODULES_ENABLE=(
  # Administration.
  "admin_views"
  "adminimal"
  "adminimal_admin_menu"
  "module_filter"
  # Minimal.
  "ctools"
  "entity"
  "entityreference"
  "jquery_update"
  "libraries"
  "pathauto"
  "redirect"
  "token"
  "transliteration"
  "views"
  "views_bulk_operations"
)
