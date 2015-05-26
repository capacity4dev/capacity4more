/**
 * @file
 * Kapablo theme global behaviours.
 */

(
  function ($) {
    Drupal.behaviors.discussionFormClasses = {
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

    Drupal.behaviors.eventFormClasses = {
      attach: function (context, settings) {
        $('#edit-c4m-event-type-und').addClass('row');

        var $discussionTypes = $('#edit-c4m-event-type input[type="radio"]');
        $discussionTypes.each(function () {
          if ($(this).is(':checked')) {
            $(this).parent().addClass('active');
          }
          value = $(this).attr('value');
          $(this).parent()
            .addClass('event-type-button')
            .addClass('event-type-' + value)
            .parent().addClass('col-xs-4');
          $(this).click(function () {
            $discussionTypes.each(function () {
              $(this).parent().removeClass('active');
            });
            $(this).parent().addClass('active');
          });
        });
      }
    };

    Drupal.behaviors.youTubeVideo = {
      attach: function (context, settings) {
        // Inject YouTube API script.
        var tag = document.createElement('script');
        tag.src = "//www.youtube.com/player_api";
        var firstScriptTag = document.getElementsByTagName('script')[0];
        firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);
      }
    };

    Drupal.behaviors.collapseExpand = {
      attach: function (context, settings) {
        $('#allGroups').on('shown.bs.collapse', function () {
          $('#toggleMyGroups').html('Show less <i class="fa fa-chevron-right"></i>');
        }).on('hidden.bs.collapse', function () {
          $('#toggleMyGroups').html('Show all <i class="fa fa-chevron-right"></i>');
        });
      }
    };

    Drupal.behaviors.headerResize = {
      attach: function (context, settings) {
        // Make the non logged in header responsive
        var imgWidth  = 954,  // Set the width/height of the background image manually
            imgHeight = 298,
            imgRatio  = imgHeight/imgWidth;

        $(window).load(function() {
          $(window).resize(function() {
            var header          = $('.header-content'),
                headerWidth    = $(header).outerWidth();
            if (headerWidth > imgWidth) {
              headerWidth = imgWidth;
            }
            var responsiveHeight  = headerWidth*imgRatio;
            $('.block-c4m-features-homepage-intro .button-wrapper .btn').height(responsiveHeight);
          }).resize();
        });
      }
    };
  }
)(jQuery);
