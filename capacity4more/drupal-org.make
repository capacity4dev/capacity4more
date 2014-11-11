core = 7.x
api = 2

; Modules
projects[admin_views][subdir] = "contrib"
projects[admin_views][version] = "1.3"

projects[ckeditor][subdir] = "contrib"
projects[ckeditor][version] = "1.x-dev"

projects[context][subdir] = "contrib"
projects[context][version] = "3.2"

projects[context_block_disable][subdir] = "contrib"
projects[context_block_disable][version] = "1.x-dev"

projects[context_local_tasks][subdir] = "contrib"
projects[context_local_tasks][version] = "1.x-dev"

projects[context_no_title][subdir] = "contrib"
projects[context_no_title][version] = "1.x-dev"

projects[context_og][subdir] = "contrib"
projects[context_og][version] = "2.1"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.4"

projects[currency][subdir] = "contrib"
projects[currency][version] = "2.4"

projects[date][subdir] = "contrib"
projects[date][version] = "2.8"

projects[diff][subdir] = "contrib"
projects[diff][version] = "3.2"

projects[dragndrop_upload][subdir] = "contrib"
projects[dragndrop_upload][version] = "1.x-dev"

projects[entity][subdir] = "contrib"
projects[entity][version] = "1.5"
; Patches for RESTful
projects[entity][patch][] = "https://www.drupal.org/files/issues/2264079-entity-wrapper-access-single-entity-reference-2.patch"
projects[entity][patch][] = "https://www.drupal.org/files/issues/2086225-entity-access-check-node-create-3.patch"

projects[entityreference][subdir] = "contrib"
projects[entityreference][version] = "1.1"

projects[entityreference_prepopulate][subdir] = "contrib"
projects[entityreference_prepopulate][version] = "1.5"

projects[features][subdir] = "contrib"
projects[features][version] = "2.2"

projects[field_group][subdir] = "contrib"
projects[field_group][version] = "1.4"

projects[file_entity][subdir] = "contrib"
projects[file_entity][version] = "2.x-dev"

projects[flag][subdir] = "contrib"
projects[flag][version] = "3.5"

projects[getlocations][subdir] = "contrib"
projects[getlocations][version] = "1.13"

projects[inline_entity_form][subdir] = "contrib"
projects[inline_entity_form][version] = "1.5"

projects[jquery_update][subdir] = "contrib"
projects[jquery_update][version] = "2.4"

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "2.2"

projects[link][subdir] = "contrib"
projects[link][version] = "1.3"

projects[location][subdir] = "contrib"
projects[location][version] = "3.3"

projects[mailsystem][version] = "2.34"
projects[mailsystem][subdir] = "contrib"

projects[media][subdir] = "contrib"
projects[media][version] = "2.x-dev"

projects[media_flickr][subdir] = "contrib"
projects[media_flickr][version] = "2.x-dev"

projects[media_vimeo][subdir] = "contrib"
projects[media_vimeo][version] = "2.0"

projects[media_youtube][subdir] = "contrib"
projects[media_youtube][version] = "2.x-dev"

projects[message][subdir] = "contrib"
projects[message][version] = "1.9"

projects[message_notify][subdir] = "contrib"
projects[message_notify][version] = "2.5"

projects[mimemail][version] = "1.0-beta3"
projects[mimemail][subdir] = "contrib"
; ? projects[mimemail][patch][] = "http://drupal.org/files/rules-1585546-1-moving_rules_actions.patch"
; ? projects[mimemail][patch][] = "http://drupal.org/files/compress_install_missing_value.patch"

projects[money][subdir] = "contrib"
projects[money][version] = "1.x-dev"

projects[module_filter][subdir] = "contrib"
projects[module_filter][version] = "2.0-alpha2"

projects[node_gallery][subdir] = "contrib"
projects[node_gallery][version] = "1.0"

projects[og][subdir] = "contrib"
projects[og][version] = "2.7"

projects[og_purl][subdir] = "contrib"
projects[og_purl][version] = "1.2"

projects[og_vocab][subdir] = "contrib"
projects[og_vocab][version] = "1.2"

projects[panels][subdir] = "contrib"
projects[panels][version] = "3.4"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.2"

projects[pluggable_node_access][subdir] = "contrib"
projects[pluggable_node_access][version] = "1.x-dev"
projects[pluggable_node_access][patch][] = https://github.com/Gizra/pluggable_node_access/pull/10.patch

projects[plupload][subdir] = "contrib"
projects[plupload][version] = "1.6"

projects[purl][subdir] = "contrib"
projects[purl][version] = "1.x-dev"
projects[purl][patch][] = https://drupal.org/files/purl-1693984-10.patch

projects[reldate][subdir] = "contrib"
projects[reldate][version] = "1.x-dev"

projects[restful][download][type] = "git"
projects[restful][download][url] = "https://github.com/Gizra/restful.git"
projects[restful][download][branch] = 7.x-1.x
projects[restful][subdir] = "contrib"
projects[restful][type] = "module"

projects[rules][subdir] = "contrib"
projects[rules][version] = "2.6"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"

projects[token][subdir] = "contrib"
projects[token][version] = "1.5"

projects[summary_settings][subdir] = "contrib"
projects[summary_settings][version] = "1.x-dev"

projects[transliteration][subdir] = contrib
projects[transliteration][version] = "3.2"

projects[views][subdir] = "contrib"
projects[views][version] = "3.8"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "3.2"

projects[weight][subdir] = "contrib"
projects[weight][version] = "2.3"



; Development modules
; Modules
projects[devel][subdir] = "development"
projects[coder][subdir] = "development"

projects[migrate][version] = "2.5"
projects[migrate][subdir] = "development"

projects[migrate_extras][version] = "2.5"
projects[migrate_extras][subdir] = "development"



; Libraries
libraries[ckeditor][download][type]= "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.3.4/ckeditor_4.3.4_full.zip"
libraries[ckeditor][directory_name] = "ckeditor"
libraries[ckeditor][destination] = "libraries"

libraries[plupload][download][type]= "get"
libraries[plupload][download][url] = "https://github.com/moxiecode/plupload/archive/v1.5.8.zip"
libraries[plupload][directory_name] = "plupload"
libraries[plupload][destination] = "libraries"

libraries[getlocations_markers][download][type]= "get"
libraries[getlocations_markers][download][url] = "http://dl.dropbox.com/u/41489105/Drupal/getlocations/getlocations-markers.zip"
libraries[getlocations_markers][directory_name] = "getlocations"
libraries[getlocations_markers][destination] = "libraries"

; Themes
projects[bootstrap][subdir] = "contrib"
projects[bootstrap][version] = "3.0"
projects[bootstrap][type] = "theme"
