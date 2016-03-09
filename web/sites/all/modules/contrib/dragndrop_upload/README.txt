
-- SUMMARY --
This module provides a Drag & Drop Upload element and widgets for a File
and an Image fields.


-- FEATURES --
* Drag & Drop upload widget for a File and an Image fields.
* Drag & Drop multi-upload support.
* Upload progress bar support.
* Browse button can be enabled if needed.
* Provides drag & drop upload element (dragndrop_upload).
* Flexible JS part of the module, that allows developers to define custom
validators and previewers for a dropzone.
* Makes it possible to turn any element into a dropzone(see Examples submodule).


-- INSTALLATION --
* Install this module.
* Submodules that provide widgets for a File or an Image fields will be enabled
automatically. Multi-upload support will be enabled if Multiupload Filefield
Widget module exists.
* Create a File or an Image field and choose the widget 'Drag & Drop Upload'
for it.
* If needed you can configure the widget in the field edit form, see the
screenshot for help.


-- FOR DEVELOPERS --
* There is a "Drag & Drop Upload: examples" (dragndrop_upload_example) that
contains examples of how to use dropzones and dragndrop_upload element.
* Submodules that provide widgets for a File and an Image fields are the best
examples of how to add new or change the functionality.
* DnD js class (dragndrop-upload.dnd.js) is a class that contains core
functionality for Drag & Drop uploads. See the comments for the DnD class to get
info about events that are triggered by DnD class. Using custom events is a
great way to change the functionality.
* You can even override default DnD, DnDUploadAbstract, DnDUpload,
DnDUploadFile, DnDUploadImage classes to change the functionality.

-- CONTACT --

Current maintainers:
* WebEvt - http://drupal.org/user/856734
