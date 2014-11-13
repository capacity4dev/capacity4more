(function ($) {
  Drupal.behaviors.fullForms = {
    attach: function () {
      $( document ).ready(function() {
        // Hide original select.
        $("#edit-c4m-vocab-date").css('position', 'relative');
        $("#edit-c4m-vocab-date-und").css({
          'display': 'none',
          'position': 'absolute',
          'top': '0',
          'left': '100px'
        });
        // Append new button.
        $("#edit-c4m-vocab-date").append (
          '<button type="button" class="btn toggler btn-primary fa fa-plus">Select Date</button>'
        );

        $(".toggler").click(function () {
          $("#edit-c4m-vocab-date-und").toggle("fast");
          return false;
        })
      });
    }
  };
})(jQuery);
