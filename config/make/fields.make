core = 7.x
api = 2

; Contrib field definitions

projects[addressfield][subdir] = "contrib"
projects[addressfield][version] = "1.2"

projects[currency][subdir] = "contrib"
projects[currency][version] = "2.6"

projects[date][subdir] = "contrib"
projects[date][version] = "2.9"

projects[dragndrop_upload][subdir] = "contrib"
projects[dragndrop_upload][version] = "1.x-dev"

projects[field_group][subdir] = "contrib"
projects[field_group][version] = "1.5"

projects[geocoder][subdir] = "contrib"
projects[geocoder][version] = "1.3"
projects[geocoder][patch][] = "https://www.drupal.org/files/issues/geocoder-osm-nominatim-address-2682507-2.patch"

projects[geophp][subdir] = "contrib"
projects[geophp][version] = "1.7"

projects[geofield][subdir] = "contrib"
projects[geofield][version] = "2.3"

projects[leaflet][subdir] = "contrib"
projects[leaflet][version] = "1.3"

projects[link][subdir] = "contrib"
projects[link][version] = "1.4"

projects[money][subdir] = "contrib"
projects[money][version] = "1.x-dev"

projects[getlocations][subdir] = "contrib"
projects[getlocations][version] = "1.17"

projects[location][subdir] = "contrib"
projects[location][version] = "3.7"

projects[reldate][subdir] = "contrib"
projects[reldate][version] = "1.x-dev"

projects[weight][subdir] = "contrib"
projects[weight][version] = "3.1"

libraries[leaflet][download][type]= "get"
libraries[leaflet][download][url] = "https://leafletjs-cdn.s3.amazonaws.com/content/leaflet/master/leaflet.zip"
libraries[leaflet][directory_name] = "leaflet"
libraries[leaflet][destination] = "libraries"

libraries[getlocations_markers][download][type]= "get"
libraries[getlocations_markers][download][url] = "https://dl.dropboxusercontent.com/u/41489105/Drupal/getlocations/getlocations-markers.zip"
libraries[getlocations_markers][directory_name] = "getlocations"
libraries[getlocations_markers][destination] = "libraries"
