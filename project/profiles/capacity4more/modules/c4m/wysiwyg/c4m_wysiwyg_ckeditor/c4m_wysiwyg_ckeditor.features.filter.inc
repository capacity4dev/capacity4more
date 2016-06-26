<?php
/**
 * @file
 * c4m_wysiwyg_ckeditor.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function c4m_wysiwyg_ckeditor_filter_default_formats() {
  $formats = array();

  // Exported format: Default HTML.
  $formats['default_html'] = array(
    'format' => 'default_html',
    'name' => 'Default HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_url' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'c4m_moodle_link_filter' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(),
      ),
      'wysiwyg' => array(
        'weight' => -43,
        'status' => 1,
        'settings' => array(
          'valid_elements' => '@[class|style|title],
a[href|target<_blank|title|rel|name],
em/i, strong/b, strike/s, sub, sup,
img[width|height|alt|title|src],
p[align<center?justify?left?right],
div[align<center?justify?left?right|data-align|data-oembed|data-oembed_provider|data-resizetype],
br,address, hr, blockquote, pre, cite, code, span,
h1,h2,h3,h4,h5,h6,
ul,ol,li,dl,dt,dd,
table[width|cellpadding|cellspacing|border|summary|align<center?left?right],
colgroup,col,
tr[align|valign|rowspan],
td[align|valign|width|colspan],
th[align|valign|width],tbody,thead,tfoot,
iframe[allowfullscreen|allowscriptaccess|frameborder|height|scrolling|src|width]',
          'allow_comments' => 0,
          'nofollow_policy' => 'whitelist',
          'nofollow_domains' => array(),
          'style_color' => array(
            'background-color' => 'background-color',
          ),
          'style_font' => array(),
          'style_text' => array(
            'text-align' => 'text-align',
            'text-decoration' => 'text-decoration',
            'text-indent' => 'text-indent',
            'text-transform' => 'text-transform',
          ),
          'style_box' => array(
            'margin' => 'margin',
            'padding' => 'padding',
          ),
          'style_border-1' => array(
            'border' => 'border',
          ),
          'style_border-2' => array(
            'border-color' => 'border-color',
            'border-style' => 'border-style',
          ),
          'style_dimension' => array(
            'height' => 'height',
            'width' => 'width',
          ),
          'style_positioning' => array(),
          'style_layout' => array(),
          'style_list' => array(),
          'style_table' => array(
            'border-collapse' => 'border-collapse',
            'border-spacing' => 'border-spacing',
          ),
          'style_user' => array(),
          'rule_valid_classes' => array(
            0 => 'align-right',
            1 => 'align-left',
            2 => 'embeddedContent',
            3 => 'oembed-provider-*',
            4 => 'oembed-provider-youtube',
          ),
          'rule_valid_ids' => array(),
          'rule_style_urls' => array(),
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_url' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'c4m_moodle_link_filter' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(),
      ),
      'wysiwyg' => array(
        'weight' => -43,
        'status' => 1,
        'settings' => array(
          'valid_elements' => '@[class|style|title],
a[href|target<_blank|title|rel|name],
em/i, strong/b, strike/s, sub, sup,
img[width|height|alt|title|src],
p[align<center?justify?left?right],
div[align<center?justify?left?right|data-align|data-oembed|data-oembed_provider|data-resizetype],
br,address, hr, blockquote, pre, cite, code, span,
h1,h2,h3,h4,h5,h6,
ul,ol,li,dl,dt,dd,
table[width|cellpadding|cellspacing|border|summary|align<center?left?right],
colgroup,col,
tr[align|valign|rowspan],
td[align|valign|width|colspan],
th[align|valign|width],tbody,thead,tfoot,
iframe[allowfullscreen|allowscriptaccess|frameborder|height|scrolling|src|width]',
          'allow_comments' => 0,
          'nofollow_policy' => 'whitelist',
          'nofollow_domains' => array(),
          'style_color' => array(
            'background-color' => 'background-color',
          ),
          'style_font' => array(),
          'style_text' => array(
            'text-align' => 'text-align',
            'text-decoration' => 'text-decoration',
            'text-indent' => 'text-indent',
            'text-transform' => 'text-transform',
          ),
          'style_box' => array(
            'margin' => 'margin',
            'padding' => 'padding',
          ),
          'style_border-1' => array(
            'border' => 'border',
          ),
          'style_border-2' => array(
            'border-color' => 'border-color',
            'border-style' => 'border-style',
          ),
          'style_dimension' => array(
            'height' => 'height',
            'width' => 'width',
          ),
          'style_positioning' => array(),
          'style_layout' => array(),
          'style_list' => array(),
          'style_table' => array(
            'border-collapse' => 'border-collapse',
            'border-spacing' => 'border-spacing',
          ),
          'style_user' => array(),
          'rule_valid_classes' => array(
            0 => 'align-right',
            1 => 'align-left',
            2 => 'embeddedContent',
            3 => 'oembed-provider-*',
            4 => 'oembed-provider-youtube',
          ),
          'rule_valid_ids' => array(),
          'rule_style_urls' => array(),
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 1,
    'filters' => array(
      'filter_url' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'c4m_moodle_link_filter' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_autop' => array(
        'weight' => -42,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => 10,
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
