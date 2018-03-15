core = 7.x
api = 2

; Organic Groups and friends.

projects[og][version] = "2.9"
projects[og][subdir] = "contrib"
projects[og][patch][] = "https://www.drupal.org/files/issues/access_check_when_getting_groups.patch"
projects[og][patch][] = "https://www.drupal.org/files/issues/og-fix_return_value_of_og_get_groups_by_user-2569471-3.patch"
projects[og][patch][] = "https://www.drupal.org/files/issues/og_context_is_not_part_of_menu_access_callbacks-2804591-3.patch"
projects[og][patch][] = "https://patch-diff.githubusercontent.com/raw/Gizra/og/pull/213.patch"
projects[og][patch][] = "../patches/og_ui-invited_members_count_overview.patch"

projects[og_purl][subdir] = "contrib"
projects[og_purl][version] = "1.x-dev"
projects[og_purl][patch][] = "https://www.drupal.org/files/issues/og_purl_node_delete-2419277-1.patch"

projects[og_variables][subdir] = "contrib"
projects[og_variables][version] = "1.0"

projects[og_vocab][subdir] = "contrib"
projects[og_vocab][version] = "1.2"
projects[og_vocab][patch][] = https://www.drupal.org/files/issues/og_vocab-fix_strict_warning.patch
projects[og_vocab][patch][] = https://www.drupal.org/files/issues/2399883-og_vocab-menuitem-7.patch
projects[og_vocab][patch][] = https://www.drupal.org/files/issues/og_vocab-unset-theme-2379169-1.patch

projects[pluggable_node_access][subdir] = "contrib"
projects[pluggable_node_access][version] = "1.x-dev"

projects[purl][subdir] = "contrib"
projects[purl][version] = "1.x-dev"
projects[purl][patch][] = https://www.drupal.org/files/purl-1693984-10.patch
projects[purl][patch][] = https://www.drupal.org/files/issues/purl_modifiers_xx_cache-2419261-1.patch
projects[purl][patch][] = https://www.drupal.org/files/808956-14-purl-menu-behavior.patch

projects[session_api][subdir] = "contrib"
projects[session_api][version] = "1.0-rc1"

projects[og_invite][subdir] = "contrib"
projects[og_invite][version] = "1.0-beta5"
projects[og_invite][patch][] = "../patches/og_invite-decline_message.patch"

projects[og_context_access_callback][subdir] = "contrib"
projects[og_context_access_callback][version] = "1.x-dev"

projects[og_menu][subdir] = "contrib"
projects[og_menu][version] = "3.1"
