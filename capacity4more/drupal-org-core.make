core = 7.x
api = 2

projects[drupal][version] = "7.31"


; Patch to make it possible to run tests on modules located in a custom profile.
; See https://drupal.org/node/911354#comment-7341092.
projects[drupal][patch][] = "https://drupal.org/files/911354-drupal-profile-85.patch"
