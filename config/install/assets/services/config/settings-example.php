<?php

/**
 * @file
 * Services configuration.
 */

$config = array();

/**
 * Array of API keys that are allowed to access the services.
 *
 * Example:
 *   8a23dbb1-146d-4142-46fc-cdb5c32a8517
 */
$config['api_keys'] = array();

/**
 * LDAP service configuration.
 */
$config['ldap_host'] = '';
$config['ldap_port'] = '';
$config['ldap_pass'] = '';
$config['ldap_basedn'] = '';
$config['ldap_binddn'] = '';
$config['ldap_attributes'] = array(
  'uid',
  'mail',
  'c',
  'dg',
  'title',
  'givenname',
  'sn',
  'departmentNumber',
);

/**
 * Mock Allowed email domains.
 *
 * Only email addresses with one of these domains will be "valid".
 */
$config['ldap_mock_domains'] = array(
  'ext.ec.europa.eu',
  'ec.europa.eu',
  'cec.eu.int',
  'eeas.europa.eu',
  'ext.eeas.europa.eu',
  'jrc.ec.europa.eu',
  'ext.jrc.ec.europa.eu',
);

/**
 * Pattern that will be used to identify invalid mock email adresses.
 */
$config['ldap_mock_invalid'] = '/^invalid/';
