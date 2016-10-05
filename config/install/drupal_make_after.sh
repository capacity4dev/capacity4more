
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

markup_h2 "Files"
mkdir -p "$DIR_WEB/$FILE_PATH_PUBLIC"
mkdir -p "$DIR_WEB/$FILE_PATH_PRIVATE"

if [ "$FILE_PATH_PRIVATE" != "" ]; then

    drupal_sites_default_unprotect
cat << EOF >> "$DIR_WEB/$FILE_PATH_PRIVATE/.htaccess"
Deny from all

# Turn off all options we don't need.
Options None
Options +FollowSymLinks

# Set the catch-all handler to prevent scripts from being executed.
SetHandler Drupal_Security_Do_Not_Remove_See_SA_2006_006

# Override the handler again if we're run later in the evaluation list.
SetHandler Drupal_Security_Do_Not_Remove_See_SA_2013_003


# If we know how to do it safely, disable the PHP engine entirely.

php_flag engine off
EOF

else
    echo
    echo
    echo
    markup_h2 "Please add your FILE_PATH_PRIVATE to your config.sh!!"
    echo
    echo
    echo
fi

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

markup_h2 "Robots.txt"
cp -a "$DIR_ROOT/config/install/assets/robots.txt" "$DIR_WEB"
message_success "Custom robots.txt file copied to web folder."

markup_h2 "Plupload examples folder"
rm -Rf "$DIR_WEB/sites/all/libraries/plupload/examples"
message_success "Removed plupload examples folder from web directory."
