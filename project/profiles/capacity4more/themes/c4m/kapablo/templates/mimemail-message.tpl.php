<?php
/**
 * @file
 * Format the HTML mail.
 *
 * Copy this file in your default theme folder to create a custom themed mail.
 * Rename it to mimemail-message--[module]--[key].tpl.php to override it for a
 * specific mail.
 *
 * Available variables:
 * - $recipient: The recipient of the message
 * - $subject: The message subject
 * - $body: The message body
 * - $css: Internal style sheets
 * - $module: The sending module
 * - $key: The message identifier
 *
 * @see template_preprocess_mimemail_message()
 */
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
  <meta name="viewport" content="width=device-width">

</head>

<body style="-moz-box-sizing: border-box; -ms-text-size-adjust: 100%; -webkit-box-sizing: border-box; -webkit-text-size-adjust: 100%; Margin: 0; background: #ececec; box-sizing: border-box; color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 19px; margin: 0; min-width: 100%; padding: 0; text-align: left; width: 100% !important;">
<style>
  @media only screen and (max-width: 596px) {
    .small-float-center {
      margin: 0 auto !important;
      float: none !important;
      text-align: center !important;
    }
    .small-text-center {
      text-align: center !important;
    }
    .small-text-left {
      text-align: left !important;
    }
    .small-text-right {
      text-align: right !important;
    }
  }

  @media only screen and (max-width: 596px) {
    table.body table.container .hide-for-large {
      display: block !important;
      width: auto !important;
      overflow: visible !important;
    }
  }

  @media only screen and (max-width: 596px) {
    table.body table.container .row.hide-for-large,
    table.body table.container .row.hide-for-large {
      display: table !important;
      width: 100% !important;
    }
  }

  @media only screen and (max-width: 596px) {
    table.body table.container .show-for-large {
      display: none !important;
      width: 0;
      mso-hide: all;
      overflow: hidden;
    }
  }

  @media only screen and (max-width: 596px) {
    table.body img {
      width: auto !important;
      height: auto !important;
    }
    table.body center {
      min-width: 0 !important;
    }
    table.body .container {
      width: 95% !important;
    }
    table.body .columns,
    table.body .column {
      height: auto !important;
      -moz-box-sizing: border-box;
      -webkit-box-sizing: border-box;
      box-sizing: border-box;
      padding-left: 16px !important;
      padding-right: 16px !important;
    }
    table.body .columns .column,
    table.body .columns .columns,
    table.body .column .column,
    table.body .column .columns {
      padding-left: 0 !important;
      padding-right: 0 !important;
    }
    table.body .collapse .columns,
    table.body .collapse .column {
      padding-left: 0 !important;
      padding-right: 0 !important;
    }
    td.small-1,
    th.small-1 {
      display: inline-block !important;
      width: 8.33333% !important;
    }
    td.small-2,
    th.small-2 {
      display: inline-block !important;
      width: 16.66667% !important;
    }
    td.small-3,
    th.small-3 {
      display: inline-block !important;
      width: 25% !important;
    }
    td.small-4,
    th.small-4 {
      display: inline-block !important;
      width: 33.33333% !important;
    }
    td.small-5,
    th.small-5 {
      display: inline-block !important;
      width: 41.66667% !important;
    }
    td.small-6,
    th.small-6 {
      display: inline-block !important;
      width: 50% !important;
    }
    td.small-7,
    th.small-7 {
      display: inline-block !important;
      width: 58.33333% !important;
    }
    td.small-8,
    th.small-8 {
      display: inline-block !important;
      width: 66.66667% !important;
    }
    td.small-9,
    th.small-9 {
      display: inline-block !important;
      width: 75% !important;
    }
    td.small-10,
    th.small-10 {
      display: inline-block !important;
      width: 83.33333% !important;
    }
    td.small-11,
    th.small-11 {
      display: inline-block !important;
      width: 91.66667% !important;
    }
    td.small-12,
    th.small-12 {
      display: inline-block !important;
      width: 100% !important;
    }
    .columns td.small-12,
    .column td.small-12,
    .columns th.small-12,
    .column th.small-12 {
      display: block !important;
      width: 100% !important;
    }
    .body .columns td.small-1,
    .body .column td.small-1,
    td.small-1 center,
    .body .columns th.small-1,
    .body .column th.small-1,
    th.small-1 center {
      display: inline-block !important;
      width: 8.33333% !important;
    }
    .body .columns td.small-2,
    .body .column td.small-2,
    td.small-2 center,
    .body .columns th.small-2,
    .body .column th.small-2,
    th.small-2 center {
      display: inline-block !important;
      width: 16.66667% !important;
    }
    .body .columns td.small-3,
    .body .column td.small-3,
    td.small-3 center,
    .body .columns th.small-3,
    .body .column th.small-3,
    th.small-3 center {
      display: inline-block !important;
      width: 25% !important;
    }
    .body .columns td.small-4,
    .body .column td.small-4,
    td.small-4 center,
    .body .columns th.small-4,
    .body .column th.small-4,
    th.small-4 center {
      display: inline-block !important;
      width: 33.33333% !important;
    }
    .body .columns td.small-5,
    .body .column td.small-5,
    td.small-5 center,
    .body .columns th.small-5,
    .body .column th.small-5,
    th.small-5 center {
      display: inline-block !important;
      width: 41.66667% !important;
    }
    .body .columns td.small-6,
    .body .column td.small-6,
    td.small-6 center,
    .body .columns th.small-6,
    .body .column th.small-6,
    th.small-6 center {
      display: inline-block !important;
      width: 50% !important;
    }
    .body .columns td.small-7,
    .body .column td.small-7,
    td.small-7 center,
    .body .columns th.small-7,
    .body .column th.small-7,
    th.small-7 center {
      display: inline-block !important;
      width: 58.33333% !important;
    }
    .body .columns td.small-8,
    .body .column td.small-8,
    td.small-8 center,
    .body .columns th.small-8,
    .body .column th.small-8,
    th.small-8 center {
      display: inline-block !important;
      width: 66.66667% !important;
    }
    .body .columns td.small-9,
    .body .column td.small-9,
    td.small-9 center,
    .body .columns th.small-9,
    .body .column th.small-9,
    th.small-9 center {
      display: inline-block !important;
      width: 75% !important;
    }
    .body .columns td.small-10,
    .body .column td.small-10,
    td.small-10 center,
    .body .columns th.small-10,
    .body .column th.small-10,
    th.small-10 center {
      display: inline-block !important;
      width: 83.33333% !important;
    }
    .body .columns td.small-11,
    .body .column td.small-11,
    td.small-11 center,
    .body .columns th.small-11,
    .body .column th.small-11,
    th.small-11 center {
      display: inline-block !important;
      width: 91.66667% !important;
    }
    table.body td.small-offset-1,
    table.body th.small-offset-1 {
      margin-left: 8.33333% !important;
      Margin-left: 8.33333% !important;
    }
    table.body td.small-offset-2,
    table.body th.small-offset-2 {
      margin-left: 16.66667% !important;
      Margin-left: 16.66667% !important;
    }
    table.body td.small-offset-3,
    table.body th.small-offset-3 {
      margin-left: 25% !important;
      Margin-left: 25% !important;
    }
    table.body td.small-offset-4,
    table.body th.small-offset-4 {
      margin-left: 33.33333% !important;
      Margin-left: 33.33333% !important;
    }
    table.body td.small-offset-5,
    table.body th.small-offset-5 {
      margin-left: 41.66667% !important;
      Margin-left: 41.66667% !important;
    }
    table.body td.small-offset-6,
    table.body th.small-offset-6 {
      margin-left: 50% !important;
      Margin-left: 50% !important;
    }
    table.body td.small-offset-7,
    table.body th.small-offset-7 {
      margin-left: 58.33333% !important;
      Margin-left: 58.33333% !important;
    }
    table.body td.small-offset-8,
    table.body th.small-offset-8 {
      margin-left: 66.66667% !important;
      Margin-left: 66.66667% !important;
    }
    table.body td.small-offset-9,
    table.body th.small-offset-9 {
      margin-left: 75% !important;
      Margin-left: 75% !important;
    }
    table.body td.small-offset-10,
    table.body th.small-offset-10 {
      margin-left: 83.33333% !important;
      Margin-left: 83.33333% !important;
    }
    table.body td.small-offset-11,
    table.body th.small-offset-11 {
      margin-left: 91.66667% !important;
      Margin-left: 91.66667% !important;
    }
    table.body table.columns td.expander,
    table.body table.columns th.expander {
      display: none !important;
    }
    table.body .right-text-pad,
    table.body .text-pad-right {
      padding-left: 10px !important;
    }
    table.body .left-text-pad,
    table.body .text-pad-left {
      padding-right: 10px !important;
    }
    table.menu {
      width: 100% !important;
    }
    table.menu td,
    table.menu th {
      width: auto !important;
      display: inline-block !important;
    }
    table.menu.vertical td,
    table.menu.vertical th,
    table.menu.small-vertical td,
    table.menu.small-vertical th {
      display: block !important;
    }
    table.button.expand {
      width: 100% !important;
    }
  }
