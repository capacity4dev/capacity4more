core = 7.x
api = 2

; Themes based on bootstrap

libraries[font_awesome][type] = "libraries"
libraries[font_awesome][download][type] = "file"
libraries[font_awesome][download][url] = "https://github.com/FortAwesome/Font-Awesome/archive/v4.5.0.tar.gz"

projects[bootstrap][subdir] = "contrib"
projects[bootstrap][version] = "3.5"
projects[bootstrap][type] = "theme"
projects[bootstrap][patch][] = https://www.drupal.org/files/issues/bootstrap-autosubmit-fix-2695405-2.patch
