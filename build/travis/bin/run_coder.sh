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

PATTERNS="*.features.*,*.field_group.inc,*.strongarm.inc,*.ds.inc,*.context.inc,*.views_default.inc,*.file_default_displays.inc,*.facetapi_defaults.inc"
HAS_ERRORS=0

echo

# Review custom modules, run each folder seperatly to avoid memory limits.
for dir in $TRAVIS_BUILD_DIR/capacity4more/modules/c4m/*/ ; do
  echo "Reviewing : $dir"
  phpcs --standard=Drupal \
    -p \
    --colors \
    --ignore=$PATTERNS \
    $dir

  if [ $? -ne 0 ]; then
    HAS_ERRORS=1
  fi
done

echo


# Review custom themes.
# Disabled as it does not play nice with mixt environments (tpl…).
# See https://github.com/squizlabs/PHP_CodeSniffer/issues/512
#phpcs --standard=Drupal --colors $TRAVIS_BUILD_DIR/capacity4more/themes/c4m


exit $HAS_ERRORS
