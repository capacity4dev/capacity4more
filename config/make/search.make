core = 7.x
api = 2

; Search.

projects[facetapi][subdir] = "contrib"
projects[facetapi][version] = "1.5"

projects[facetapi_bonus][subdir] = "contrib"
projects[facetapi_bonus][version] = "1.2"

projects[search_api][subdir] = "contrib"
projects[search_api][version] = "1.20"
projects[search_api][patch][] = "https://www.drupal.org/files/issues/search-api-indexed-node-author-2769877-2.patch"
projects[search_api][patch][] = "https://www.drupal.org/files/issues/1123454-89--vbo_support.patch"

projects[search_api_attachments][subdir] = "contrib"
projects[search_api_attachments][version] = "1.10"

projects[search_api_solr][subdir] = "contrib"
projects[search_api_solr][version] = "1.11"

projects[search_api_sorts][subdir] = "contrib"
projects[search_api_sorts][version] = "1.x-dev"

projects[search_api_spellcheck][subdir] = "contrib"
projects[search_api_spellcheck][version] = "1.0"
projects[search_api_spellcheck][patch][] = "https://www.drupal.org/files/issues/search_api_spellcheck-adjust_regexp-2304271-3_0.patch"
