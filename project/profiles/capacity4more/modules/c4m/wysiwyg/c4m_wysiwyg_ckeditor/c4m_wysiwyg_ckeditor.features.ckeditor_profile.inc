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
        'ss' => 2,
        'toolbar' => '[
    [\'Source\'],
    [\'Cut\',\'Copy\',\'Paste\',\'PasteText\',\'PasteFromWord\'],
    [\'Undo\',\'Redo\',\'Find\',\'Replace\',\'-\',\'SelectAll\'],
    [\'Image\',\'Media\',\'oembed\',\'Table\',\'HorizontalRule\',\'Smiley\',\'SpecialChar\'],
    [\'Iframe\',\'Maximize\',\'ShowBlocks\'],
    \'/\',
    [\'Format\'],
    [\'Bold\',\'Italic\',\'Underline\',\'Strike\',\'-\',\'Subscript\',\'Superscript\',\'-\',\'RemoveFormat\'],
    [\'NumberedList\',\'BulletedList\',\'-\',\'Outdent\',\'Indent\',\'Blockquote\'],
    [\'JustifyLeft\',\'JustifyCenter\',\'JustifyRight\',\'JustifyBlock\',\'-\',\'BidiLtr\',\'BidiRtl\'],
    [\'Link\',\'Unlink\',\'Anchor\']
]',
        'expand' => 't',
        'default' => 't',
        'show_toggle' => 'f',
        'uicolor' => 'default',
        'uicolor_user' => 'default',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'allowed_content' => 't',
        'extraAllowedContent' => '',
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
          'mediaembed' => array(
            'name' => 'mediaembed',
            'desc' => 'Plugin for inserting Drupal embeded media',
            'path' => '%plugin_dir%mediaembed/',
            'buttons' => array(
              'MediaEmbed' => array(
                'label' => 'MediaEmbed',
                'icon' => 'images/icon.png',
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
    'Default' => array(
      'name' => 'Default',
      'settings' => array(
        'ss' => 2,
        'toolbar' => '[
    [\'Format\',\'Bold\',\'Italic\',\'Strike\',\'-\',\'BulletedList\',\'NumberedList\',\'Outdent\',\'Indent\'],
    [\'Link\',\'Unlink\',\'Anchor\',\'-\',\'BidiLtr\',\'BidiRtl\',\'-\'],
    [\'SpecialChar\',\'DrupalBreak\',\'-\',\'Table\',\'Image\',\'Media\',\'oembed\'],
    [\'Maximize\']
]',
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
        'extraAllowedContent' => '',
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
        'filtered_html' => 'Filtered HTML',
      ),
    ),
  );
  return $data;
}
