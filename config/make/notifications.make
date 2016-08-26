core = 7.x
api = 2

; Notifications stack.

projects[mailsystem][version] = "2.x-dev"
projects[mailsystem][subdir] = "contrib"

projects[message][subdir] = "contrib"
projects[message][version] = "1.11"
projects[message][patch][] = "https://www.drupal.org/files/message-primary_nullable-2051751-7.patch"

projects[message_subscribe][subdir] = "contrib"
projects[message_subscribe][version] = "1.0-rc2"

projects[message_notify][subdir] = "contrib"
projects[message_notify][version] = "2.5"

projects[mimemail][version] = "1.0-beta4"
projects[mimemail][subdir] = "contrib"
