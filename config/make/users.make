core = 7.x
api = 2

; Modules related to users.

projects[auto_username][subdir] = "contrib"
projects[auto_username][version] = "1.0-alpha2"
projects[auto_username][patch][] = https://www.drupal.org/files/issues/username_set_to_random_string-2658254-4.patch

projects[campaignmonitor][subdir] = "contrib"
projects[campaignmonitor][version] = "1.1"

projects[email_confirm][subdir] = "contrib"
projects[email_confirm][version] = "1.3"

projects[legal][subdir] = "contrib"
projects[legal][version] = "1.6"

projects[nocurrent_pass][subdir] = "contrib"
projects[nocurrent_pass][version] = "1.1"

projects[user_registrationpassword][subdir] = "contrib"
projects[user_registrationpassword][version] = "1.4"

libraries[campaignmonitor][download][type]= "get"
libraries[campaignmonitor][download][url] = "https://github.com/campaignmonitor/createsend-php/zipball/master"
libraries[campaignmonitor][directory_name] = "campaignmonitor"
libraries[campaignmonitor][destination] = "libraries"
