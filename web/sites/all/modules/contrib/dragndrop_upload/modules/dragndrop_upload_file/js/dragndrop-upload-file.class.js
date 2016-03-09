/**
 * @file
 * Contains DnDUploadFile class.
 */

/**
 * DnDUploadFile class.
 *
 * Attaches events callback to make widget 'dragndrop_upload_file'
 * work properly.
 *
 * @param {jQuery} $droppable
 */
var DnDUploadFile = function ($droppable) {
  this.dnd = $droppable.DnD();
  if (!this.dnd) {
    throw new Error('The $droppable does not contain an instance of DnD!');
  }

  this.$droppable = $droppable;
  this.dnd.$droppables.data('DnDUploadFile', this);

  this.attachEvents(this.dnd.$droppables);
};

(function ($) {
  DnDUploadFile.prototype = $.extend(true, {}, DnDUploadAbstract.prototype, {
    /**
     * Event callback that will be binded to the droppable areas.
     */
    eventsList: {
      /**
       * Droppable events.
       */
      dnd: {
        /**
         * Detach events before the droppable area will be destroyed.
         *
         * @param event
         * @param $droppable
         */
        'dnd:destroy:before': function (event, $droppable) {
          $droppable.removeClass('dnd-upload-file-processed');
        }
      }
    }
  });
})(jQuery);
