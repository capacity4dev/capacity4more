
/**
 * @file
 * getlocations_categories.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations categories support
*/
(function ($) {
  Drupal.behaviors.getlocations_categories = {
    attach: function() {

      function categoriesGetClicks(k, c, l) {
        var tgt = "#getlocations_toggle_" + c + '_' + k;
        if ($(tgt).is('input')) {
          $(tgt).click( function() {
            $.each(Drupal.getlocations_markers[k].lids, function (lid, mark) {
              if (Drupal.getlocations_markers[k].cat[lid] == c) {
                vis = mark.getVisible();
                if (vis) {
                  label = l + ' ' + Drupal.t('On');
                  sv = false;
                  if (Drupal.getlocations_settings[k].useclustermanager) {
                    Drupal.getlocations_settings[k].cmgr.removeMarker(mark);
                  }
                }
                else {
                  label = l + ' ' + Drupal.t('Off');
                  sv = true;
                  if (Drupal.getlocations_settings[k].useclustermanager) {
                    Drupal.getlocations_settings[k].cmgr.addMarker(mark);
                  }
                }
                mark.setVisible(sv);
                $(tgt).val(label);
              }
            });
          });
        }
      }

      $.each(Drupal.settings.getlocations, function (key, settings) {
        // categories
        var cats = (settings.categories ? settings.categories : []);
        if (cats) {
          $.each(cats, function (cat, label) {
            categoriesGetClicks(key, cat, label);
          });
        }
      });

    }
  };
}(jQuery));
