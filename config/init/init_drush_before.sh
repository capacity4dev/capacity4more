if [ -f "$DIR_CONFIG/drush/drush.phar" ]; then
  cp -af "$DIR_CONFIG/drush/drush.phar" "$DIR_BIN/packagist/"
  chmod +x "$DIR_BIN/packagist/drush.phar"
  message_success "Drush moved to bin/packagist/drush.phar"
else
  message_success "No drush provided in this repository"
fi