core = 7.x
api = 2

; Views

projects[draggableviews][subdir] = "contrib"
projects[draggableviews][version] = "2.1"

projects[views][subdir] = "contrib"
projects[views][version] = "3.14"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "3.3"
projects[views_bulk_operations][patch][] = "https://www.drupal.org/files/issues/1334374-36-use_generic_entity_tables.patch"
projects[views_bulk_operations][patch][] = "https://www.drupal.org/files/issues/2334625-6-fix-vbo-select-all-on-last-page.patch"

projects[views_load_more][subdir] = "contrib"
projects[views_load_more][version] = "1.5"
projects[views_load_more][patch][] = "https://www.drupal.org/files/1330574_different_item_count_on_first_page_refactored_1.patch"

projects[draggableviews][subdir] = "contrib"
projects[draggableviews][version] = "2.1"
projects[draggableviews][patch][] = "https://www.drupal.org/files/issues/draggableviews-2343793-16.patch"

projects[views_contextual_filters_or][subdir] = "contrib"
projects[views_contextual_filters_or][version] = "1.x-dev"

projects[views_access_callback][subdir] = "contrib"
projects[views_access_callback][version] = "1.x-dev"
