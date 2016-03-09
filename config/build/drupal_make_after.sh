
################################################################################
# Use this file to add custom script steps that should run after the make files
# have run for the build script.
################################################################################


# Add the custom code from the project folder.
markup_h1 "Copy project profiles, modules, themes and libraries."

markup_h2 "Profiles"
file_copy_subdirectories "$DIR_PROJECT/profiles" "$DIR_WEB/profiles"

markup_h2 "Modules"
mkdir -p "$DIR_WEB/sites/all/modules"
file_copy_subdirectories "$DIR_PROJECT/modules" "$DIR_WEB/sites/all/modules"

markup_h2 "Themes"
mkdir -p "$DIR_WEB/sites/all/themes"
file_copy_subdirectories "$DIR_PROJECT/themes" "$DIR_WEB/sites/all/themes"

markup_h2 "Libraries"
mkdir -p "$DIR_WEB/sites/all/libraries"
file_copy_subdirectories "$DIR_PROJECT/libraries" "$DIR_WEB/sites/all/libraries"


echo
