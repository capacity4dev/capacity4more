#!/bin/sh

# ---------------------------------------------------------------------------- #
#
# Run the coder review.
#
# ---------------------------------------------------------------------------- #


# Do we need to run the coder review?
if [ $CODE_REVIEW != 1 ]; then
  exit 0
fi

PATTERNS="*.features.*,*.field_group.inc,*.strongarm.inc,*.ds.inc,*.context.inc,*.views_default.inc"

echo

# Review custom modules, run each folder seperatly to avoid memory limits.
for dir in $TRAVIS_BUILD_DIR/capacity4more/modules/c4m/*/ ; do
    echo "Reviewing : $dir"
    phpcs --standard=Drupal \
      --colors \
      -p \
      --ignore=$PATTERNS \
      $dir
done

echo

# Review custom themes.
# Disabled as it does not play nice with mixt environments (tpl…).
# See https://github.com/squizlabs/PHP_CodeSniffer/issues/512
#phpcs --standard=Drupal --colors $TRAVIS_BUILD_DIR/capacity4more/themes/c4m
