(
  function ($) {
    Drupal.behaviors.discussionClasses = {
      attach: function (context, settings) {
        $('#edit-c4m-discussion-type-und').addClass('row');

        var $discussionTypes = $('#edit-c4m-discussion-type input[type="radio"]');
        $discussionTypes.each(function () {
          if ($(this).is(':checked')) {
            $(this).parent().addClass('active');
          }
          value = $(this).attr('value');
          $(this).parent()
            .addClass('discussion-type-button')
            .addClass('discussion-type-' + value)
            .parent().addClass('col-xs-6').addClass('col-sm-3');
          $(this).click(function () {
            $discussionTypes.each(function () {
              $(this).parent().removeClass('active');
            });
            $(this).parent().addClass('active');
          });
        });
      }
    };
    Drupal.behaviors.vocabToggle = {
      attach: function (context, settings) {
        var $parentSelectors = $('.popover .parent-select');
        $parentSelectors.each(function () {
          if ($(this).siblings('ng-hide')) {
            $(this).addClass('parent-hide');
          }

          $(this).click(function() {
            console.log(this);
            if ($(this).hasClass('parent-hide')) {
              $(this).removeClass('parent-hide');
            }
            else {
              $(this).addClass('parent-hide');
            }
          });
        });
      }
    };
  }
)(jQuery);
