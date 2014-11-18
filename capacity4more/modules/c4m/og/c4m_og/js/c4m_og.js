Drupal.behaviors.c4m_og = {};
Drupal.c4m_og = {};

/**
 * In the add view wizard, use the view name to prepopulate form fields such as
 * page title and menu link.
 */
Drupal.behaviors.c4m_og.attach = function (context, settings) {
  var $ = jQuery;
  var exclude, replace, suffix;
  // Set up regular expressions to allow only numbers, letters, and dashes.
  exclude = new RegExp('[^a-z0-9\\-]+', 'g');
  replace = '-';

  // Prepopulate the purl field with a URLified version of the group name.
  var $pathField = $(context).find('[id^="edit-purl-value"]');
  if ($pathField.length) {
    if (!this.pathFiller) {
      this.pathFiller = new Drupal.c4m_og.FormFieldFiller($pathField, exclude, replace);
    }
    else {
      this.pathFiller.rebind($pathField);
    }
  }
};

/**
 * Constructor for the Drupal.c4m_og.FormFieldFiller object.
 *
 * Prepopulates a form field based on the view name.
 *
 * @param $target
 *   A jQuery object representing the form field to prepopulate.
 * @param exclude
 *   Optional. A regular expression representing characters to exclude from the
 *   target field.
 * @param replace
 *   Optional. A string to use as the replacement value for disallowed
 *   characters.
 * @param suffix
 *   Optional. A suffix to append at the end of the target field content.
 */
Drupal.c4m_og.FormFieldFiller = function ($target, exclude, replace, suffix) {
  var $ = jQuery;
  this.source = $('#edit-title');
  this.target = $target;
  this.exclude = exclude || false;
  this.replace = replace || '';
  this.suffix = suffix || '';

  // Create bound versions of this instance's object methods to use as event
  // handlers. This will let us easily unbind those specific handlers later on.
  // NOTE: jQuery.proxy will not work for this because it assumes we want only
  // one bound version of an object method, whereas we need one version per
  // object instance.
  var self = this;
  this.populate = function () {return self._populate.call(self);};
  this.unbind = function () {return self._unbind.call(self);};

  this.bind();
  // Object constructor; no return value.
};

/**
 * Bind the form-filling behavior.
 */
Drupal.c4m_og.FormFieldFiller.prototype.bind = function () {
  this.unbind();
  // Populate the form field when the source changes.
  this.source.bind('keyup change', this.populate);
  // Quit populating the field as soon as it gets focus.
  this.target.bind('focus', this.unbind);
};

/**
 * Populate the target form field with the altered source field value.
 */
Drupal.c4m_og.FormFieldFiller.prototype._populate = function () {
  var transliterated = this.getTransliterated();
  this.target.val(transliterated);
};

/**
 * Stop prepopulating the form fields.
 */
Drupal.c4m_og.FormFieldFiller.prototype._unbind = function () {
  this.source.unbind('keyup change', this.populate);
  this.target.unbind('focus', this.unbind);
};

/**
 * Bind event handlers to the new form fields, after they're replaced via AJAX.
 */
Drupal.c4m_og.FormFieldFiller.prototype.rebind = function ($fields) {
  this.target = $fields;
  this.bind();
}

/**
 * Get the source form field value as altered by the passed-in parameters.
 */
Drupal.c4m_og.FormFieldFiller.prototype.getTransliterated = function () {
  var from = this.source.val();
  if (this.exclude) {
    from = from.toLowerCase().replace(this.exclude, this.replace);
  }
  return from + this.suffix;
};
