
################################################################################
# Use this file to add custom script steps that should run before the
# installation of Drupal is started.
################################################################################


# Add symlinks from the project directory.
markup_h1 "Symlink project profiles, modules, themes and libraries."

markup_h2 "Profiles"
file_symlink_subdirectories "$DIR_PROJECT/profiles" "$DIR_WEB/profiles"

markup_h2 "Modules"
mkdir -p "$DIR_WEB/sites/all/modules"
file_symlink_subdirectories "$DIR_PROJECT/modules" "$DIR_WEB/sites/all/modules"

markup_h2 "Themes"
mkdir -p "$DIR_WEB/sites/all/themes"
file_symlink_subdirectories "$DIR_PROJECT/themes" "$DIR_WEB/sites/all/themes"

markup_h2 "Libraries"
mkdir -p "$DIR_WEB/sites/all/libraries"
file_symlink_subdirectories "$DIR_PROJECT/libraries" "$DIR_WEB/sites/all/libraries"
