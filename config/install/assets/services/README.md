# Services
Services used and provided by capacity4dev.

The services need an configuration file. Create one by creating a copy of
`config/setting-example.php` and save it as `config/settings.php`.

See service specific configuration documentation about the configuration
variables.


## LDAP
The LDAP service as a proxy script to the LDAP servers by the EC. Its gets the
user related data from the LDAP based on the email address.

The request should be like:
```
http://europa.eu/capacity4dev/services/ldap.php?apikey=<API>&email=<EMAIL>
```

It will return data in the following format:
```
<user>
  <valid>1</valid>
  <title>Mss</title>
  <userid>ldap.test</userid>
  <fname>ldap</fname>
  <lname>test</lname>
  <email>ldap.test@ec.europa.eu</email>
  <dg>EEAS.DEL.MEXICO.004</dg>
  <country iso="BE">Belgium</country>
  <region>Europe</region>
</user>
```

### Configuration
The configuration file (`config/settings.php`) has following configuration:

General:
* `$config['api_keys']` : Array of api keys that have access to the services.

LDAP connection:
* `$config['ldap_host']` : The LDAP server IP address or hostname.
* `$config['ldap_port']` : The port to use to connect to the LDAP server.
* `$config['ldap_pass']` : The password to connect to the LDAP server.
* `$config['ldap_basedn']` : The LDAP Base DN.
* `$config['ldap_binddn']` : The LDAP Bind DN.
* `$config['ldap_attributes']` : An array of LDAP attributes that should be
  returned by the LDAP service.



## LDAP mock
There is an option to access the LDAP service in mock mode:
* No real LDAP call will be perfomend.
* Dummy data will be returned.
* Only the domains as configured in `config/settings.php` will be valid.
* You can force an email address with a valid email domain to be seen as invalid
  by prefix it with `invalid.`.

Add `mock` as an extra get parameter to the request URL:
```
http://europa.eu/capacity4dev/services/ldap.php?mock&apikey=<API>&email=<EMAIL>
```

### Configuration
Mock specific configuration:

* `$config['ldap_mock_domains']` : Array of domains that will be seen as valid
  email domains.
* `$config['ldap_mock_invalid']` : Regex string to identify email addresses that
  will be identified as invalid.


### Mock data
There is a separate config file containing the dummy data. The data is stored in
`config/ldap-mock-data.php`.

Example:
```
$ldap_mock_data['title'] = array(
  'Mr',
  'Ms',
  'Mss',
);

$ldap_mock_data['department'] = array(
  'DEVCO.DGA1.06',
  'DEVCO.F.2.DEL.LEBANON.002',
  'EEAS.DEL.TAJIKISTAN.004',
  'EEAS.DEL.MEXICO.004',
);

$ldap_mock_data['country'] = array(
  array(
    'iso' => 'BE',
    'name' => 'Belgium',
    'region' => 'Europe',
  ),
  array(
    'iso' => 'TJ',
    'name' => 'Tajikistan',
    'region' => 'Central Asia',
  ),
  array(
    'iso' => 'MX',
    'name' => 'Mexico',
    'region' => 'Latin America',
  ),
);
```
