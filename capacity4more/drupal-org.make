core = 7.x
api = 2

; Modules
projects[admin_menu][subdir] = "contrib"
projects[admin_menu][version] = "3.0-rc4"

projects[admin_views][subdir] = "contrib"
projects[admin_views][version] = "1.2"

projects[ckeditor][subdir] = "contrib"
projects[ckeditor][version] = "1.x-dev"

projects[currency][subdir] = "contrib"
projects[currency][version] = "2.3"

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

projects[date][subdir] = "contrib"
projects[date][version] = "2.7"

projects[diff][subdir] = "contrib"
projects[diff][version] = "3.2"

projects[entity][subdir] = "contrib"
projects[entity][version] = "1.4"

projects[entityreference][subdir] = "contrib"
projects[entityreference][version] = "1.1"

projects[entityreference_prepopulate][subdir] = "contrib"
projects[entityreference_prepopulate][version] = "1.5"

projects[features][subdir] = "contrib"
projects[features][version] = "2.0"

projects[file_entity][subdir] = "contrib"
projects[file_entity][version] = "2.x-dev"

projects[flag][subdir] = "contrib"
projects[flag][version] = "3.4"

projects[getlocations][subdir] = "contrib"
projects[getlocations][version] = "1.12"

projects[inline_entity_form][subdir] = "contrib"
projects[inline_entity_form][version] = "1.5"

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "2.2"

projects[mailsystem][version] = 2.34
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

projects[mimemail][version] = 1.0-beta3
projects[mimemail][subdir] = "contrib"
; ? projects[mimemail][patch][] = "http://drupal.org/files/rules-1585546-1-moving_rules_actions.patch"
; ? projects[mimemail][patch][] = "http://drupal.org/files/compress_install_missing_value.patch"

projects[money][subdir] = "contrib"
projects[money][version] = 1.x-dev

projects[module_filter][subdir] = "contrib"
projects[module_filter][version] = 2.0-alpha2

projects[og][subdir] = "contrib"
projects[og][version] = 2.6

projects[og_purl][subdir] = "contrib"
projects[og_purl][version] = 1.2

projects[og_vocab][subdir] = "contrib"
projects[og_vocab][version] = "1.2"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.2"

projects[plupload][subdir] = "contrib"
projects[plupload][version] = "1.6"

projects[purl][subdir] = "contrib"
projects[purl][version] = "1.x-dev"

projects[reldate][subdir] = "contrib"
projects[reldate][version] = "1.x-dev"

projects[rules][subdir] = "contrib"
projects[rules][version] = 2.6

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"

projects[token][subdir] = "contrib"
projects[token][version] = "1.5"

projects[transliteration][subdir] = contrib
projects[transliteration][version] = "3.2"

projects[views][subdir] = "contrib"
projects[views][version] = "3.7"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "3.2"



; Development modules
; Modules
projects[devel][subdir] = "development"
projects[coder][subdir] = "development"

projects[migrate][version] = 2.5
projects[migrate][subdir] = "development"

projects[migrate_extras][version] = 2.5
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