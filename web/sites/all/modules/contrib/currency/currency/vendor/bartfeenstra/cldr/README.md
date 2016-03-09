CLDR
====

# Introduction
BartFeenstra/cldr is a PHP library to parse decimals, currency amounts,
percentages, and even integers using [Unicode Common Locale Data Repository
number patterns](http://cldr.unicode.org/translation/number-patterns). Unlike
PHP's [Intl](http://nl1.php.net/manual/en/book.intl.php) extension, this
library allows CLDR patterns to contain non-standard characters (such as HTML)
and it does not have dependencies, which is ideal for shared hosting.

# Usage
It offers four classes (`CurrencyFormatter`, `DecimalFormatter`,
`IntegerFormatter`, and `PercentageFormatter`) which accept a CLDR pattern and
optional replacements for replaceable special symbols, and can be reused to
format different numbers.

# Requirements
* PHP 5.3.x or higher
* PHPUnit 3.7.* (for running tests only)

# Integrates with
* [Composer](http://getcomposer.org) (as
[bartfeenstra/cldr](https://packagist.org/packages/bartfeenstra/cldr))