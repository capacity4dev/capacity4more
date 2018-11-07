core = 7.x
api = 2

; Search.

projects[current_search_links][subdir] = "contrib"
projects[current_search_links][version] = "1.x-dev"
projects[current_search_links][download][type] = "git"
projects[current_search_links][download][url] = "https://git.drupal.org/project/current_search_links.git"
projects[current_search_links][download][revision] = "55c035d131f99a131f49de2decd3cc08640f33b0"
projects[current_search_links][patch][] = "https://www.drupal.org/files/issues/current_search_links-theming-hooks-2929123-2.patch"

projects[facetapi][subdir] = "contrib"
projects[facetapi][version] = "1.5"
projects[facetapi][patch][] = "https://www.drupal.org/files/issues/facetapi-exportable-current-search-searcher-1469002-0.patch"

projects[facetapi_bonus][subdir] = "contrib"
projects[facetapi_bonus][version] = "1.2"

projects[search_api][subdir] = "contrib"
projects[search_api][version] = "1.20"
projects[search_api][patch][] = "https://www.drupal.org/files/issues/search-api-indexed-node-author-2769877-2.patch"
projects[search_api][patch][] = "https://www.drupal.org/files/issues/1123454-89--vbo_support.patch"

projects[search_api_attachments][subdir] = "contrib"
projects[search_api_attachments][version] = "1.10"

projects[search_api_solr][subdir] = "contrib"
projects[search_api_solr][version] = "1.14"

projects[search_api_sorts][subdir] = "contrib"
projects[search_api_sorts][version] = "1.7"

projects[search_api_spellcheck][subdir] = "contrib"
projects[search_api_spellcheck][version] = "1.0"
projects[search_api_spellcheck][patch][] = "https://www.drupal.org/files/issues/search_api_spellcheck-adjust_regexp-2304271-3_0.patch"
