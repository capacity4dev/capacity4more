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