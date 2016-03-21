# Project directory
The project directory contains all the custom code for the project:

- [Install profiles](profiles/README.md).
- [Modules](modules/README.md).
- [Themes](themes/README.md).
- [Libraries](libraries/README.md).

Put all the custom code in this directory. The by default available directory
structure is an example, feel free to create the structure as required for the
project you are building.

Integrating this code into the project can be done by symlinking them into the
web directory by implemnting one of the hooks (see
`config/install/drupal_make_after.sh`) for an example.

Including the custom functionality code into the build is done by copying the
project (sub)directories into the build (see
`config/build/drupal_make_after.sh`) for an example.

[See druleton documentation about project][link-project].



[link-project]: ../bin/docs/project.md
