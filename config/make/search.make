core = 7.x
api = 2

; Search.

projects[facetapi][subdir] = "contrib"
projects[facetapi][version] = "1.5"

projects[facetapi_bonus][subdir] = "contrib"
projects[facetapi_bonus][version] = "1.1"

projects[search_api][subdir] = "contrib"
projects[search_api][version] = "1.17"

projects[search_api_attachments][subdir] = "contrib"
projects[search_api_attachments][version] = "1.8"

projects[search_api_autocomplete][subdir] = "contrib"
projects[search_api_autocomplete][version] = "1.4"

projects[search_api_solr][subdir] = "contrib"
projects[search_api_solr][version] = "1.10"

projects[search_api_sorts][subdir] = "contrib"
projects[search_api_sorts][version] = "1.x-dev"

projects[search_api_spellcheck][subdir] = "contrib"
projects[search_api_spellcheck][version] = "1.0"
projects[search_api_spellcheck][patch][] = "https://www.drupal.org/files/issues/search_api_spellcheck-adjust_regexp-2304271-3_0.patch"
