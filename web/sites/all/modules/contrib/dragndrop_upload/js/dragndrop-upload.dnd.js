/**
 * @file
 * Contains DnD class.
 *
 * @param {jQuery} droppable
 *  jQuery object of droppable areas.
 * @param {Object} settings
 *
 * Each droppable area has these events:
 *
 *  dnd:addFiles:before
 *    Arguments: event, transFiles
 *
 *  dnd:addFiles:added
 *    Arguments: event, dndFile, index, filesNumber
 *
 *  dnd:addFiles:after
 *    Arguments: event, transFiles
 *
 *  dnd:createPreview
 *    Arguments: dndFile, {FileReader} reader
 *
 *  dnd:removePreview
 *    Arguments: event, dndFile
 *
 *  dnd:validateFile
 *    Arguments: event, dndFile
 *
 *  dnd:showErrors
 *    Arguments: event, dndFile
 *
 *  dnd:removeFile
 *    Arguments: event, dndFile
 *
 *  dnd:removeFile:empty
 *    Arguments: event
 *
 *  dnd:send:options
 *    Arguments: event, options, {DnDFormData} dndFormData
 *
 *  dnd:send:complete
 *    Arguments: response, status, sentFiles
 *
 *  dnd:init
 *    Arguments: event
 *
 *  dnd:destroy:before
 *    Arguments: event
 *
 *  dnd:destroy:after
 *    Arguments: event
 */
function DnD(droppable, settings) {
  this.$droppables = jQuery();
  this.settings = settings;
  this.jqVersion = parseInt(jQuery.fn.jquery.replace(/\./g, ''));

  this.addDroppable(droppable);
}

