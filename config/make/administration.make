core = 7.x
api = 2

; Modules to make the life of a Drupal admin more pleasant.

projects[admin_menu][subdir] = "contrib"
projects[admin_menu][version] = "3.0-rc5"

projects[admin_views][subdir] = "contrib"
projects[admin_views][version] = "1.6"

projects[adminimal_admin_menu][subdir] = "contrib"
projects[adminimal_admin_menu][version] = "1.7"
; https://www.drupal.org/node/2598278
projects[adminimal_admin_menu][patch][] = https://www.drupal.org/files/issues/adminimal_admin_menu-js-error-2407007-3-no-whitespace-changes.patch
projects[adminimal_admin_menu][patch][] = https://www.drupal.org/files/issues/adminimal_admin_menu-js-error-2407007-3.patch

projects[module_filter][subdir] = "contrib"
projects[module_filter][version] = "2.1"

projects[better_formats][subdir] = "contrib"
projects[better_formats][version] = "1.0-beta2"

projects[blockreference][subdir] = "contrib"
projects[blockreference][version] = "2.4"

projects[context][subdir] = "contrib"
projects[context][version] = "3.7"
projects[context][patch][] = https://www.drupal.org/files/issues/context-2742913-5.patch

projects[context_block_disable][subdir] = "contrib"
projects[context_block_disable][version] = "2.1"

projects[context_local_tasks][subdir] = "contrib"
projects[context_local_tasks][version] = "1.0-alpha1"

projects[context_no_title][subdir] = "contrib"
projects[context_no_title][version] = "1.0"

projects[context_og][subdir] = "contrib"
projects[context_og][version] = "2.1"

projects[eu_cookie_compliance][subdir] = "contrib"
projects[eu_cookie_compliance][version] = "1.18"

projects[elysia_cron][subdir] = "contrib"
projects[elysia_cron][version] = "2.4"
projects[elysia_cron][patch][] = "https://www.drupal.org/files/issues/elysia_cron-exported-code-cs-2930214-7.x-2.4_0.patch"

projects[entityreference_prepopulate][subdir] = "contrib"
projects[entityreference_prepopulate][version] = "1.7"

projects[file_entity][subdir] = "contrib"
projects[file_entity][version] = "2.15"

projects[file_download_count][subdir] = "contrib"
projects[file_download_count][version] = "1.0-rc1"
projects[file_download_count][patch][] = "../patches/file-download-count-skip-download-count.patch"

projects[inline_entity_form][subdir] = "contrib"
projects[inline_entity_form][version] = "1.8"

projects[mefibs][subdir] = "contrib"
projects[mefibs][version] = "1.x-dev"

projects[masquerade][subdir] = "contrib"
projects[masquerade][version] = "1.0-rc7"

projects[plupload][subdir] = "contrib"
projects[plupload][version] = "2.x-dev"

projects[save_draft][subdir] = "contrib"
projects[save_draft][version] = "1.4"

projects[smart_trim][subdir] = "contrib"
projects[smart_trim][version] = "1.5"

projects[summary_settings][subdir] = "contrib"
projects[summary_settings][version] = "1.x-dev"

projects[variable][subdir] = "contrib"
projects[variable][version] = "2.5"

projects[ds][subdir] = "contrib"
projects[ds][version] = "2.14"

projects[flag][subdir] = "contrib"
projects[flag][version] = "3.9"
projects[flag][patch][] = "../patches/flag-array-check-1925922.patch"

projects[node_gallery][subdir] = "contrib"
projects[node_gallery][version] = "1.1"
projects[node_gallery][patch][] = https://www.drupal.org/files/issues/node_gallery-entity-delete-exception-2006772-1.patch
projects[node_gallery][patch][] = "../patches/node-gallery-unpublished-frontend.patch"

projects[queue_ui][subdir] = "contrib"
projects[queue_ui][version] = "2.x-dev"

projects[restful][download][type] = "git"
projects[restful][download][url] = "https://github.com/Gizra/restful.git"
projects[restful][download][branch] = 7.x-1.x
projects[restful][subdir] = "contrib"
projects[restful][type] = "module"
projects[restful][patch][] = "../patches/restful-fix-rr.patch"

projects[term_reference_tree][subdir] = "contrib"
projects[term_reference_tree][version] = "1.10"

projects[views_data_export][subdir] = "contrib"
projects[views_data_export][version] = "3.1"
projects[views_data_export][patch][] = https://www.drupal.org/files/issues/views_data_export-permanent-files-1875456-63-beta9-do-not-test.patch

; Themes to upgrade the admin backend.

projects[adminimal_theme][subdir] = "contrib"
projects[adminimal_theme][version] = "1.24"
projects[adminimal_theme][type] = "theme"

; Libraries

libraries[select2][type] = "libraries"
libraries[select2][download][type] = "file"
libraries[select2][download][url] = "https://github.com/ivaynberg/select2/archive/4.0.2.zip"

libraries[plupload][download][type]= "get"
libraries[plupload][download][url] = "https://github.com/moxiecode/plupload/archive/v2.2.1.zip"
libraries[plupload][directory_name] = "plupload"
libraries[plupload][destination] = "libraries"

libraries[leaflet_draw][download][type]= "get"
libraries[leaflet_draw][download][url] = "https://github.com/Leaflet/Leaflet.draw/archive/v0.4.6.zip"
libraries[leaflet_draw][directory_name] = "Leaflet.draw"
libraries[leaflet_draw][destination] = "libraries"
