/**
 * @file
 * Contains DnDUploadMedia class.
 */

/**
 * DnDUploadMedia class.
 *
 * Attaches event callbacks to make Media browser work when clicking on "Browse"
 * button.
 *
 * @param {jQuery} $droppable
 * @param {Object} settings
 */
var DnDUploadMedia = function ($droppable, settings) {
  this.dnd = $droppable.DnD();
  if (!this.dnd) {
    throw new Error('The $droppable does not contain an instance of DnD!');
  }

  this.$droppable = $droppable;
  this.dnd.$droppables.data('DnDUploadMedia', this);
  this.mediaSettings = settings;
  this.dnduImageInstance = this.dnd.$droppables.data('DnDUploadImage');
  this.dnduFileInstance = this.dnd.$droppables.data('DnDUploadFile');

  this.attachEvents(this.dnd.$droppables);
};

(function ($) {
  DnDUploadMedia.prototype = $.extend({}, DnDUploadAbstract.prototype, {
    /**
     * Attach events to the given droppable areas.
     *
     * @param {jQuery} $droppables
     */
    attachEvents: function ($droppables) {
      var me = this;
      var settings = me.dnd.settings;

      $(settings.browseButton).unbind('click')
        .bind('click', me.eventsList.browseButtonClick.bind(me));

      me.parent().attachEvents.call(me, $droppables);
    },

    /**
     * Detach events from the given droppable areas.
     *
     * @param {jQuery|undefined} $droppables
     */
    detachEvents: function ($droppables) {
      var me = this;
      var settings = me.dnd.settings;

      me.parent().detachEvents.call(me, $droppables);
      $(settings.browseButton).unbind('click');
    },

    /**
     * Event callback that will be binded to the droppable areas.
     */
    eventsList: {
      /**
       * Droppable events.
       */
      dnd: {
        /**
         * Event callback for dnd:send:options
         *
         * @param event
         * @param options
         * @param {DnDFormData} dndFormData
         */
        'dnd:send:options': function (event, options, dndFormData) {
          var me = this;

          // Do not call the callback for every droppable area, call it just once.
          if (me.isProcessed(event.type)) {
            return;
          }
          me.setProcessed(event.type);

          // Filter out existing files from DnDFormData.
          var exFiles = [];
          dndFormData.filter(function (v) {
            if ($.isPlainObject(v)) {
              if (v.data.fid) {
                exFiles.push(v.data);
                return null;
              }
            }
            else {
              if (v.fid) {
                exFiles.push(v);
                return null;
              }
            }
            return v;
          });

          // Add existing files fids directly to the DnDFormData.
          var mediaSettings = me.mediaSettings;
          var filesNumber = me.dnd.getFilesList().length;
          var delta = filesNumber - exFiles.length + mediaSettings.delta;
          var getInputName = function (delta, name) {
            return mediaSettings.nameTemplate + '[' + delta + '][' + name + ']';
          };

          $.each(exFiles, function (i, file) {
            dndFormData.append(getInputName(delta, 'fid'), file.fid);
            dndFormData.append(getInputName(delta, '_weight'), delta);
            dndFormData.append(getInputName(delta, 'display'), mediaSettings.display);
            delta++;
          });
        },

        /**
         * Detach events before the droppable area will be destroyed.
         *
         * @param event
         * @param $droppable
         */
        'dnd:destroy:before': function (event, $droppable) {
          this.detachEvents($droppable);
          $droppable.removeClass('dnd-upload-media-processed');
        },

        'dnd:createPreview': function (dndFile) {
          if (!this.dnduFileInstance) {
            // This handler is for DnDUploadFile instances only.
            return;
          }

          var fileSize = dndFile.file.fakesize;
          var sizes = [Drupal.t('@size B'), Drupal.t('@size KB'), Drupal.t('@size MB'), Drupal.t('@size GB')];
          $.each(sizes, function (i, size) {
            if (fileSize > 1024) {
              fileSize /= 1024;
            }
            else {
              fileSize = sizes[i].replace('@size', parseInt(fileSize.toPrecision(2)));
              return false;
            }
            return true;
          });

          // Set fake size.
          $('.preview-filesize', dndFile.$preview).html(fileSize);
        }
      },

      /**
       * Event callback for the Browse button.
       */
      browseButtonClick: function (event) {
        event.preventDefault();

        var me = this;
        me.dnd.$activeDroppable = me.$droppable;

        var options = {
          disabledPlugins: [],
          dragndropUpload: true
        };
        if (me.dnd.settings.multiupload) {
          options.disabledPlugins.push('upload');
          options.multiselect = true;
        }
        else {
          options.disabledPlugins.push('mfw_multiupload');
        }
        Drupal.media.popups.mediaBrowser(function (mediaFiles) {
          // When the media browser succeeds
          $.each(mediaFiles, function (i, mediaFile) {
            // Load images
            if (me.dnduImageInstance) {
              // Load image to get its Blob and add as a File.
              $.ajax({
                url: mediaFile.url,
                type: 'GET',
                beforeSend: function (jqXHR) {
                  jqXHR.responseType = 'arraybuffer';
                },
                complete: function (jqXHR) {
                  var arrayBufferView = new Uint8Array(jqXHR.response);
                  var file = new Blob([arrayBufferView], {
                    type: mediaFile.filemime
                  });
                  // Blob does not allow to set name manually, so store name
                  // as a property here.
                  file.name = mediaFile.filename;
                  // Save fid in the Blob object to be able to have access
                  // to it in send:options handlers.
                  file.fid = mediaFile.fid;
                  // Add file.
                  me.dnd.addFiles(me.dnd.$activeDroppable, [file]);
                }
              });
            }
            else {
              // No need to load file blob, so make a fake blob.
              var file = new Blob([], {
                type: mediaFile.filemime
              });
              // Blob does not allow to set name manually, so store name
              // as a property here.
              file.name = mediaFile.filename;
              // Save fid in the Blob object to be able to have access
              // to it in send:options handlers.
              file.fid = mediaFile.fid;
              // Blob does not allow to set size manually, so it is 0
              // for fake blob, but we need to pass it to createPreview
              // handlers, sot store it here.
              file.fakesize = parseInt(mediaFile.filesize);
              // Add file.
              me.dnd.addFiles(me.dnd.$activeDroppable, [file]);
            }
          });
          return false;
        }, options);

        return false;
      }
    }
  });

})(jQuery);
