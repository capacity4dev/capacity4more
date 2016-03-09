/**
 * @file
 * Contains behavior to initialize DnD instances.
 */

(function ($) {
  Drupal.behaviors.dragndropUpload = {
    attach: function (context, settings) {
      if (!settings.dragndropUpload) {
        return;
      }

      $.each(settings.dragndropUpload, function (selector, settings) {
        $(selector, context).once('dnd-upload', function () {
          var $droppable = $(this);

          var dnd;
          // Check if a droppable is a mirror.
          if (settings.asMirrorFor) {
            // Try to get DnD instance.
            dnd = $(settings.asMirrorFor);
            // Add the event callback only if droppable is found.
            if (dnd.size()) {
              // Add an event callback for adding a droppable, because may be
              // the mirrored droppable does not exist yet, so act when it is
              // initiated.
              dnd.one('dnd:init', function () {
                $(this).DnD().addDroppable($droppable);
              });
            }
            // Main droppable area is not found, so remove the processed class.
            else {
              $droppable.removeClass('dnd-upload-processed');
            }
          }
          // Otherwise just create a new droppable instance.
          else {
            dnd = $droppable.DnD(settings);
            $droppable.bind('dnd:showErrors', showErrors.bind(dnd));
            $droppable.bind('dnd:send:options', sendOptions.bind(dnd));
            $droppable.bind('dnd:addFiles:after', afterFilesAdded.bind(dnd));
          }
        });
      });
    },

    detach: function (context, settings) {
      if (settings.dragndropUpload) {
        $.each(settings.dragndropUpload, function (selector) {
          var $droppable = $(selector, context);
          var dnd = $droppable.DnD();
          if (dnd) {
            $droppable.removeClass('dnd-upload-processed');
            dnd.removeDroppable($droppable);
          }
        });
      }
    }
  };

  /**
   * Default dnd:showErrors callback for DnD.
   *
   * @param event
   * @param errors
   */
  var showErrors = function (event, errors) {
    var me = this;
    var messages = [];
    // Go through the errors array and create human-readable messages.
    $.each(errors, function (i, error) {
      if (!me.settings.errorsInfo[error.type]) {
        error.type = 'unknown';
      }
      messages.push(Drupal.t(me.settings.errorsInfo[error.type], error.args));
    });

    alert(messages.join());
  };

  /**
   * Default dnd:send:options callback for DnD.
   *
   * Adds Drupal.ajax support (including ajax commands).
   *
   * @param event
   * @param options
   * @param {DnDFormData} dndFormData
   */
  var sendOptions = function (event, options, dndFormData) {
    var me = this;
    /**
     * Create a simple Drupal.ajax instance.
     */
    var ajaxSettings = {
      url: me.settings.url,
      event: 'dnd-never-triggered'
    };
    var ajax = new Drupal.ajax(false, me.$droppables, ajaxSettings);
    var drupalAjaxOptions = $.extend({}, ajax.options);

    options = $.extend(options, drupalAjaxOptions, {
      cache: false,
      data: null,
      contentType: false,
      processData: false,
      beforeSend: function (xmlhttprequest, options) {
        options.data = drupalAjaxOptions.data;
        
        // Call standard Drupal ajax methods.
        drupalAjaxOptions.beforeSerialize(me.$droppables, options);
        drupalAjaxOptions.beforeSend(xmlhttprequest, options);

        // Put elements from options.data into the dndFormData.
        dndFormData.multiAppend(options.data);
      }
    });
  };

  /**
   * Default dnd:files:after callback for DnD.
   *
   * Send files automatically after they were dropped.
   */
  var afterFilesAdded = function () {
    this.send();
  };
})(jQuery);
