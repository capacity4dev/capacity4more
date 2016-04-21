<?php
/**
 * @file
 * c4m_wysiwyg_ckeditor.features.ckeditor_profile.inc
 */

/**
 * Implements hook_ckeditor_profile_defaults().
 */
function c4m_wysiwyg_ckeditor_ckeditor_profile_defaults() {
  $data = array(
    'Advanced' => array(
      'name' => 'Advanced',
      'settings' => array(
        'filebrowser' => 'none',
        'quickupload' => 'f',
        'ss' => 2,
        'default' => 't',
        'show_toggle' => 't',
        'popup' => 'f',
        'toolbar' => '
[
    [\'Source\'],
    [\'Cut\',\'Copy\',\'Paste\',\'PasteText\',\'PasteFromWord\',\'-\',\'SpellChecker\', \'Scayt\'],
    [\'Undo\',\'Redo\',\'Find\',\'Replace\',\'-\',\'SelectAll\'],
    [\'Image\',\'Media\',\'Flash\',\'Table\',\'HorizontalRule\',\'Smiley\',\'SpecialChar\'],
    [\'Maximize\', \'ShowBlocks\'],
    \'/\',
    [\'Format\'],
    [\'Bold\',\'Italic\',\'Underline\',\'Strike\',\'-\',\'Subscript\',\'Superscript\',\'-\',\'RemoveFormat\'],
    [\'NumberedList\',\'BulletedList\',\'-\',\'Outdent\',\'Indent\',\'Blockquote\'],
    [\'JustifyLeft\',\'JustifyCenter\',\'JustifyRight\',\'JustifyBlock\',\'-\',\'BidiLtr\',\'BidiRtl\'],
    [\'Link\',\'Unlink\',\'Anchor\',\'Linkit\']
]
    ',
        'expand' => 't',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;div;pre;address;h1;h2;h3;h4;h5;h6',
        'format_source' => 't',
        'format_output' => 't',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
          ),
        ),
        'css_mode' => 'none',
        'css_path' => '',
        'user_choose' => 'f',
        'ckeditor_load_method' => 'ckeditor.js',
        'ckeditor_load_time_out' => 0,
        'scayt_autoStartup' => 'f',
        'html_entities' => 'f',
      ),
      'input_formats' => array(),
    ),
    'CKEditor Global Profile' => array(
      'name' => 'CKEditor Global Profile',
      'settings' => array(
        'ckeditor_path' => '%l/ckeditor',
      ),
      'input_formats' => array(),
    ),
    'Full' => array(
      'name' => 'Full',
      'settings' => array(
        'filebrowser' => 'none',
        'quickupload' => 'f',
        'ss' => 2,
        'default' => 't',
        'show_toggle' => 't',
        'popup' => 'f',
        'toolbar' => '
[
    [\'Source\'],
    [\'Cut\',\'Copy\',\'Paste\',\'PasteText\',\'PasteFromWord\',\'-\',\'SpellChecker\', \'Scayt\'],
    [\'Undo\',\'Redo\',\'Find\',\'Replace\',\'-\',\'SelectAll\'],
    [\'Image\',\'Media\',\'Flash\',\'Table\',\'HorizontalRule\',\'Smiley\',\'SpecialChar\',\'Iframe\'],
    \'/\',
    [\'Bold\',\'Italic\',\'Underline\',\'Strike\',\'-\',\'Subscript\',\'Superscript\',\'-\',\'RemoveFormat\'],
    [\'NumberedList\',\'BulletedList\',\'-\',\'Outdent\',\'Indent\',\'Blockquote\',\'CreateDiv\'],
    [\'JustifyLeft\',\'JustifyCenter\',\'JustifyRight\',\'JustifyBlock\',\'-\',\'BidiLtr\',\'BidiRtl\',\'-\',\'Language\'],
    [\'Link\',\'Unlink\',\'Anchor\',\'Linkit\'],
    [\'DrupalBreak\'],
    \'/\',
    [\'Format\',\'Font\',\'FontSize\'],
    [\'TextColor\',\'BGColor\'],
    [\'Maximize\', \'ShowBlocks\']
]
    ',
        'expand' => 't',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;div;pre;address;h1;h2;h3;h4;h5;h6',
        'format_source' => 't',
        'format_output' => 't',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
          ),
        ),
        'css_mode' => 'none',
        'css_path' => '',
        'user_choose' => 'f',
        'ckeditor_load_method' => 'ckeditor.js',
        'ckeditor_load_time_out' => 0,
        'scayt_autoStartup' => 'f',
        'html_entities' => 'f',
      ),
      'input_formats' => array(),
    ),
    'c4m_advanced' => array(
      'name' => 'c4m_advanced',
      'settings' => array(
        'ss' => 2,
        'toolbar' => '    [
      [\'Bold\',\'Italic\',\'Strike\',\'-\',\'BulletedList\',\'NumberedList\',\'-\',\'Outdent\',\'Indent\'],
      [\'Link\',\'Unlink\',\'Anchor\',\'Linkit\',\'-\',\'BidiLtr\',\'BidiRtl\',\'-\',\'Superscript\',\'Subscript\'],
      [\'CreateDiv\',\'SpecialChar\',\'Format\',\'DrupalBreak\',\'-\',\'Table\',\'Image\',\'Media\',\'oembed\'],
      [\'Source\',\'-\',\'Maximize\']
    ]
  ',
        'expand' => 't',
        'default' => 't',
        'show_toggle' => 't',
        'uicolor' => 'default',
        'uicolor_user' => 'default',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'allowed_content' => 't',
        'extraAllowedContent' => '*[class,id]',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;div;pre;address;h1;h2;h3;h4;h5;h6',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
            'breakBeforeClose' => 0,
            'pre_indent' => 0,
          ),
        ),
        'css_mode' => 'none',
        'css_path' => '',
        'css_style' => 'theme',
        'styles_path' => '',
        'filebrowser' => 'none',
        'filebrowser_image' => '',
        'filebrowser_flash' => '',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'forcePasteAsPlainText' => 'f',
        'html_entities' => 'f',
        'scayt_autoStartup' => 'f',
        'theme_config_js' => 'f',
        'js_conf' => '',
        'loadPlugins' => array(
          'drupalbreaks' => array(
            'name' => 'drupalbreaks',
            'desc' => 'Plugin for inserting Drupal teaser and page breaks.',
            'path' => '%plugin_dir%drupalbreaks/',
            'buttons' => array(
              'DrupalBreak' => array(
                'label' => 'DrupalBreak',
                'icon' => 'images/drupalbreak.png',
              ),
            ),
            'default' => 't',
          ),
          'lineutils' => array(
            'name' => 'lineutils',
            'desc' => 'CKEditor: Line utils plugin',
            'path' => '%base_path%profiles/capacity4more/modules/c4m/wysiwyg/c4m_wysiwyg_ckeditor/ckeditor-plugins/lineutils/',
            'default' => 't',
            'buttons' => FALSE,
          ),
          'media' => array(
            'name' => 'media',
            'desc' => 'Plugin for inserting images from Drupal media module',
            'path' => '%plugin_dir%media/',
            'buttons' => array(
              'Media' => array(
                'label' => 'Media',
                'icon' => 'images/icon.gif',
              ),
            ),
            'default' => 'f',
          ),
          'oembed' => array(
            'name' => 'oembed',
            'desc' => 'CKEditor: Oembed plugin',
            'path' => '%base_path%profiles/capacity4more/modules/c4m/wysiwyg/c4m_wysiwyg_ckeditor/ckeditor-plugins/oembed/',
            'default' => 't',
            'buttons' => array(
              'oembed' => array(
                'label' => 'Oembed',
                'icon' => 'icons/oembed.png',
              ),
            ),
          ),
          'tableresize' => array(
            'name' => 'tableresize',
            'desc' => 'CKEditor: Tableresize plugin',
            'path' => '%base_path%profiles/capacity4more/modules/c4m/wysiwyg/c4m_wysiwyg_ckeditor/ckeditor-plugins/tableresize/',
            'default' => 't',
            'buttons' => FALSE,
          ),
          'widget' => array(
            'name' => 'widget',
            'desc' => 'CKEditor: Widget plugin',
            'path' => '%base_path%profiles/capacity4more/modules/c4m/wysiwyg/c4m_wysiwyg_ckeditor/ckeditor-plugins/widget/',
            'default' => 't',
            'buttons' => FALSE,
          ),
        ),
      ),
      'input_formats' => array(
        'full_html' => 'Full HTML',
      ),
    ),
    'c4m_default' => array(
      'name' => 'c4m_default',
      'settings' => array(
        'filebrowser' => 'none',
        'quickupload' => 'f',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'ss' => 2,
        'filters' => array(
          'filter_html' => 1,
        ),
        'default' => 't',
        'show_toggle' => 't',
        'popup' => 'f',
        'toolbar' => '
    [
      [\'Bold\',\'Italic\',\'Strike\',\'-\',\'BulletedList\',\'NumberedList\',\'-\',\'Outdent\',\'Indent\'],
      [\'Link\',\'Unlink\',\'Anchor\',\'Linkit\',\'-\',\'BidiLtr\',\'BidiRtl\',\'-\',\'Superscript\',\'Subscript\'],
      [\'CreateDiv\',\'SpecialChar\',\'Format\',\'DrupalBreak\',\'-\',\'Table\',\'Image\',\'Media\',\'oembed\'],
      [\'Maximize\']
    ]
  ',
        'loadPlugins' => array(
          'media' => array(
            'name' => 'media',
            'path' => '%plugin_dir%media/',
          ),
          'drupalbreaks' => array(
            'name' => 'drupalbreaks',
            'path' => '%plugin_dir%drupalbreaks/',
          ),
          'lineutils' => array(
            'name' => 'lineutils',
            'path' => '%base_path%profiles/capacity4more/modules/c4m/wysiwyg/c4m_wysiwyg_ckeditor/ckeditor-plugins/lineutils/',
          ),
          'oembed' => array(
            'name' => 'oembed',
            'path' => '%base_path%profiles/capacity4more/modules/c4m/wysiwyg/c4m_wysiwyg_ckeditor/ckeditor-plugins/oembed/',
          ),
          'tableresize' => array(
            'name' => 'tableresize',
            'path' => '%base_path%profiles/capacity4more/modules/c4m/wysiwyg/c4m_wysiwyg_ckeditor/ckeditor-plugins/tableresize/',
          ),
          'widget' => array(
            'name' => 'widget',
            'path' => '%base_path%profiles/capacity4more/modules/c4m/wysiwyg/c4m_wysiwyg_ckeditor/ckeditor-plugins/widget/',
          ),
        ),
        'expand' => 't',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;div;pre;address;h1;h2;h3;h4;h5;h6',
        'format_source' => 't',
        'format_output' => 't',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
          ),
        ),
        'css_mode' => 'none',
        'css_path' => '',
        'user_choose' => 'f',
        'ckeditor_load_method' => 'ckeditor.js',
        'ckeditor_load_time_out' => 0,
        'scayt_autoStartup' => 'f',
        'html_entities' => 'f',
      ),
      'input_formats' => array(
        'default_html' => 'Default HTML',
      ),
    ),
    'c4m_simple' => array(
      'name' => 'c4m_simple',
      'settings' => array(
        'filebrowser' => 'none',
        'quickupload' => 'f',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'ss' => 2,
        'filters' => array(
          'filter_html' => 1,
        ),
        'default' => 't',
        'show_toggle' => 't',
        'popup' => 'f',
        'toolbar' => '
    [
      [\'Bold\',\'Italic\',\'Strike\',\'-\',\'BulletedList\',\'NumberedList\',\'-\',\'Outdent\',\'Indent\'],
      [\'Link\',\'Unlink\',\'Format\'],
    ]
  ',
        'loadPlugins' => array(),
        'expand' => 't',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;div;pre;address;h1;h2;h3;h4;h5;h6',
        'format_source' => 't',
        'format_output' => 't',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
          ),
        ),
        'css_mode' => 'none',
        'css_path' => '',
        'user_choose' => 'f',
        'ckeditor_load_method' => 'ckeditor.js',
        'ckeditor_load_time_out' => 0,
        'scayt_autoStartup' => 'f',
        'html_entities' => 'f',
      ),
      'input_formats' => array(
        'filtered_html' => 'Filtered HTML',
      ),
    ),
  );
  return $data;
}
