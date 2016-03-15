
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

if [ "$MIGRATION_MODULE" != "" ] || [ "$MIGRATION_SCRIPT" != "" ]; then
    markup_h2 "Migration module"

    if [ "$MIGRATION_MODULE" != "" ]; then
        mkdir -p "$DIR_WEB/sites/all/modules/c4d_migrate"
        ln -s "$MIGRATION_MODULE" "$DIR_WEB/sites/all/modules/c4d_migrate"
        message_success "$MIGRATION_MODULE"
    fi

    if [ "$MIGRATION_SCRIPT" != "" ]; then
        ln -s "$MIGRATION_SCRIPT" "$DIR_WEB/"
        message_success "$MIGRATION_SCRIPT"
    fi
fi