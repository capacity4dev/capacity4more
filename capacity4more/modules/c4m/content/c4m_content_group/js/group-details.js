(function ($) {
    Drupal.behaviors.groupDetails = {
        attach: function (context, settings) {

            $('fieldset.collapsible', context).once('collapse', function () {
                var $fieldset = $(this);

                // Bind Bootstrap events with Drupal core events.
                $fieldset
                    .on('show.bs.collapse', function () {
                        console.log('show.bs.collapse');
                    })
                    .on('shown.bs.collapse', function () {
                        console.log('shown.bs.collapse')

                    })
                    .on('hide.bs.collapse', function () {
                        console.log('hide.bs.collapse');
                    })
                    .on('hidden.bs.collapse', function () {
                        console.log('hidden.bs.collapse');
                    });
            });

        }
    }
})(jQuery);