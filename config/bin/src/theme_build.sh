################################################################################
# Functionality to build the theme using Gulp.
################################################################################

##
# Build the theme.
#
# Params:
# string $1
#   the gulp task to build.
##
function theme_build {
  theme_build_npm
  theme_build_gulp $1
}

##
# Install / update the NodeJS modules.
#
# The modules will only be installed if they are not installed yet.
# The modules will only be updated if the --no-update option is not passed.
##
function theme_build_npm {
  cd "$DIR_PROJECT/profiles/capacity4more/themes/c4m/kapablo/build"

  if [ ! -d "./node_modules" ]; then
    npm install
  elif [ $( option_is_set "--no-update" ) -ne 1 ]; then
    npm install
  fi

  cd "$DIR_ROOT"
}

##
# Run the Gulp task(s).
#
# string $1
#   the gulp task to build.
##
function theme_build_gulp {
  cd "$DIR_PROJECT/profiles/capacity4more/themes/c4m/kapablo/build"

  gulp $1

  cd "$DIR_ROOT"
}
