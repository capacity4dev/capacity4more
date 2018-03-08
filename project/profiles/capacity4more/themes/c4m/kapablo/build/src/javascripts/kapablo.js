/**
 * @file
 * Kapablo theme global behaviours.
 */

var Drupal = Drupal || {};
var jQuery = jQuery || {};

(function ($) {
    "use strict";

    /**
     * Add proper bootstrap classes to the discussion type selector on the node form of discussions.
     *
     * @type {{attach: Drupal.behaviors.eventFormClasses.attach}}
     */
    Drupal.behaviors.discussionFormClasses = {
        attach: function () {
            var discussionTypes = $("#edit-c4m-discussion-type-und");

            discussionTypes.addClass("row");

            $("input:radio", discussionTypes).each((function () {
                var value = $(this).attr("value");
                // Target the label.
                var parent = $(this).parent();
                parent.addClass("discussion-type-button")
                    .addClass("discussion-type-" + value);
                // Target the wrapper div.
                parent.parent()
                    .addClass("col-xs-6")
                    .addClass("col-sm-3");
            }));
        }
    };

    /**
     * Add proper bootstrap classes to the event type selector on the node form of events.
     *
     * @type {{attach: Drupal.behaviors.eventFormClasses.attach}}
     */
    Drupal.behaviors.eventFormClasses = {
        attach: function () {
            var eventTypes = $("#edit-c4m-event-type-und");

            eventTypes.addClass("row");

            $("input:radio", eventTypes).each((function () {
                var value = $(this).attr("value");
                // Target the label.
                var parent = $(this).parent();
                parent.addClass("event-type-button")
                    .addClass("event-type-" + value);
                // Target the wrapper div.
                parent.parent().addClass("col-xs-4");

            }));
        }
    };

    /**
     * Attach the YouTube iFrame API on the front page (for anonymous users) for the promo video.
     *
     * @type {{attach: Drupal.behaviors.youTubeVideo.attach}}
     */
    Drupal.behaviors.youTubeVideo = {
        attach: function () {
            var tag;
            var firstScriptTag;

            // Only attach IFrame API on frontpage for anonymous users.
            if ($("body").is(".front, .not-logged-in")) {
                // Inject YouTube IFrame API script.
                tag = document.createElement("script");
                tag.src = "https://www.youtube.com/iframe_api";
                firstScriptTag = document.getElementsByTagName("script")[0];
                firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);
            }
        }
    };

    /**
     * Allow wiki pages to be displayed in "fullscreen" mode, and save this state when clicking other pages.
     *
     * @type {{attach: Drupal.behaviors.sidebarCollapseExpand.attach}}
     */
    Drupal.behaviors.sidebarCollapseExpand = {
        attach: function () {
            var url = location.href;
            var fullscreen = _getParameter(url, "fullscreen");
            var sidebar = $("#collapse-sidebar");
            var navLinks = $(".og-menu-link.wiki .c4m-book-og-menu-link, #group-pages-navigation-left .field-name-c4m-content-wiki-page-navigation a, .book-navigation a");

            if (fullscreen === "1") {
                collapseSidebar(sidebar);
            }

            sidebar.on("click", (function () {
                var buttonClasses = $(this).attr("class");
                // If the button has the "collapsed" class: expand the sidebar, otherwise collapse it.
                if (buttonClasses.indexOf("collapsed") >= 0) {
                    expandSidebar($(this), navLinks);
                }
                else {
                    collapseSidebar($(this), navLinks);
                }
            }));

            /**
             * Collapse the sidebar in the Wiki pages.
             *
             * Changes classes of the right and left column,
             * hides the content in the sidebar.
             *
             * @param button
             *  The clicked button element.
             */
            function collapseSidebar(button, navLinks) {
                var groupLeft = $(".group-left");
                var groupRight = $(".group-right");
                var href;

                button.addClass("collapsed");
                button.html("<i class=\"fa fa-chevron-circle-right\"></i>");
                groupLeft.removeClass("col-sm-4").addClass("col-sm-1 sidebar-collapsed");
                groupRight.removeClass("col-sm-8").addClass("col-sm-11");

                $(navLinks).each((function () {
                    href = _addParameter($(this).attr("href"), "fullscreen", "1");
                    $(this).attr("href", href);
                }));
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
            function expandSidebar(button, navLinks) {
                var groupLeft = $(".group-left");
                var groupRight = $(".group-right");
                var href;
                var sidebarContent = $(".collapsible");

                button.removeClass("collapsed");
                button.html("<i class=\"fa fa-chevron-circle-left\"></i> " + Drupal.t("Hide sidebar"));
                groupLeft.removeClass("col-sm-1 sidebar-collapsed").addClass("col-sm-4");
                groupRight.removeClass("col-sm-11").addClass("col-sm-8");
                sidebarContent.show();

                $(navLinks).each((function () {
                    href = _removeURLParameter($(this).attr("href"), "fullscreen");
                    $(this).attr("href", href);
                }));
            }
        }
    };

    /**
     * Allow wiki pages to minimize (collapse) the sub-navigation, and save this state when clicking other pages.
     *
     * @type {{attach: Drupal.behaviors.wikiPagesSubNavigation.attach}}
     */
    Drupal.behaviors.wikiPagesSubNavigation = {
        attach: function () {
            var outerWrapper = $("#group-pages-navigation-left");
            var wrapper;
            var url;
            var collapsed;
            var navLinks;
            var href;

            if (outerWrapper.length === 0) {
                return;
            }

            collapsibleNavigation($("ul[role=\"menu\"]", outerWrapper));

            // .wrapInner() does not retain bound events.
            wrapper = outerWrapper.get(0);

            if (wrapper.length === 0) {
                return;
            }

            url = location.href;
            collapsed = _getParameter(url, "collapsed");

            navLinks = $(".og-menu-link.wiki .c4m-book-og-menu-link, #group-pages-navigation-left .field-name-c4m-content-wiki-page-navigation a, .book-navigation a");

            $(".field-group-format-title", wrapper).on("click", (function () {
                if ($(wrapper).hasClass("collapsed")) {
                    $(navLinks).each((function () {
                        href = _addParameter($(this).attr("href"), "collapsed", "1");
                        $(this).attr("href", href);
                    }));
                }
                else {
                    $(navLinks).each((function () {
                        href = _removeURLParameter($(this).attr("href"), "collapsed");
                        $(this).attr("href", href);
                    }));
                }
            }));

            if (collapsed !== "1") {
                toggleSubpages(wrapper);
            }

            else {
                $(navLinks).each((function () {
                    href = _addParameter($(this).attr("href"), "collapsed", "1");
                    $(this).attr("href", href);
                }));
            }

            /**
             * Toggle subpage state.
             *
             * @param wrapper
             *   The subnavigation wrapper.
             *
             * @returns {boolean}
             */
            function toggleSubpages(wrapper) {
                var speed;

                if (!wrapper.animating || wrapper.animating === null) {
                    wrapper.animating = true;

                    if ($(wrapper).hasClass("speed-fast")) {
                        speed = 300;
                    }
                    else {
                        speed = 1000;
                    }

                    if ($(wrapper).is(".effect-none, .speed-none")) {
                        $("> .field-group-format-wrapper", wrapper).toggle();
                    }
                    else if ($(wrapper).hasClass("effect-blind")) {
                        $("> .field-group-format-wrapper", wrapper).toggle("blind", {}, speed);
                    }
                    else {
                        $("> .field-group-format-wrapper", wrapper).toggle(speed);
                    }

                    wrapper.animating = false;
                    $(wrapper).toggleClass("collapsed");

                    return false;
                }
            }
        }
    };

    /**
     * Load all tooltips in the DOM and initialize them (Bootstrap functionality).
     *
     * @type {{attach: Drupal.behaviors.initTooltips.attach}}
     */
    Drupal.behaviors.initTooltips = {
        attach: function () {
            $("[data-toggle=\"tooltip\"]").tooltip();
        }
    };

    /**
     * Load all dropdown menus in the DOM and initialize them (Bootstrap functionality).
     *
     * @type {{attach: Drupal.behaviors.initDropdowns.attach}}
     */
    Drupal.behaviors.initDropdowns = {
        attach: function () {
            $(".dropdown-toggle").dropdown();
        }
    };

    /**
     * Site has a pretty large banner, functionality skips this header and jumps straight to the h1 tag.
     *
     * @type {{attach: Drupal.behaviors.jumpToTitle.attach}}
     */
    Drupal.behaviors.jumpToTitle = {
        attach: function (context, settings) {
            var timeout = 0;
            var body;

            // Do this only once.
            if (context !== document) {
                return;
            }

            if (settings.c4m && !settings.c4m.jumpToTitle) {
                return;
            }

            // We have to use setTimeout because for some reason when attaching the behaviour.
            // h1 has the scroll top value of 0.
            body = $("body");

            if ($(body).hasClass("admin-menu")) {
                timeout = 500;
            }

            setTimeout((function () {
                // Don't do anything if the user already scrolled to a different
                // position.
                if ($(body).scrollTop() !== 0) {
                    return;
                }
                $("html, body").animate({
                    scrollTop: parseInt($("h1").offset().top) + "px"
                }, 100);
            }), timeout);
        }
    };

    /**
     * Invalidate leaflet maps after 100ms (they are wrongly centered by default).
     *
     * @type {{attach: Drupal.behaviors.fixLeafletMaps.attach}}
     */
    Drupal.behaviors.fixLeafletMaps = {
        attach: function (context, settings) {
            setTimeout((function () {
                if (typeof settings.leaflet !== "undefined" && settings.leaflet instanceof Array) {
                    settings.leaflet[0].lMap.invalidateSize(false);
                }
            }), 100);
        }
    };

    /**
     * Create a "use another mail" link that wipes the e-mail field + enable fields when submitting (AJAX issue).
     *
     * @type {{attach: Drupal.behaviors.registration.attach}}
     */
    Drupal.behaviors.registration = {
        attach: function (context, settings) {
            $(".use-another-email", context).click((function () {
                // Wipe content and focus mail field.
                $("input[name=\"mail\"]").val("").focus();
                return false;
            }));
        }
    };

    Drupal.behaviors.restrictedOrganisations = {
        syncSelectedOrganisations: function () {
            $(".form-item-restricted-organisations input").each(
                function () {
                    if ($(this).attr('checked')) {
                        $(this).parent().show();
                    }
                    else {
                        $(this).parent().hide();
                    }
                }
            );
        },
        syncSelectedOrganisation: function (element) {
            var summaryLabel = $(".form-item-restricted-organisations label[for=" + $(element).attr("id") + "]");
            var originalInput = $("input[id=" + $(element).attr("id") + "]");

            if (element.checked) {
                $(summaryLabel).show();
                $(originalInput).attr('checked', 'checked');
            }
            else {
                $(summaryLabel).hide();
                $(originalInput).removeAttr('checked');
            }
        },
        attach: function (context, settings) {
            // Initial state.
            Drupal.behaviors.restrictedOrganisations.syncSelectedOrganisations();

            // Load the content on attach only.
            var content = $("#restrictedOrganisationsButton", context).data("contentwrapper");

            $('.form-item-restricted-organisations input').on("change", function () {
                Drupal.behaviors.restrictedOrganisations.syncSelectedOrganisation(this);
            });

            // Dynamically load (swap) the content in the popover body.
            $("#restrictedOrganisationsButton", context).once("restrictedOrganisationsButton").popover({
                html: true,
                placement: "right",
                content: function () {
                    return $(content).html();
                }
            }).on('shown.bs.popover', function () {
                // Items inherit the state of the "original" checkboxes, which is hidden if unchecked.
                $("#edit-restricted-organisations-selector label").show();
                $("#edit-restricted-organisations-selector input").once("restrictedOrganisationsListener").on("change", function () {
                    Drupal.behaviors.restrictedOrganisations.syncSelectedOrganisation(this);
                });
            });
        }

    };

  /**
   * Scroll to top functionality.
   *
   * @type {{attach: Drupal.behaviors.registration.attach}}
   */
  Drupal.behaviors.scrollToTop = {
      attach: function (context, settings) {
          var windowHeight = window.innerHeight;

          $('.container--push .page-content').add(window).on('scroll', (function () {
              if ($(this).scrollTop() > windowHeight / 2) {
                  $("#scroll-top:hidden").stop(true, true).fadeIn();
              }
              else {
                  $("#scroll-top").stop(true, true).fadeOut();
              }
          }));
          $(function () {
              $("#scroll-top").on("click", (function (e) {
                  e.preventDefault();
                  $("html, body, .container--push .page-content").animate({scrollTop: 0}, "2000");
                  return false;
              }));
          });
      }
  };

    /**
     * Automatically focus the registration form on the mail field after page load.
     */
    $(window).bind("load", (function () {
        // After ajax processing, the form often gets the id "user-register--2" or similar, therefore use wildcard.
        $("[id^=user-register] input[name=\"mail\"]").focus();
    }));

    /**
     * Disable form buttons on AJAX calls and enable them when AJAX is completed.
     */
    $(document).ajaxStart((function () {
        $(".form-submit").addClass("drupal-ajax-disabled").attr("disabled", "disabled");
    })
    ).ajaxComplete((function () {
        $(".drupal-ajax-disabled").removeClass('drupal-ajax-disabled').each(function () {
          if (!$(this).hasClass(/-disabled/)) {
            $(this).removeAttr('disabled');
          }
        });
      })
    );

    /**
     * Initialise and handle collapsible navigation wrappers.
     *
     * @param element
     */
    function collapsibleNavigation(htmlElement) {
        var element = $(htmlElement);

        element.find("li.expanded").each((function (index, htmlEl) {
            var el = $(htmlEl);
            var subnav = el.find("> .collapse");
            if (subnav.hasClass("in")) {
                el.find("> a > i").removeClass("fa-caret-right").addClass("fa-caret-down");
            }
        }));

        element.find("[data-toggle=\"collapse\"]").on("click", (function (e) {
            var $this = $(this);
            var target;
            var subNavigation;

            e.preventDefault();

            target = $this.data("target");
            subNavigation = $(target);

            subNavigation.toggleClass("in");

            if ($this.hasClass("fa-caret-right")) {
                $this.removeClass("fa-caret-right");
                $this.addClass("fa-caret-down");
            }
            else if ($this.hasClass("fa-caret-down")) {
                $this.removeClass("fa-caret-down");
                $this.addClass("fa-caret-right");
            }

            return false;
        }));
    }

    /**
     * Remove a parameter from an URL string.
     *
     * @param returnUrl
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
        var urlparts = url.split("?");
        var parts;
        var prefix;
        var i;
        var returnUrl;

        if (urlparts.length >= 2) {
            prefix = encodeURIComponent(parameter) + "=";
            parts = urlparts[1].split(/[&;]/g);

            // Reverse iteration as may be destructive.
            i = parts.length;
            while (0 < i--) {
                // Idiom for string.startsWith.
                if (parts[i].lastIndexOf(prefix, 0) !== -1) {
                    parts.splice(i, 1);
                }
            }

            if (parts.length > 0) {
                returnUrl = urlparts[0] + "?" + parts.join("&");
            }
            else {
                returnUrl = urlparts[0];
            }

            return returnUrl;
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
        var urlhash, cl, sourceUrl, urlParts, newQueryString;
        var parameters, parameterParts, i;

        if (url.indexOf("#") > 0) {
            cl = url.indexOf("#");
            urlhash = url.substring(url.indexOf("#"), url.length);
        }
        else {
            urlhash = "";
            cl = url.length;
        }
        sourceUrl = url.substring(0, cl);

        urlParts = sourceUrl.split("?");
        newQueryString = "";

        if (urlParts.length > 1) {
            parameters = urlParts[1].split("&");
            for (i = 0; (i < parameters.length); i++) {
                parameterParts = parameters[i].split("=");
                if (!(replaceDuplicates && parameterParts[0] === parameterName)) {
                    if (newQueryString === "") {
                        newQueryString = "?";
                    }
                    else {
                        newQueryString += "&";
                    }
                    newQueryString += parameterParts[0] + "=" + (parameterParts[1] ? parameterParts[1] : "");
                }
            }
        }
        if (newQueryString === "") {
            newQueryString = "?";
        }

        if (newQueryString !== "" && newQueryString !== "?") {
            newQueryString += "&";
        }
        newQueryString += parameterName + "=" + (parameterValue ? parameterValue : "");
        return urlParts[0] + newQueryString + urlhash;
    }

    /**
     * Helper function to retrieve a named URL parameter.
     *
     * @param url
     *   URL string.
     * @param parameter
     *   Parameter name to return.
     *
     * @private
     */
    function _getParameter(url, parameter) {
        var urlParts = url.split("?");
        var parameters, parameterParts, i;

        if (urlParts.length > 1) {
            parameters = urlParts[1].split("&");
            for (i = 0; (i < parameters.length); i++) {
                parameterParts = parameters[i].split("=");
                if (parameterParts[0] === parameter) {
                    return parameterParts[1];
                }
            }
        }
    }

  Drupal.behaviors.disableSubmitUntilAllRequired = {
    forms: [],

    attach: function (context) {
      // Make sure the rest of the code is not executed on AJAX calls.
      if (context !== document) {
        // Initialize fields when fields get replaced, eg email field on
        // registration form. Otherwise, for image fields, the tagName is FORM
        // or the id is empty.
        if ($(context).prop('tagName').toLowerCase() === 'div' && $(context).attr('id')) {
          $.each(Drupal.behaviors.disableSubmitUntilAllRequired.forms, function () {
            this.initializeFields();
          });
        }
        $.each(Drupal.behaviors.disableSubmitUntilAllRequired.forms, function () {
          this.checkFields();
          this.updateSubmitButtons();
        });
        return;
      }

      var index = 0;
      $('form').each(function () {
        if ($(this).attr('id')) {
          Drupal.behaviors.disableSubmitUntilAllRequired.forms[index] = new formDisableSubmitUntilAllRequired();
          Drupal.behaviors.disableSubmitUntilAllRequired.forms[index].form = $(this);
          Drupal.behaviors.disableSubmitUntilAllRequired.forms[index].initializeFields();
          index++;
        }
      });

      // Initialize on page load after 1 sec. Allow Angular script to run.
      setTimeout(function () {
        $.each(Drupal.behaviors.disableSubmitUntilAllRequired.forms, function () {
          this.checkFields();
          this.updateSubmitButtons();
        });
      }, 1000);
    }
  };

  function formDisableSubmitUntilAllRequired() {
    this.requiredImageFields = null;
    this.emptyImageFields = null;

    this.requiredDragAndDropFields = null;
    this.emptyDragAndDropFields = null;

    this.requiredTextFields = null;
    this.emptyTextFields = null;

    this.requiredWidgetFields = null;
    this.emptyWidgetFields = null;

    this.requiredAngularFields = null;
    this.emptyAngularFields = null;

    this.form = null;
    this.submitButtons = null;

    this.updateSubmitButtons = function () {
      if (this.emptyImageFields || this.emptyDragAndDropFields || this.emptyTextFields || this.emptyWidgetFields || this.emptyAngularFields) {
        if (!this.submitButtons.hasClass('form-disabled')) {
          this.submitButtons.closest('.form-actions').before('<p class="required-fields-message text-danger">' + Drupal.t('Please fill in required fields before submitting the form') + '</p>');
          this.submitButtons.addClass('form-disabled').attr('disabled', 'disabled');
        }
      }
      else {
        this.submitButtons.removeClass('form-disabled').each(function () {
          // The button may have other classes like ".drupal-ajax-disabled".
          if (!$(this).hasClass(/-disabled/)) {
            $(this).removeAttr('disabled');
          }
        });
        this.form.find('.required-fields-message').remove();
      }
    };

    this.checkImageFields = function () {
      var emptyFields = false;
      this.requiredImageFields.each(function () {
        var fid = $(this).find('input.fid');
        if (fid.val() === '0') {
          emptyFields = true;
        }
      });

      this.emptyImageFields = emptyFields;
    };

    this.checkDragAndDropFields = function () {
      var emptyFields = false;
      this.requiredDragAndDropFields.each(function () {
        var fid = $(this).find("input[name$='[fid]']");
        if (fid.val() === '0') {
          emptyFields = true;
        }
      });

      this.emptyDragAndDropFields = emptyFields;
    };

    this.checkTextFields = function () {
      var emptyFields = false;
      this.requiredTextFields.each(function () {
        if ($(this).val() === '' || $(this).val() === '_none' && $(this).prop('tagName').toLowerCase() === 'select') {
          if (($(this).prop("type") === 'textarea') && ($(this).parent().find('iframe'))) {
            if ($(this).parent().find('iframe').contents().find("p").text() === '') {
              emptyFields = true;
            }
          }
          else {
            emptyFields = true;
          }
        }
      });

      this.emptyTextFields = emptyFields;
    };

    this.checkWidgetFields = function () {
      var emptyFields = false;
      this.requiredWidgetFields.each(function () {
        if ($(this).val() === '') {
          emptyFields = true;
        }
      });

      this.emptyWidgetFields = emptyFields;
    };

    this.checkAngularFields = function () {
      var emptyFields = false;
      this.requiredAngularFields.each(function () {
        if ($(this).find('.selected-values > .ng-scope:not(.ng-hide)').length === 0) {
          emptyFields = true;
        }
      });

      this.emptyAngularFields = emptyFields;
    };

    this.checkFields = function () {
      this.checkImageFields();
      this.checkDragAndDropFields();
      this.checkTextFields();
      this.checkWidgetFields();
      this.checkAngularFields();
    };

    this.initializeFields = function () {
      this.requiredImageFields = this.form.find('.field-type-image').has('.form-required');
      this.requiredDragAndDropFields = this.form.find('.field-widget-dragndrop-upload-file').has('.form-required');
      // #security_code is for captcha inputs. We cannot alter that code as it's
      // part of captchalib.
      this.requiredTextFields = this.form.find('.required, #security_code');
      this.requiredWidgetFields = this.form.find('.required-checkbox');
      this.requiredAngularFields = this.form.find('.c4m_vocab_topic, .c4m_vocab_document_type').has('.form-required');
      this.submitButtons = this.form.find('.form-actions').find('.form-submit, .form-preview').not('#edit-cancel, #edit-delete');

      var self = this;

      // Text fields.
      this.requiredTextFields.on('input change', function () {
        // @todo Only Text Fields are needed to be checked here.
        self.checkFields();
        self.updateSubmitButtons();
      });

      // Widgets.
      this.requiredWidgetFields.click(function () {
        // @todo Only Widget Fields are needed to be checked here.
        self.checkFields();
        self.updateSubmitButtons();
      });

      // Angular fields.
      this.requiredAngularFields.click(function () {
        // @todo Only Angular Fields are needed to be checked here.
        self.checkFields();
        self.updateSubmitButtons();
      });
    }
  }

  Drupal.behaviors.disableSubmitButtons = {
    attach: function (context) {
      // We can target all forms not only form.node-form.
      $('form', context).once('disableSubmitButtons', function () {
        var $form = $(this);
        $form.find('#edit-submit, #edit-draft, #edit-cancel, #edit-delete').click(function (e) {
          var el = $(this);
          // Even though the input is clicked the form might not get submitted
          // due to javascript validation. So, we have to remove hidden input
          // added on previous submit buttons clicked.
          el.closest('form').find('.input_button_name').remove();
          el.after('<input type="hidden" class="input_button_name" name="' + el.attr('name') + '" value="' + el.attr('value') + '" />');
          return true;
        });
        $form.submit(function (e) {
          if (!e.isDefaultPrevented()) {
            $form.find('#edit-submit, #edit-draft, #edit-cancel, #edit-delete').addClass('form-disabled').attr('disabled', 'disabled');
            $form.find('#edit-preview-changes').addClass('disabled-preview');
          }
        });
      });
    }
  };

})
(jQuery);

// https://github.com/NV/jquery-regexp-classes
(function (hasClass) {
  jQuery.fn.hasClass = function hasClassRegExp(selector) {
    if (selector && typeof selector.test === "function") {
      for (var i = 0, l = this.length; i < l; i++) {
        var classNames = this[i].className.split(/\s+/);
        for (var c = 0, cl = classNames.length; c < cl; c++) {
          if (selector.test(classNames[c])) {
            return true;
          }
        }
      }
      return false;
    }
    else {
      return hasClass.call(this, selector);
    }
  }

})(jQuery.fn.hasClass);