(function ($) {
  DnD.prototype = {
    $droppables: null,
    $activeDroppable: null,
    filesList: null,
    settings: null,

    /**
     * Attach events to the given droppable areas.
     *
     * @param {jQuery} $droppables
     */
    attachEvents: function ($droppables) {
      var me = this;
      $.each($droppables, function (i, droppable) {
        $.each(me.eventsList, function (name, func) {
          droppable[name] = func.bind(me);
        });
      });

      // Attach event to create a preview when a file is added.
      $droppables.bind('dnd:addFiles:added', me.createPreview);

      // Add default validators.
      var validators = me.settings.validators || {};
      $.each(validators, function (name) {
        if (me.validatorsList[name]) {
          $droppables.bind('dnd:validateFile', me.validatorsList[name].bind(me));
        }
      });

      if (me.settings.cardinality != -1) {
        $droppables.bind('dnd:validateFile', me.validatorsList.filesNum.bind(me));
      }

      /**
       * Add an event callback to remove from DnD files that have been sent.
       */
      $droppables.bind('dnd:send:beforeSend', function (event, response, status, sentFiles) {
        me.removeFiles(sentFiles);
      });
    },

    /**
     * Detach events from the given droppable areas.
     *
     * @param {jQuery} $droppables
     */
    detachEvents: function ($droppables) {
      var me = this;

      $.each($droppables, function (i, droppable) {
        $.each(me.eventsList, function (name) {
          droppable[name] = null;
        });
      });

      // Detach events of creating a preview when a file is added.
      $droppables.unbind('dnd:addFiles:added');

      // Detach validators.
      $droppables.unbind('dnd:validateFile');
    },

    eventsList: {
      /**
       * Fires when file was dropped in the droppable area.
       *
       * @param {Event} event
       */
      ondrop: function (event) {
        // Prevent drop event from bubbling through parent elements.
        event.stopPropagation();
        event.preventDefault();

        var transFiles = event.dataTransfer.files;
        if (transFiles.length == 0) {
          return;
        }

        var $dropppable = $(event.currentTarget);
        $dropppable.removeClass('drag-over').addClass('dropped');

        this.addFiles($dropppable, transFiles);
      },

      /**
       * Fires every time when file is under the droppable area.
       *
       * @param event
       */
      ondragover: function (event) {
        // Prevent the event from bubbling through parent elements.
        event.stopPropagation();
        event.preventDefault();

        $(event.target).addClass('drag-over');
      },

      /**
       * Fires when file was leave the droppable area.
       *
       * @param event
       */
      ondragleave: function (event) {
        // Prevent the event from bubbling through parent elements.
        event.stopPropagation();
        event.preventDefault();

        $(event.target).removeClass('drag-over');
      }
    },

    validatorsList: {
      'file_validate_size': function (event, dndFile) {
        var settings = this.settings;
        var maxSize = settings.validators.file_validate_size[0] + '';

        if (dndFile.file.size > maxSize) {
          dndFile.error = {
            type: 'fileSize',
            args: {
              '@filename': dndFile.file.name,
              '@filesize': dndFile.file.size
            }
          };
        }
      },

      'file_validate_extensions': function (event, dndFile) {
        var settings = this.settings;
        var ext = dndFile.file.name.split('.').pop().toLowerCase();
        var isValid = false;

        var extList = settings.validators
          .file_validate_extensions[0].toLowerCase().split(/\s+/);
        $.each(extList, function (index, allowedExt) {
          if (allowedExt == ext) {
            isValid = true;
            return false;
          }
          return true;
        });

        if (!isValid) {
          dndFile.error = {
            type: 'fileExt',
            args: {
              '@filename': dndFile.file.name,
              '@allowed': extList.join(','),
              '@ext': ext
            }
          };
        }
      },

      filesNum: function (event, dndFile, filesList) {
        var settings = this.settings;

        if (filesList.length >= settings.cardinality) {
          dndFile.error = {
            type: 'filesNum',
            args: {
              '@filename': dndFile.file.name,
              '@number': filesList.length,
              '@allowed': settings.cardinality
            }
          };
        }
      }
    },

    /**
     * Add files to the droppable area.
     *
     * @param {jQuery} $droppable
     *  A droppable area that should receive files.
     * @param {Array} transFiles
     *  Array of files that should be added to the dropppable area.
     */
    addFiles: function ($droppable, transFiles) {
      var dndFile, errors = [], filesList = this.getFilesList();
      $droppable.trigger('dnd:addFiles:before', [transFiles]);

      for (var i = 0, n = transFiles.length; i < n; i++) {
        dndFile = {
          file: transFiles[i],
          $droppable: $droppable,
          $preview: null,
          error: null
        };

        this.validateFile(dndFile, filesList);
        if (dndFile.error) {
          errors.push(dndFile.error);
          continue;
        }

        filesList.push(dndFile);

        /**
         * Each dndFile have:
         *  - file {Object}: dropped file object.
         *  - $droppable {jQuery|null}: preview object.
         *  - $preview {jQuery|null}: preview object.
         *  - error {String}: error message if present.
         *
         * @type {Array}
         */
        this.setFilesList(filesList);

        // Trigger event telling that dndFile has been added.
        $droppable.trigger('dnd:addFiles:added', [dndFile, i, n]);
      }

      if (errors.length) {
        this.showErrors($droppable, errors);
        return;
      }

      // Trigger the event telling that all files have been added.
      $droppable.trigger('dnd:addFiles:after', [transFiles]);
    },

    /**
     * Add new droppable area.
     *
     * @param {string|jQuery} droppable
     */
    addDroppable: function (droppable) {
      var $droppable = $(droppable);
      this.attachEvents($droppable);
      $droppable.data('DnD', this);

      this.$droppables = this.$droppables.add($droppable);

      $droppable.trigger('dnd:init');
    },

    /**
     * Remove droppable area.
     *
     * @param {string|jQuery} droppable
     */
    removeDroppable: function (droppable) {
      var $droppable = $(droppable);

      $droppable.trigger('dnd:destroy:before', [$droppable]);

      this.detachEvents($droppable);
      $droppable.data('DnD', null);

      this.$droppables = this.$droppables.not($droppable);

      $droppable.trigger('dnd:destroy:after', [$droppable]);
    },

    /**
     * Create previews of dropped files.
     *
     * @param event
     * @param dndFile
     */
    createPreview: function (event, dndFile) {
      var reader = new FileReader();

      // Save createPreview handlers.
      var createPreviewEvent = dndFile.$droppable.DnD()
        ._getEventHandlers(dndFile.$droppable, 'dnd:createPreview');

      reader.onload = function () {
        // Give others an ability to build a preview for a dndFile.
        // Trigger event for all droppables. Each one should decide what to do
        // accodring to the $droppable reference in the dndFile object.
        //
        // It is needed to call event handlers in a such weird way because in
        // case of auto upload at this point events are already detached because
        // of sent Drupal.ajax request.
        $.each(createPreviewEvent, function (i, event) {
          if (event.hasOwnProperty('handler')) {
            var result = event.handler(dndFile, reader);
            // Allow callbacks to prevent others running.
            if (result === false) {
              return result;
            }
            return true;
          }
        });
      };
      reader.readAsDataURL(dndFile.file);
    },

    /**
     * Remove preview for the dndFile.
     *
     * @param dndFile
     */
    removePreview: function (dndFile) {
      // Give others an ability to remove dndFile preview.
      // Trigger event for all droppables. Each one should decide what to do
      // accodring to the $droppable reference in the dndFile object.
      this.$droppables.trigger('dnd:removePreview', [dndFile]);
    },

    /**
     * Validate dndFile by given function.
     *
     * @param dndFile
     * @param filesList
     *  Array of files already dropped.
     */
    validateFile: function (dndFile, filesList) {
      dndFile.$droppable.trigger('dnd:validateFile', [dndFile, filesList]);
    },

    /**
     * Show errors for the droppable.
     *
     * @param $droppable
     * @param errors
     */
    showErrors: function ($droppable, errors) {
      if (typeof errors != 'object') {
        errors = [errors];
      }

      $droppable.trigger('dnd:showErrors', [errors]);
    },

    /**
     * Remove a dndFile from droppable area.
     *
     * @param dndFile
     *  The dndFile that should be removed.
     */
    removeFile: function (dndFile) {
      var me = this;
      var droppedFiles = me.getFilesList();

      $.each(droppedFiles, function (i, eachFile) {
        if (dndFile == eachFile) {
          droppedFiles.splice(i, 1);
          me.removePreview(dndFile);
          return false;
        }
        return true;
      });

      me.setFilesList(droppedFiles);

      // Trigger an event telling that dndFile has been removed.
      dndFile.$droppable.trigger('dnd:removeFile', [dndFile]);
      if (!me.getFilesList(dndFile.$droppable).length) {
        dndFile.$droppable.trigger('dnd:removeFile:empty', [dndFile.$droppable]);
      }
    },

    /**
     * Remove dndFiles from the droppable area.
     *
     * @param dndFiles
     *  Files to be removed. Removes all dndFiles if undefined.
     */
    removeFiles: function (dndFiles) {
      var me = this;
      dndFiles = dndFiles || this.getFilesList();

      $.each(dndFiles, function (index, eachFile) {
        me.removeFile(eachFile);
      });
    },

    /**
     * Get files list of the droppable area.
     *
     * $droppable {jQuery} Droppables to get files list from.
     *
     * @returns {*|Array}
     */
    getFilesList: function ($droppables) {
      var list = [];
      if ($droppables) {
        $.each(this.filesList, function (a, dndFile) {
          /**
           * jQuery().is() is not working?
           */
          $.each($droppables, function (b, droppable) {
            if (dndFile.$droppable[0] == droppable) {
              list.push(dndFile);
            }
          });
        });
      }
      else {
        list = this.filesList;
      }
      return list || [];
    },

    /**
     * Get files list of the droppable area.
     *
     * @param filesList
     */
    setFilesList: function (filesList) {
      this.filesList = filesList || [];
    },

    /**
     * Send files.
     */
    send: function ($droppables) {
      var me = this;
      $droppables = $droppables || this.$droppables;

      // Set flag telling that files are sending at the moment.
      me.sending = true;

      var filesList = this.getFilesList($droppables);
      if (!filesList.length) {
        return;
      }

      // This object will be converted into FormData before sending.
      var dndFormData = new DnDFormData();
      var sentFiles = [];

      // Append filesList to the DnDFormData.
      $.each(filesList, function (index, dndFile) {
        dndFormData.append(me.settings.name, dndFile.file, dndFile.file.name);
        // Add dndFile to the sent array to remove it later.
        sentFiles.push(dndFile);
      });

      var options = {
        url: me.settings.url,
        type: 'POST',
        cache: false,
        // Do not set data here because of incorrect handling of content-type
        // header in jQuery 1.4.4. Instead, set it in the beforeSend callback.
        data: null,
        contentType: false,
        processData: false
      };

      // Give an ability to modify ajax options before sending request.
      $droppables.trigger('dnd:send:options', [options, dndFormData]);

      // Override beforeSend callback to set this.sending property to false.
      var beforeSendCallback = options.beforeSend;
      options.beforeSend = function (xmlhttprequest, options) {
        beforeSendCallback(xmlhttprequest, options);

        // Transform DnDFormData into FormData object.
        options.data = dndFormData.render();
      };

      /**
       * Save 'dnd:send:complete' handlers of the
       * $droppables in a separate variable as the element can be destroyed
       * (or behaviors can be detached) after the ajax request.
       */
      var completeEvent = me._getEventHandlers($droppables, 'dnd:send:complete');

      // Override complete callback to set this.sending property to false.
      var completeCallback = options.complete;
      options.complete = function (response, status) {
        me.sending = false;
        me.removeFiles(sentFiles);

        completeCallback(response, status);

        // Call 'dnd:send:complete' handlers that have been saved earlier.
        $.each(completeEvent, function (i, event) {
          if (event.hasOwnProperty('handler')) {
            return event.handler(response, status, sentFiles);
          }
        });
      };

      // Finally, send a request.
      $.ajax(options);
    },

    /**
     * Get object event handlers.
     *
     * @param $obj
     * @param [eventName]
     *    Event name to return.
     * @returns {*}
     * @private
     */
    _getEventHandlers: function ($obj, eventName) {
      var events;
      if (this.jqVersion < 180) {
        events = $obj.data('events');
      }
      else {
        events = $._data($obj[0], "events");
      }

      var event = {};
      if (events[eventName]) {
        event = $.extend({}, events[eventName]);
      }

      return eventName ? event : events;
    }
  };

  /**
   * jQuery plugin to help to work with DnD class.
   *
   * @returns {DnD}
   * @constructor
   */
  $.fn.DnD = function (settings) {
    var dnd = this.data('DnD');
    if (!dnd && settings) {
      this.data('DnD', new DnD(this, settings));
      dnd = this.data('DnD');
    }

    return dnd;
  };
})(jQuery);
