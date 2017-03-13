<?php

/**
 * @file
 * Mock data for the LDAP service.
 */

/**
 * Dummy data to be used in the responses.
 */
$ldap_mock_data = array();

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
