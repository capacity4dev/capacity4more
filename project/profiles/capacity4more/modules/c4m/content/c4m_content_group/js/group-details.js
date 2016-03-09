/**
 * @file
 * Script to show/hide group details.
 */

(
  function ($) {
    Drupal.behaviors.groupDetails = {
      attach: function(context, settings) {
        $('fieldset.collapsible', context).once('collapseGroupDetails', function () {
          var $fieldset = $(this);

          // Prevent default behaviour of collapsible field kicking in.
          // If not, we go to top of page on click.
          $fieldset.find('[data-toggle=collapse]').on('click', function (e) {
            e.preventDefault();
          });

          // Bind some behaviour on bootstrap events.
          $fieldset
            .on('show.bs.collapse', function() {
              $fieldset.find('> legend a.fieldset-legend').html(Drupal.t('Less Details'));
            })
            .on('hide.bs.collapse', function() {
              $fieldset.find('> legend a.fieldset-legend').html(Drupal.t('More Details'));
            });
        });
      }
    }
  }
)(jQuery);
