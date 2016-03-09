Getlocations Search provides a search facility that will show nearby
locations from Getlocation Fields enabled nodes, users, terms or comments.

It also has support for Geofield and Geolocation

It can however be used without any of the above modules enabled, in which case
it will just do searches and show a map of the area found.

Enable Getlocations Search under Modules, then go to
Configuration > Web Services > Getlocations Search and set it up to suit your needs,
then go to Structure > Menus > Navigation where you can enable the link.

Theming.
Getlocations Search pages can be themed by copying the relevant function to your theme's template.php,
renaming it in the usual manner.
eg
theme_getlocations_search_form() becomes MYTHEME_getlocations_search_form() where MYTHEME is the name of your theme.
You can edit it there to suit your needs.

These functions can be found in the file getlocations_search.module

Theming the Getlocations Search form.
This is done with function theme_getlocations_search_form()

Theming the Getlocations Search settings form.
This is done with function theme_getlocations_search_settings_form()

Getlocations Search can be viewed in a Colorbox. The colorbox module must be installed and "colorbox load" enabled.
To make it work add a url in the following form:
<a class="colorbox-load" href="/getlocations_search_box?width=550&height=600&iframe=true">Getlocations search in a colorbox</a>
