Currency
========

# Introduction
A language-independent library that provides metadata for current and historic
currencies:
* ISO 4217 currency codes and numbers
* Currency signs
* The number of decimals a currency has
* Where (ISO 3166 country codes) and when (ISO 8601 dates) currencies were and
  are used
* Fixed exchange rates (usually historic)

# Usage
* Currency information is stored in YAML files in `/resources`.
* PHP helpers:
  * `\BartFeenstra\Currency\Currency` is a basic class that serves as a container and a controller for
working with the YAML resources.
  * `\BartFeenstra\Curency\Input` contains a parser for user input.

# Requirements
The library does not have any global requirements.

## Testing
* PHPUnit 3.7.*

## Resources
* Any YAML parser.

## PHP
* PHP 5.3.x or higher
* Symfony YAML 2.1.*

# Integrates with
* [Composer](http://getcomposer.org) (as
[bartfeenstra/currency](https://packagist.org/packages/bartfeenstra/currency))
* [Drupal](http://drupal.org) (through [Currency](http://drupal.org/project/currency))
