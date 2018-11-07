core = 7.x
api = 2

; Modules that every project (should) need.

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.12"
projects[ctools][patch][] = "https://www.drupal.org/files/issues/2067997-reload-plugins-class-7.patch"

projects[entity][subdir] = "contrib"
projects[entity][version] = "1.8"

projects[entityreference][subdir] = "contrib"
projects[entityreference][version] = "1.5"
projects[entityreference][patch][] = "https://www.drupal.org/files/entity_reference-attach_selection_handler_on_form_element-2014535-1.patch"

projects[jquery_update][subdir] = "contrib"
projects[jquery_update][version] = "3.0-alpha3"

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "2.3"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.3"

projects[redirect][subdir] = "contrib"
projects[redirect][version] = "1.0-rc3"

projects[path_redirect_import][subdir] = "contrib"
projects[path_redirect_import][version] = "1.0-rc4"

projects[token][subdir] = "contrib"
projects[token][version] = "1.7"

projects[transliteration][subdir] = contrib
projects[transliteration][version] = "3.2"
