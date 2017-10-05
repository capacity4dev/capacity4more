core = 7.x
api = 2

; Modules related to exporting/importing configuration.

projects[diff][subdir] = "contrib"
projects[diff][version] = "3.2"

projects[features][subdir] = "contrib"
projects[features][version] = "2.10"
projects[features][patch][] = "https://www.drupal.org/files/issues/undefined-property-status-2324973-19.patch"
projects[features][patch][] = "https://www.drupal.org/files/issues/features-blank-line-after-php-tag-2765721-0.patch"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"
