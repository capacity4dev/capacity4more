core = 7.x
api = 2

projects[drupal][version] = "7.63"

; Patch to make it possible to run tests on modules located in a custom profile.
; See https://drupal.org/node/911354#comment-7341092.
projects[drupal][patch][] = "https://drupal.org/files/911354-drupal-profile-85.patch"
projects[drupal][patch][] = "https://www.drupal.org/files/issues/book_unpublished_patch_760102-10.patch"
projects[drupal][patch][] = "https://www.drupal.org/files/issues/cannot_create_references_tofrom_string_offsets_nor_overloaded_objects-2313517-32.patch"
projects[drupal][patch][] = "../patches/machine-name-validate-custom-message.patch"
projects[drupal][patch][] = "../patches/drupal-filter-save-html.patch"

projects[drupal][patch][] = "https://www.drupal.org/files/issues/drupal-drupal_tempnam-985384-11.patch"

; Place "addTag('node_access')"" first in the menu access checkes.
projects[drupal][patch][] = "../patches/menu_access_check_node_access_first.patch"

; Support for the "reset to alphabetical" in taxonomy listings.
projects[drupal][patch][] = "https://www.drupal.org/files/order-weighted-terms-941266-35-D7.patch"

; Allows multiple error messages per form element.
projects[drupal][patch][] = "https://www.drupal.org/files/issues/form.inc-549020-7.x.patch"
