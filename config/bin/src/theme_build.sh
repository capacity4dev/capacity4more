################################################################################
# Functionality to build the theme using Grunt.
################################################################################

##
# Build the theme.
#
# Params:
# string $1
#   the grunt task to build.
##
function theme_build {
  theme_build_bundle
  theme_build_npm
  theme_build_grunt $1
}

##
# Install/update the bower modules.
##
function theme_build_bundle {
  cd "$DIR_PROJECT/profiles/capacity4more/themes/c4m/kapablo/build"

  bundle install

  cd "$DIR_ROOT"
}

##
# Install/update the NodeJS modules.
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
# Run the Grunt task(s).
#
# string $1
#   the grunt task to build.
##
function theme_build_grunt {
  cd "$DIR_PROJECT/profiles/capacity4more/themes/c4m/kapablo/build"

  node_modules/grunt-cli/bin/grunt $1

  cd "$DIR_ROOT"
}
