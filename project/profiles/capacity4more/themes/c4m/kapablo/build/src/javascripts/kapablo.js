/**
 * @file
 * Kapablo theme global behaviours.
 */

(function ($) {

  Drupal.behaviors.discussionFormClasses = {
    attach: function (context, settings) {
      $('#edit-c4m-discussion-type-und').addClass('row');

      var $discussionTypes = $('#edit-c4m-discussion-type input[type="radio"]');
      $discussionTypes.each(function () {
        if ($(this).is(':checked')) {
          $(this).parent().addClass('active');
        }
        var value = $(this).attr('value');
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
        var value = $(this).attr('value');
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
      // Inject YouTube IFrame API script.
      var tag = document.createElement('script');
      tag.src = "https://www.youtube.com/iframe_api";
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
      var url = location.href;
      var fullscreen = _getParameter(url, 'fullscreen');

      if (fullscreen === '1') {
        collapseSidebar($('#collapse-sidebar'));
      }

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
        groupLeft.removeClass('col-sm-4').addClass('col-sm-1 sidebar-collapsed');
        groupRight.removeClass('col-sm-8').addClass('col-sm-11');
        sidebarContent.hide();

        var nav_links = $('.og-menu-link.wiki .c4m-book-og-menu-link, #group-pages-navigation-left .field-name-c4m-content-wiki-page-navigation a');
        var href;
        $(nav_links).each(function () {
          href = _addParameter($(this).attr('href'), 'fullscreen', '1');
          $(this).attr('href', href);
        });
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
        button.html('<i class="fa fa-chevron-circle-left"></i> ' + Drupal.t('Hide sidebar'));
        groupLeft.removeClass('col-sm-1 sidebar-collapsed').addClass('col-sm-4');
        groupRight.removeClass('col-sm-11').addClass('col-sm-8');
        sidebarContent.show();

        var nav_links = $('.og-menu-link.wiki .c4m-book-og-menu-link, #group-pages-navigation-left .field-name-c4m-content-wiki-page-navigation a');
        var href;
        $(nav_links).each(function () {
          href = _removeURLParameter($(this).attr('href'), 'fullscreen');
          $(this).attr('href', href);
        });
      }
    }
  };

  Drupal.behaviors.wikiPagesSubNavigation = {
    attach: function (context, settings) {
      var $wrapper = $('#group-pages-navigation-left');

      collapsibleNavigation($wrapper.find('ul[role="menu"]'));

      // .wrapInner() does not retain bound events.
      var wrapper = $wrapper.get(0);
      // Don't animate multiple times.
      if (!wrapper.animating) {
        wrapper.animating = true;
        var speed = $wrapper.hasClass('speed-fast') ? 300 : 1000;
        if ($wrapper.hasClass('effect-none') && $wrapper.hasClass('speed-none')) {
          $('> .field-group-format-wrapper', wrapper).toggle();
        }
        else if ($wrapper.hasClass('effect-blind')) {
          $('> .field-group-format-wrapper', wrapper).toggle('blind', {}, speed);
        }
        else {
          $('> .field-group-format-wrapper', wrapper).toggle(speed);
        }
        wrapper.animating = false;
        $wrapper.toggleClass('collapsed');

        return false;
      }
    }
  };

  Drupal.behaviors.initTooltips = {
    attach: function (context, settings) {
      var tooltips = $('[data-toggle="tooltip"]');
      tooltips.tooltip();
    }
  };

  Drupal.behaviors.initDropdowns = {
    attach: function (context, settings) {
      $('.dropdown-toggle').dropdown();
    }
  };

  Drupal.behaviors.fixLeafletMaps = {
    attach: function (context, settings) {
      setTimeout(function () {
        if (typeof settings.leaflet != 'undefined' && settings.leaflet instanceof Array) {
          settings.leaflet[0].lMap.invalidateSize(false);
        }
      }, 100);
    }
  };

  Drupal.behaviors.registration = {
    attach: function (context, settings) {
      $('.use-another-email', context).click(function () {
        $('input[name="mail"]').val('').focus();
        return false;
      });

      $('#user-register-form').submit(function () {
        $(':disabled', this).prop('disabled', false);
      });
    }
  };

  // Disable form buttons on AJAX calls.
  $(document)
    .ajaxStart(function () {
      $('.form-submit').addClass('drupal-ajax-disabled').attr('disabled', 'disabled');
    })
    .ajaxComplete(function () {
      $('.drupal-ajax-disabled').removeAttr('disabled');
    });

  function collapsibleNavigation(element) {
    var element = $(element);

    element.find('li.expanded').each(function (index, el) {
      var el = $(el);
      var subnav = el.find('> .collapse');
      if (subnav.hasClass('in')) {
        el.find('> a > i').removeClass('fa-plus').addClass('fa-minus');
      }
    });

    element.find('[data-toggle="collapse"]').on('click', function (e) {
      e.preventDefault();

      var $this = $(this);

      var target = $this.data('target');
      var sub_navigation = $(target);

      sub_navigation.toggleClass('in');

      if ($this.hasClass('fa-plus')) {
        $this.removeClass('fa-plus');
        $this.addClass('fa-minus');
      }
      else if ($this.hasClass('fa-minus')) {
        $this.removeClass('fa-minus');
        $this.addClass('fa-plus');
      }

      return false;
    });
  }

  /**
   * Remove a parameter from an URL string.
   *
   * @param url
   *   Url or path to remove parameter from.
   * @param parameter
   *   Name of the parameter to remove.
   *
   * @returns {*}
   *
   * @private
   */
  function _removeURLParameter(url, parameter) {
    // Prefer to use l.search if you have a location/link object.
    var urlparts = url.split('?');
    if (urlparts.length >= 2) {

      var prefix = encodeURIComponent(parameter) + '=';
      var pars = urlparts[1].split(/[&;]/g);

      // Reverse iteration as may be destructive.
      for (var i = pars.length; i-- > 0;) {
        // Idiom for string.startsWith.
        if (pars[i].lastIndexOf(prefix, 0) !== -1) {
          pars.splice(i, 1);
        }
      }

      if (pars.length > 0) {
        url = urlparts[0] + '?' + pars.join('&');
      }
      else {
        url = urlparts[0];
      }

      return url;
    }
    else {
      return url;
    }
  }

  /**
   * Add a parameter to an URL string.
   *
   * @param url
   *   Url or path to add parameter to.
   * @param parameterName
   *   Name of the parameter to add.
   * @param parameterValue
   *   Value to give the parameter.
   *
   * @returns {string}
   *
   * @private
   */
  function _addParameter(url, parameterName, parameterValue) {
    var replaceDuplicates = true;
    var urlhash;
    var cl;

    if (url.indexOf('#') > 0) {
      cl = url.indexOf('#');
      urlhash = url.substring(url.indexOf('#'), url.length);
    }
    else {
      urlhash = '';
      cl = url.length;
    }
    var sourceUrl = url.substring(0, cl);

    var urlParts = sourceUrl.split("?");
    var newQueryString = "";

    if (urlParts.length > 1) {
      var parameters = urlParts[1].split("&");
      for (var i = 0; (i < parameters.length); i++) {
        var parameterParts = parameters[i].split("=");
        if (!(replaceDuplicates && parameterParts[0] === parameterName)) {
          if (newQueryString === "") {
            newQueryString = "?";
          }
          else {
            newQueryString += "&";
          }
          newQueryString += parameterParts[0] + "=" + (parameterParts[1] ? parameterParts[1] : '');
        }
      }
    }
    if (newQueryString === "") {
      newQueryString = "?";
    }

    if (newQueryString !== "" && newQueryString !== '?') {
      newQueryString += "&";
    }
    newQueryString += parameterName + "=" + (parameterValue ? parameterValue : '');
    return urlParts[0] + newQueryString + urlhash;
  };

  function _getParameter(url, parameter) {
    var urlParts = url.split("?");

    if (urlParts.length > 1) {
      var parameters = urlParts[1].split("&");
      for (var i = 0; (i < parameters.length); i++) {
        var parameterParts = parameters[i].split("=");
        if (parameterParts[0] === parameter) {
          return parameterParts[1];
        }
      }
    }
  };

})
(jQuery);
