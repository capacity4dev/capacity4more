################################################################################
# Functionality to build the theme using Grunt.
################################################################################

##
# Build the Angular application.
#
# Params:
# string $1
#   the grunt task to build.
##
function angular_build {
  angular_build_npm
  angular_build_grunt $1
  angular_bower_install
}

##
# Install/update the NodeJS modules.
#
# The modules will only be installed if they are not installed yet.
# The modules will only be updated if the --no-update option is not passed.
##
function angular_build_npm {
  cd "$DIR_PROJECT/profiles/capacity4more/modules/c4m/restful/c4m_restful_quick_post/components/c4m-app"

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
function angular_build_grunt {
  cd "$DIR_PROJECT/profiles/capacity4more/modules/c4m/restful/c4m_restful_quick_post/components/c4m-app"

  grunt $1

  # Symlink to the application file `c4m-app.js`.
  rm "$DIR_PROJECT/profiles/capacity4more/libraries/bower_components/c4m-app/dist/c4m-app.js"
  ln -s "$DIR_PROJECT/profiles/capacity4more/modules/c4m/restful/c4m_restful_quick_post/components/c4m-app/dist/c4m-app.js" "$DIR_PROJECT/profiles/capacity4more/libraries/bower_components/c4m-app/dist/c4m-app.js"

  cd "$DIR_ROOT"
}

##
# Install bower dependencies
##
function angular_bower_install {
  cd "$DIR_ROOT"

  bower cache clean
  bower install $DIR_PROJECT/profiles/capacity4more/modules/c4m/restful/c4m_restful_quick_post/components/c4m-app

  cd "$DIR_ROOT"
}
