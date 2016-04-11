<?php
/**
 * @file
 * Hooks provided by the C4M Email Domain module.
 */

/**
 * Define validation types for the email domain.
 */
function hook_c4m_domain_validators_info() {
  return array(
    'c4m_domain_validate_ldap' => array(
      'name' => t('EC LDAP service'),
      'description' => t('Validate the email address by passing it to the EC LDAP service.'),
      'callback' => 'c4m_domain_validate_ldap_check',
    ),
  );
}
