;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Money CCK field for CCK 2 and Drupal 6
;;
;; Current  7.x maintainer: kenorb         (http://drupal.org/user/191974)
;; Current  6.x maintainer: markus_petrux  (http://drupal.org/user/39593)
;; Original 5.x author    : Wim Leers      (http://drupal.org/user/99777)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

OVERVIEW
========

This module defines the "money" field. It uses the Currency API, which is
included in the Currency module, to get a list of valid currencies.

The form element for amount is reused from the Formatted Number CCK module.
Decimal points and thousands separators are formatted using the Format Number
API module, where these options are configured from site and/or user setting

REQUIREMENTS
============
* Currency API (http://drupal.org/project/currency)
* Format Number (http://drupal.org/project/format_number)
* Formatted Number CCK (http://drupal.org/project/formatted_number)
  [D7 sandbox: http://drupal.org/sandbox/nouriassafi/1603812]

The currency conversion dialog submodule requires
jQuery 1.3.x (jQuery Update 6.x-2.x) and jQuery UI 1.7+ to work properly.

RECOMMENDED
===========
- Checkall (http://drupal.org/project/checkall)

INSTALLATION
============
- Please, make sure all required modules are installed first.

- Copy all contents of this package to your modules directory preserving
  subdirectory structure.

- Goto Administer > Site building > Modules to install this module.

- Create or edit content types and start adding Money fields. :)

See: http://drupal.org/documentation/install/modules-themes/modules-7

