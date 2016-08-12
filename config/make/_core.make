core = 7.x
api = 2

projects[drupal][version] = "7.50"

; Patch to make it possible to run tests on modules located in a custom profile.
; See https://drupal.org/node/911354#comment-7341092.
projects[drupal][patch][] = "https://drupal.org/files/911354-drupal-profile-85.patch"
projects[drupal][patch][] = "https://www.drupal.org/files/issues/book_unpublished_patch_760102-10.patch"
projects[drupal][patch][] = "https://www.drupal.org/files/issues/drupal-drupal_tempnam-985384-11.patch"
