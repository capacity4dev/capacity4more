Views for Getlocations Fields

Name: Getlocations
Description: Provides a block with a link to a map.
This view should work out of the box.


Name: Getlocations map
Description: Provides a map of a locations_fields enabled node.

Configure contextual filter: Content: Nid
Specify validation criteria
Choose the content type


Name: Getlocations map allnodes
Description: Provides a map of all locations_fields enabled nodes.


Name: Getlocations map nearby
Description: Provides a map of all nearby locations_fields enabled nodes.

To get this to work you will need to do some configuring:
Configure contextual filter: Content: Nid
Specify validation criteria
Choose the content type

Configure filter criterion: Getlocations Fields: Distance
Make sure it is pointing to the right Location to use. You can also set the default Operator, Units and Distance.

Configure extra settings for sort criterion Getlocations Fields: Distance
Make sure it is pointing to the right Location to use.

In Block 5 you will want to do the Format > Getlocations > Settings

In Block 6 there is no further configuration required.
You might want to try exposing the Pager, Distance or Order. Remember to set ajax to Yes


Name: Getlocations show all
Description: Provides a map of all locations_fields enabled content types.
You will probably need to flush the cache to get the path 'getlocations_showall' accepted.


Name: Getlocations map allusers
Description: Provides a map of all locations_fields enabled users.


Name: Getlocations User
Description: Provides a link to a map of a locations_fields enabled user.
This view should work out of the box.


Name: Getlocations map nearby users
Description: Provides a map of all nearby locations_fields enabled users.

To get this to work you will need to do some configuring:

Configure contextual filter: User: Uid
Specify validation criteria

Configure filter criterion: Getlocations Fields: Distance
Make sure it is pointing to the right Location to use. You can also set the default Operator, Units and Distance.

Configure extra settings for sort criterion Getlocations Fields: Distance
Make sure it is pointing to the right Location to use.

Name: Getlocations terms
Description: Provides views for getlocations_fields enabled terms


Name: Getlocations by city
Description: Find locations by city in argument
Path: /getlocations_by_city/nnn
where nnn is the name or part of a city


Name: Getlocations by postcode
Description: Find locations by postcode in argument
Path: /getlocations_by_postcode/nnn
where nnn is the name or part of a postcode


Name: Getlocations by province
Description: Find locations by province in argument
Path: /getlocations_by_province/nnn
where nnn is the name or part of a province


Name: Getlocations by country
Description: Find locations by country in argument
Path: /getlocations_by_country/nn
where nn is the country code

Name: Getlocations search nearby
Description: Provides a map and form using Google Autocomplete search
Path: /getlocations_search_nearby
The exposed form contains a Google Autocomplete textbox, Unit selector and Distance textbox.
This form can be configured to appear with the page or in a block.

In the View, under "Advanced", if "Exposed form in block" is "yes"
make sure the block "Exposed form: getlocations_search_nearby-page_1" is enabled in the sidebar.
Make sure it is configured with "Only the listed pages" set to "getlocations_search_nearby"
If you set "Exposed form in block" to "no" it will appear with the map.


All of the views may need to be limited to one or more content-types, depending on your use case.

To show phone,fax or mobile fields add Getlocations_fields: Data to your fields list and select the field you want from the dropdown.

An example of a PHP snippet in Getlocations Fields Distance / Proximity Filter
to provide the latitude/longitude of the current user as supplied by the
Smart IP module. See issue #1541620

if (isset($_SESSION['smart_ip']['location'])) {
  return array('latitude' => $_SESSION['smart_ip']['location']['latitude'], 'longitude' => $_SESSION['smart_ip']['location']['longitude']);
}


If you want to modify the dropdown of distance units in the Views Distance filter exposed form you will need to use hook_form_FORM_ID_alter()
in a helper module. In this example the helper module is called "myhelper" and it limits the distance units to Kilometers and Miles only:

function myhelper_form_views_exposed_form_alter(&$form, &$form_state, $form_id) {

  // limit the search units to Miles and Kilometers
  if (isset($form['distance']['search_units']['#options'])) {
    $form['distance']['search_units']['#options'] = array('mi' => t('Miles'), 'km' => t('Kilometers'));
  }

  // change the search distance textfield into a dropdown
  if (isset($form['distance']['search_distance'])) {
    $form['distance']['search_distance']['#type'] = 'select';
    $form['distance']['search_distance']['#options'] = array(5 => '5', 10 => '10', 20 => '20');
    unset($form['distance']['search_distance']['#size']);
    unset($form['distance']['search_distance']['#required']);
  }

}

Theming.
Getlocations Fields pages can be themed by copying the relevant function to your theme's template.php,
renaming it in the usual manner.
eg
theme_getlocations_fields_show() becomes MYTHEME_getlocations_fields_show() where MYTHEME is the name of your theme.
You can edit it there to suit your needs.

These functions can be found in the file getlocations_fields.module

Theming the Getlocations Fields display.
This is done with function theme_getlocations_fields_show()

Theming the Getlocations Fields per instance settings form.
This is done with function theme_getlocations_fields_field_settings_form()

Theming the Getlocations Fields display settings form.
This is done with function theme_getlocations_fields_field_formatter_settings_form()

Theming the Getlocations Fields input form.
This is done with function theme_getlocations_fields_field_widget_form()

Theming the Getlocations Fields defaults settings form.
This is done with function theme_getlocations_fields_settings_form()
