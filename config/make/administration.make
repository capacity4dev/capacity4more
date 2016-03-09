core = 7.x
api = 2

; Modules to make the life of a Drupal admin more pleasant.

projects[admin_menu][subdir] = "contrib"
projects[admin_menu][version] = "3.0-rc5"

projects[admin_views][subdir] = "contrib"
projects[admin_views][version] = "1.5"

projects[adminimal_admin_menu][subdir] = "contrib"
projects[adminimal_admin_menu][version] = "1.6"

projects[module_filter][subdir] = "contrib"
projects[module_filter][version] = "2.0"

projects[better_formats][subdir] = "contrib"
projects[better_formats][version] = "1.x-dev"

projects[captcha][subdir] = "contrib"
projects[captcha][version] = "1.3"

projects[recaptcha][subdir] = "contrib"
projects[recaptcha][version] = "2.0"

projects[context][subdir] = "contrib"
projects[context][version] = "3.6"

projects[context_block_disable][subdir] = "contrib"
projects[context_block_disable][version] = "1.x-dev"

projects[context_local_tasks][subdir] = "contrib"
projects[context_local_tasks][version] = "1.x-dev"

projects[context_no_title][subdir] = "contrib"
projects[context_no_title][version] = "1.x-dev"

projects[context_og][subdir] = "contrib"
projects[context_og][version] = "2.1"

projects[eu_cookie_compliance][subdir] = "contrib"
projects[eu_cookie_compliance][version] = "1.14"

projects[entity][patch][] = "https://www.drupal.org/files/issues/2086225-entity-access-check-18.patch"
projects[entityreference][patch][] = "https://www.drupal.org/files/entityreference-decode_option_labels-1665818-32_0.patch"

projects[entityreference_prepopulate][subdir] = "contrib"
projects[entityreference_prepopulate][version] = "1.5"

projects[file_entity][subdir] = "contrib"
projects[file_entity][version] = "2.x-dev"

projects[file_download_count][subdir] = "contrib"
projects[file_download_count][version] = "1.0-rc1"

projects[inline_entity_form][subdir] = "contrib"
projects[inline_entity_form][version] = "1.6"

projects[plupload][subdir] = "contrib"
projects[plupload][version] = "1.7"

projects[rules][subdir] = "contrib"
projects[rules][version] = "2.6"

projects[save_draft][subdir] = "contrib"
projects[save_draft][version] = "1.4"

projects[smart_trim][subdir] = "contrib"
projects[smart_trim][version] = "1.5"

projects[summary_settings][subdir] = "contrib"
projects[summary_settings][version] = "1.x-dev"

projects[variable][subdir] = "contrib"
projects[variable][version] = "2.5"

projects[ds][subdir] = "contrib"
projects[ds][version] = "2.11"

projects[flag][subdir] = "contrib"
projects[flag][version] = "3.6"

projects[node_gallery][subdir] = "contrib"
projects[node_gallery][version] = "1.1"

projects[restful][download][type] = "git"
projects[restful][download][url] = "https://github.com/Gizra/restful.git"
projects[restful][download][branch] = 7.x-1.x
projects[restful][subdir] = "contrib"
projects[restful][type] = "module"

projects[term_reference_tree][subdir] = "contrib"
projects[term_reference_tree][version] = "1.10"

; Themes to upgrade the admin backend.

projects[adminimal_theme][subdir] = "contrib"
projects[adminimal_theme][version] = "1.22"
projects[adminimal_theme][type] = "theme"

; Libraries

libraries[select2][type] = "libraries"
libraries[select2][download][type] = "file"
libraries[select2][download][url] = "https://github.com/ivaynberg/select2/archive/3.5.2.zip"

libraries[plupload][download][type]= "get"
libraries[plupload][download][url] = "https://github.com/moxiecode/plupload/archive/v1.5.8.zip"
libraries[plupload][directory_name] = "plupload"
libraries[plupload][destination] = "libraries"
