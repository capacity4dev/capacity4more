core = 7.x
api = 2

projects[drupal][version] = "7.53"

; Patch to make it possible to run tests on modules located in a custom profile.
; See https://drupal.org/node/911354#comment-7341092.
projects[drupal][patch][] = "https://drupal.org/files/911354-drupal-profile-85.patch"
projects[drupal][patch][] = "https://www.drupal.org/files/issues/book_unpublished_patch_760102-10.patch"

; Committed in Drupal 7.50
;projects[drupal][patch][] = "https://www.drupal.org/files/issues/1116326-overlay-method-get-forms-56-D7.patch"

projects[drupal][patch][] = "https://www.drupal.org/files/issues/drupal-drupal_tempnam-985384-11.patch"

; Committed in Drupal 7.50
;projects[drupal][patch][] = "https://www.drupal.org/files/issues/imagerotate-2215369-83.patch"

; Patch which changes the output of Drupal's .htaccess files.
; This patch will make the .htaccess files match DIGIT's requirements (Apache 2.4.x).
projects[drupal][patch][] = "https://www.drupal.org/files/issues/drupal7-htaccess_protections-1599774-73.patch"

; Will prevent forms from being cached, needed for the registration form with ajax handlers.
projects[drupal][patch][] = "https://www.drupal.org/files/issues/drupal-no_cache_form-2819375-42.patch"

; Place "addTag('node_access')"" first in the menu access checkes.
projects[drupal][patch][] = "../patches/menu_access_check_node_access_first.patch"

; Support for the "reset to alphabetical" in taxonomy listings.
projects[drupal][patch][] = "https://www.drupal.org/files/order-weighted-terms-941266-35-D7.patch"
