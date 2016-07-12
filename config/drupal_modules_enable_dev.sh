################################################################################
# Modules that need to be enabled on a development environment.
#
# Do not list dependencies of modules you want to enable,
# they will be automatically enabled when the depending module is installed.
################################################################################

MODULES_ENABLE=(
  "devel"
  "devel_generate"
  "context_ui"
  "field_ui"
  "message_notify"
  "message_subscribe"
  "views_ui"
)