</style>
<!-- <style> -->
<table class="body" data-made-with-foundation="" style="Margin: 0; background: #ececec; border-collapse: collapse; border-spacing: 0; color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; height: 100%; line-height: 19px; margin: 0; margin-top: 40px; padding: 0; text-align: left; vertical-align: top; width: 100%;">
  <tbody>
  <tr style="padding: 0; text-align: left; vertical-align: top;">
    <td class="center" align="center" valign="top" style="-moz-hyphens: auto; -webkit-hyphens: auto; Margin: 0; border-collapse: collapse !important; color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; hyphens: auto; line-height: 19px; margin: 0; padding: 0; text-align: left; vertical-align: top; word-wrap: break-word;">
      <center data-parsed="" style="min-width: 580px; width: 100%;">
        <div class="header text-center" align="center">
          <table class="container" style="Margin: 0 auto; background: #f1f6f9; border: 1px solid #C5C7C8; border-collapse: collapse; border-spacing: 0; margin: 0 auto; padding: 0; padding-bottom: 16px; padding-top: 16px; text-align: inherit; vertical-align: top; width: 810px;">
            <tbody>
            <tr style="padding: 0; text-align: left; vertical-align: top;">
              <td style="-moz-hyphens: auto; -webkit-hyphens: auto; Margin: 0; border-collapse: collapse !important; color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; hyphens: auto; line-height: 19px; margin: 0; padding: 0; padding-bottom: 16px; padding-left: 64px; padding-right: 64px; padding-top: 16px; text-align: left; vertical-align: top; word-wrap: break-word;">
                <table class="row collapse" style="border-collapse: collapse; border-spacing: 0; display: table; padding: 0; position: relative; text-align: left; vertical-align: top; width: 100%;">
                  <tbody>
                  <tr style="padding: 0; text-align: left; vertical-align: top;">
                    <th class="small-12 large-12" style="Margin: 0; color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 19px; margin: 0; padding: 0; padding-left: 0; padding-right: 0; text-align: left; width: 580px;">
                      <table style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top;">
                        <tbody>
                        <tr style="padding: 0; text-align: left; vertical-align: top;">
                          <th style="Margin: 0; color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 19px; margin: 0; padding: 0; text-align: left;"> <img src="http://s33.postimg.org/n1fzibsqn/unspecified.png" style="-ms-interpolation-mode: bicubic; clear: both; display: block; max-width: 55%; outline: none; text-decoration: none; width: auto;">                                      </th>
                        </tr>
                        </tbody>
                      </table>
                    </th>
                  </tr>
                  </tbody>
                </table>
              </td>
            </tr>
            </tbody>
          </table>
        </div>
        <table class="container text-center" style="Margin: 0 auto; background: #ffffff; border-collapse: collapse; border-spacing: 0; margin: 0 auto; padding: 0; text-align: center; vertical-align: top; width: 810px;">
          <tbody>
          <tr style="padding: 0; text-align: left; vertical-align: top;">
            <td style="-moz-hyphens: auto; -webkit-hyphens: auto; Margin: 0; border-collapse: collapse !important; color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; hyphens: auto; line-height: 19px; margin: 0; padding: 0; text-align: left; vertical-align: top; word-wrap: break-word;">
              <table class="row" style="border-collapse: collapse; border-spacing: 0; display: table; padding: 0; position: relative; text-align: left; vertical-align: top; width: 100%;">
                <tbody>
                <tr style="padding: 0; text-align: left; vertical-align: top;">
                  <th class="small-12 large-12 columns mail-body" style="Margin: 0 auto; border-bottom: 12px solid #6E969F; color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 19px; margin: 0 auto; padding: 0; padding-bottom: 40px; padding-left: 64px; padding-right: 64px; padding-top: 40px; text-align: left; width: 564px;">
                    <table style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%;">
                      <tbody>
                      <tr style="padding: 0; text-align: left; vertical-align: top;">
                        <th style="Margin: 0; color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 19px; margin: 0; padding: 0; text-align: left;"> <br>
                          <?php print $body ?>
                        </th>
                      </tr>
                      </tbody>
                    </table>
                  </th>
                </tr>
                </tbody>
              </table>
            </td>
          </tr>
          </tbody>
        </table>
      </center>
    </td>
  </tr>
  </tbody>
</table>



</body>

</html>
