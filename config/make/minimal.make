core = 7.x
api = 2

; Modules that every project (should) need.

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.9"

projects[entity][subdir] = "contrib"
projects[entity][version] = "1.7"
projects[entity][patch][] = "https://www.drupal.org/files/issues/2086225-entity-access-check-18.patch"

projects[entityreference][subdir] = "contrib"
projects[entityreference][version] = "1.1"
projects[entityreference][patch][] = "https://www.drupal.org/files/entityreference-decode_option_labels-1665818-32_0.patch"

projects[jquery_update][subdir] = "contrib"
projects[jquery_update][version] = "3.0-alpha3"

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "2.2"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.3"

projects[redirect][subdir] = "contrib"
projects[redirect][version] = "1.0-rc3"

projects[token][subdir] = "contrib"
projects[token][version] = "1.6"

projects[transliteration][subdir] = contrib
projects[transliteration][version] = "3.2"
