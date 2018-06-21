core = 7.x
api = 2

; Themes based on bootstrap

libraries[font_awesome][type] = "libraries"
libraries[font_awesome][download][type] = "file"
libraries[font_awesome][download][url] = "https://github.com/FortAwesome/Font-Awesome/archive/v4.7.0.tar.gz"
libraries[font_awesome][patch][] = "../patches/github-dependency-vulnerability-fontawesome.patch"

projects[bootstrap][subdir] = "contrib"
projects[bootstrap][version] = "3.10"
projects[bootstrap][type] = "theme"
