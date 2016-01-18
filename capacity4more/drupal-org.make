core = 7.x
api = 2

; Modules
projects[admin_views][subdir] = "contrib"
projects[admin_views][version] = "1.5"

projects[admin_menu][subdir] = "contrib"
projects[admin_menu][version] = "3.0-rc5"

projects[better_formats][subdir] = "contrib"
projects[better_formats][version] = "1.x-dev"

projects[captcha][subdir] = "contrib"
projects[captcha][version] = "1.3"

projects[recaptcha][subdir] = "contrib"
projects[recaptcha][version] = "2.0"

projects[ckeditor][subdir] = "contrib"
projects[ckeditor][version] = "1.x-dev"

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

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.9"

projects[currency][subdir] = "contrib"
projects[currency][version] = "2.5"

projects[date][subdir] = "contrib"
projects[date][version] = "2.8"

projects[diff][subdir] = "contrib"
projects[diff][version] = "3.2"

projects[ds][subdir] = "contrib"
projects[ds][version] = "2.11"

projects[draggableviews][subdir] = "contrib"
projects[draggableviews][version] = "2.1"
projects[draggableviews][patch][] = "https://www.drupal.org/files/issues/draggableviews-2343793-16.patch"

projects[dragndrop_upload][subdir] = "contrib"
projects[dragndrop_upload][version] = "1.x-dev"

projects[entity][subdir] = "contrib"
projects[entity][version] = "1.6"
; Patches for RESTful
projects[entity][patch][] = "https://www.drupal.org/files/issues/2086225-entity-access-check-18.patch"

projects[entityreference][subdir] = "contrib"
projects[entityreference][version] = "1.1"
projects[entityreference][patch][] = "https://www.drupal.org/files/entityreference-decode_option_labels-1665818-32_0.patch"

projects[entityreference_prepopulate][subdir] = "contrib"
projects[entityreference_prepopulate][version] = "1.5"

projects[eu_cookie_compliance][subdir] = "contrib"
projects[eu_cookie_compliance][version] = "1.14"

projects[facetapi][subdir] = "contrib"
projects[facetapi][version] = "1.5"

projects[facetapi_bonus][subdir] = "contrib"
projects[facetapi_bonus][version] = "1.1"

projects[features][subdir] = "contrib"
projects[features][version] = "2.6"

projects[field_group][subdir] = "contrib"
projects[field_group][version] = "1.4"

projects[file_entity][subdir] = "contrib"
projects[file_entity][version] = "2.x-dev"

projects[file_download_count][subdir] = "contrib"
projects[file_download_count][version] = "1.0-rc1"

projects[flag][subdir] = "contrib"
projects[flag][version] = "3.6"

projects[getlocations][subdir] = "contrib"
projects[getlocations][version] = "1.16"

projects[inline_entity_form][subdir] = "contrib"
projects[inline_entity_form][version] = "1.6"

projects[jquery_update][subdir] = "contrib"
projects[jquery_update][version] = "3.0-alpha2"

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "2.2"

projects[link][subdir] = "contrib"
projects[link][version] = "1.3"

projects[location][subdir] = "contrib"
projects[location][version] = "3.7"

projects[mailsystem][version] = "2.34"
projects[mailsystem][subdir] = "contrib"

projects[media][subdir] = "contrib"
projects[media][version] = "2.x-dev"

projects[media_flickr][subdir] = "contrib"
projects[media_flickr][version] = "2.x-dev"

projects[mefibs][subdir] = "contrib"
projects[mefibs][version] = "1.x-dev"

projects[media_vimeo][subdir] = "contrib"
projects[media_vimeo][version] = "2.0"

projects[media_youtube][subdir] = "contrib"
projects[media_youtube][version] = "2.x-dev"

projects[memcache][subdir] = "contrib"
projects[memcache][version] = "1.5"

projects[message][subdir] = "contrib"
projects[message][version] = "1.11"
projects[message][patch][] = "https://www.drupal.org/files/issues/message-mysql57_compatibility-2629474-4.patch"

projects[message_notify][subdir] = "contrib"
projects[message_notify][version] = "2.5"

projects[mimemail][version] = "1.0-beta4"
projects[mimemail][subdir] = "contrib"

projects[money][subdir] = "contrib"
projects[money][version] = "1.x-dev"

projects[module_filter][subdir] = "contrib"
projects[module_filter][version] = "2.0"

projects[node_gallery][subdir] = "contrib"
projects[node_gallery][version] = "1.1"

projects[og][download][type] = "git"
projects[og][download][url] = "https://github.com/HelenaEksler/og.git"
projects[og][download][branch] = og_context_check_access
projects[og][type] = "module"
projects[og][subdir] = "contrib"
projects[og][patch][] = "https://www.drupal.org/files/issues/access_check_when_getting_groups.patch"

