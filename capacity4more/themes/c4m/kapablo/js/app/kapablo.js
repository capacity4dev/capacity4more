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

    Drupal.behaviors.sidebarCollapseExpand = {
      attach: function (context, settings) {
        $('#collapse-sidebar').on('click', function () {
          var buttonClasses = $(this).attr("class");
          // If the button has the "collapsed" class,
          // Expand the sidebar, otherwise collapse it.
          if (buttonClasses.indexOf("collapsed") >= 0) {
            expandSidebar($(this));
          }
          else {
            collapseSidebar($(this));
          }
        });

        /**
         * Collapse the sidebar in the Wiki pages.
         *
         * Changes classes of the right and left column,
         * hides the content in the sidebar.
         *
         * @param button
         *  The clicked button element.
         */
        function collapseSidebar(button) {
          var groupLeft = $('.group-left');
          var groupRight = $('.group-right');
          var sidebarContent = $('.collapsible');
          button.addClass('collapsed');
          button.html('<i class="fa fa-chevron-circle-right"></i>');
          groupLeft.removeClass('col-sm-4').addClass('col-sm-1');
          groupRight.removeClass('col-sm-8').addClass('col-sm-11');
          sidebarContent.hide();
        }

        /**
         * Expand the sidebar in the Wiki pages.
         *
         * Changes classes of the right and left column,
         * shows the content in the sidebar.
         *
         * @param button
         *  The clicked button element.
         */
        function expandSidebar(button) {
          var groupLeft = $('.group-left');
          var groupRight = $('.group-right');
          var sidebarContent = $('.collapsible');
          button.removeClass('collapsed');
          button.html('<i class="fa fa-chevron-circle-left"></i>');
          groupLeft.removeClass('col-sm-1').addClass('col-sm-4');
          groupRight.removeClass('col-sm-11').addClass('col-sm-8');
          sidebarContent.show();
        }
      }
    };
  }
)(jQuery);
