Composer
========
Currency depends on third party Composer packages. For your convenience these
are bundled with the module. However, in rare cases the bundled Composer
autoloader may clash with other Composer autoloaders in your Drupal project. If
you run into the
"Call to undefined method Composer\Autoload\ClassLoader::setPsr4()" error, try
manually updating Currency's Composer dependencies by running the command
"composer update" in Currency's root directory.