projects[og_purl][subdir] = "contrib"
projects[og_purl][version] = "1.x-dev"
projects[og_purl][patch][] = "https://www.drupal.org/files/issues/og_purl_node_delete-2419277-1.patch"

projects[og_variables][subdir] = "contrib"
projects[og_variables][version] = "1.0"

projects[og_vocab][subdir] = "contrib"
projects[og_vocab][version] = "1.2"
projects[og_vocab][patch][] = https://www.drupal.org/files/issues/og_vocab-fix_strict_warning.patch

projects[panels][subdir] = "contrib"
projects[panels][version] = "3.5"

projects[panels_bootstrap_layouts][subdir] = "contrib"
projects[panels_bootstrap_layouts][version] = "3.0"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.2"

projects[pluggable_node_access][download][type] = "git"
projects[pluggable_node_access][download][url] = "https://github.com/Gizra/pluggable_node_access.git"
projects[pluggable_node_access][download][branch] = 7.x-1.x
projects[pluggable_node_access][subdir] = "contrib"
projects[pluggable_node_access][type] = "module"

projects[plupload][subdir] = "contrib"
projects[plupload][version] = "1.7"

projects[purl][subdir] = "contrib"
projects[purl][version] = "1.x-dev"
projects[purl][patch][] = https://www.drupal.org/files/purl-1693984-10.patch
projects[purl][patch][] = https://www.drupal.org/files/issues/purl_modifiers_xx_cache-2419261-1.patch
projects[purl][patch][] = https://www.drupal.org/files/808956-14-purl-menu-behavior.patch

projects[redirect][subdir] = "contrib"
projects[redirect][version] = "1.0-rc3"

projects[reldate][subdir] = "contrib"
projects[reldate][version] = "1.x-dev"

projects[restful][download][type] = "git"
projects[restful][download][url] = "https://github.com/Gizra/restful.git"
projects[restful][download][branch] = 7.x-1.x
projects[restful][subdir] = "contrib"
projects[restful][type] = "module"


projects[rules][subdir] = "contrib"
projects[rules][version] = "2.6"

projects[search_api][subdir] = "contrib"
projects[search_api][version] = "1.15"
projects[search_api_attachments][subdir] = "contrib"
projects[search_api_attachments][version] = "1.6"
projects[search_api_autocomplete][subdir] = "contrib"
projects[search_api_autocomplete][version] = "1.3"
projects[search_api_autocomplete][patch][] = "https://www.drupal.org/files/issues/search_api_autocomplete-JS-error-on-click-or-key-pressed-2473737-5.patch"
projects[search_api_solr][subdir] = "contrib"
projects[search_api_solr][version] = "1.8"
projects[search_api_sorts][subdir] = "contrib"
projects[search_api_sorts][version] = "1.x-dev"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"

projects[term_reference_tree][subdir] = "contrib"
projects[term_reference_tree][version] = "1.10"

projects[token][subdir] = "contrib"
projects[token][version] = "1.6"

projects[save_draft][subdir] = "contrib"
projects[save_draft][version] = "1.4"

projects[smart_trim][subdir] = "contrib"
projects[smart_trim][version] = "1.5"

projects[summary_settings][subdir] = "contrib"
projects[summary_settings][version] = "1.x-dev"

projects[transliteration][subdir] = contrib
projects[transliteration][version] = "3.2"

projects[variable][subdir] = "contrib"
projects[variable][version] = "2.5"

projects[views][subdir] = "contrib"
projects[views][version] = "3.11"
projects[views][patch][] = "https://www.drupal.org/files/issues/views-more-links-with-query-params-2210663-1.patch"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "3.3"
projects[views_bulk_operations][patch][] = "https://www.drupal.org/files/issues/1334374-25-generic_entity_tables_revisions.patch"

projects[views_load_more][subdir] = "contrib"
projects[views_load_more][version] = "1.5"

projects[weight][subdir] = "contrib"
projects[weight][version] = "2.4"

projects[wysiwyg_filter][subdir] = "contrib"
projects[wysiwyg_filter][version] = "1.x-dev"


; Development modules
; Modules
projects[devel][subdir] = "development"

projects[coder][subdir] = "development"
projects[coder][version] = "2.x-dev"

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

libraries[select2][type] = "libraries"
libraries[select2][download][type] = "file"
libraries[select2][download][url] = "https://github.com/ivaynberg/select2/archive/3.5.2.zip"

libraries[font_awesome][type] = "libraries"
libraries[font_awesome][download][type] = "file"
libraries[font_awesome][download][url] = "https://github.com/FortAwesome/Font-Awesome/archive/v4.3.0.tar.gz"

; Themes
projects[bootstrap][subdir] = "contrib"
projects[bootstrap][version] = "3.x-dev"
projects[bootstrap][type] = "theme"
