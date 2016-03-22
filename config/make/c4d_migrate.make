core = 7.x
api = 2

; Modules only to install for ci environments.

projects[c4d_import][download][type] = "git"
projects[c4d_import][download][url] = "git@github.com:capacity4dev/c4d_import.git"
projects[c4d_import][download][branch] = master
projects[c4d_import][type] = "module"
projects[c4d_import][subdir] = "migration"
