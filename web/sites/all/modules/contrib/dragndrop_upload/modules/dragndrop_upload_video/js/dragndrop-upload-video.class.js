/**
 * @file
 * Contains DnDUploadVideo class.
 */

/**
 * DnDUploadVideo class.
 *
 * Attaches event callbacks to make widget 'dragndrop_upload_video'
 * work properly.
 *
 * @param {jQuery} $droppable
 */
var DnDUploadVideo = function ($droppable) {
  this.dnd = $droppable.DnD();
  if (!this.dnd) {
    throw new Error('The $droppable does not contain an instance of DnD!');
  }

  this.$droppable = $droppable;
  this.dnd.$droppables.data('DnDUploadVideo', this);

  this.attachEvents(this.dnd.$droppables);
};

(function ($) {
  DnDUploadVideo.prototype = $.extend(true, {}, DnDUploadFile.prototype, {
    /**
     * Attach events to the given droppable areas.
     *
     * @param {jQuery} $droppables
     */
    attachEvents: function ($droppables) {
      var me = this;

      me.parent().attachEvents.call(me, $droppables);
    },
    
    /**
     * Event callback that will be binded to the droppable areas.
     */
    eventsList: {
      /**
       * Droppable events.
       * 
       * Nothing here yet..
       */
      dnd: {
      }
    }
  });
})(jQuery);
