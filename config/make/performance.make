core = 7.x
api = 2

; Performance optimizations

projects[memcache][subdir] = "contrib"
projects[memcache][version] = "1.5"

projects[display_cache][subdir] = "contrib"
projects[display_cache][version] = "1.3"
projects[display_cache][patch][] = "https://www.drupal.org/files/issues/display_cache-alter-entity-settings-2534466-1.patch"
projects[display_cache][patch][] = "https://www.drupal.org/files/issues/display_cache-replace-node_page_view-2489098-2.patch"

projects[chained_fast][subdir] = "contrib"
projects[chained_fast][version] = "1.0-beta1"

projects[apcu][subdir] = "contrib"
projects[apcu][version] = "1.0-beta1"
