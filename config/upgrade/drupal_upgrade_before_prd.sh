# Build the theme files.
markup_h1 "Build the Theme."
source "$DIR_CONFIG_SRC/theme_build.sh"
theme_build build
echo

# Build the Angular app.
markup_h1 "Build the Angular app."
source "$DIR_CONFIG_SRC/angular_build.sh"
angular_build build
echo

source "$DIR_CONFIG/install/drupal_install_config.sh"
drupal_sites_default_unprotect
markup_h1 "Create settings.php file."
drupal_sites_default_create_settings
markup_h1 "Copy local config override file."
drupal_sites_default_config_link
drupal_sites_default_config_protect
echo
drupal_sites_default_protect
