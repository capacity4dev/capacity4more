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

projects[maxlength][subdir] = "contrib"
projects[maxlength][version] = "3.2"

projects[money][subdir] = "contrib"
projects[money][version] = "1.x-dev"

projects[reldate][subdir] = "contrib"
projects[reldate][version] = "1.x-dev"

projects[weight][subdir] = "contrib"
projects[weight][version] = "3.1"

libraries[leaflet][download][type]= "get"
libraries[leaflet][download][url] = "http://cdn.leafletjs.com/leaflet/v0.7.7/leaflet.zip"
libraries[leaflet][directory_name] = "leaflet"
libraries[leaflet][destination] = "libraries"
