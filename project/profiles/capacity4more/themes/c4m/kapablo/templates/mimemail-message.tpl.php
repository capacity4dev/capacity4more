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
 *
 * NEVER ALTER THIS FILE DIRECTLY. ALWAYS USE THE METHOD DESCRIBED IN
 * https://wiki.amplexor.com/confluence/display/C4DNG/Foundation+email+template
 */
?>

<!-- Inliner Build Version 4380b7741bb759d6cb997545f3add21ad48f010b -->
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xmlns="http://www.w3.org/1999/xhtml" style="min-height: 100%; background: #ececec;">
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <meta name="viewport" content="width=device-width" />
  <?php if ($css): ?>
    <style type="text/css">
      <!--
      <?php print $css ?>
      -->
    </style>
  <?php endif; ?>
</head>
<body style="width: 100% !important; min-width: 100%; -webkit-text-size-adjust: 100%; -ms-text-size-adjust: 100%; -moz-box-sizing: border-box; -webkit-box-sizing: border-box; box-sizing: border-box; color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-weight: normal; text-align: left; line-height: 19px; font-size: 16px; background: #ececec; margin: 0; padding: 0;" bgcolor="#ececec">
<!-- <style> -->
<table class="body" data-made-with-foundation="" style="border-spacing: 0; border-collapse: collapse; vertical-align: top; text-align: left; height: 100%; width: 100%; color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-weight: normal; line-height: 19px; font-size: 16px; background: #ececec; margin: 40px 0 0; padding: 0;" bgcolor="#ececec"><tr style="vertical-align: top; text-align: left; padding: 0;" align="left"><td class="center" align="center" valign="top" style="border-collapse: collapse !important; overflow-wrap: break-word; word-wrap: break-word; -ms-word-break: break-all; word-break: break-word; -ms-hyphens: auto; -moz-hyphens: auto; -webkit-hyphens: auto; hyphens: auto; vertical-align: top; text-align: left; color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-weight: normal; line-height: 19px; font-size: 16px; margin: 0; padding: 0;">
      <center data-parsed="" style="width: 100%; min-width: 580px;">
        <div class="header text-center" align="center">
          <table class="container" style="border-spacing: 0; border-collapse: collapse; vertical-align: top; text-align: inherit; width: 810px; background: #f1f6f9; margin: 0 auto; padding: 16px 0; border: 1px solid #c5c7c8;" bgcolor="#f1f6f9"><tbody><tr style="vertical-align: top; text-align: left; padding: 0;" align="left"><td style="border-collapse: collapse !important; overflow-wrap: break-word; word-wrap: break-word; -ms-word-break: break-all; word-break: break-word; -ms-hyphens: auto; -moz-hyphens: auto; -webkit-hyphens: auto; hyphens: auto; vertical-align: top; text-align: left; color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-weight: normal; line-height: 19px; font-size: 16px; margin: 0; padding: 16px 64px;" align="left" valign="top">
                <table class="row collapse" style="border-spacing: 0; border-collapse: collapse; vertical-align: top; text-align: left; width: 100%; position: relative; display: table; padding: 0;"><tbody><tr style="vertical-align: top; text-align: left; padding: 0;" align="left"><th class="small-12 large-12" style="width: 580px; color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-weight: normal; text-align: left; line-height: 19px; font-size: 16px; margin: 0; padding: 0;" align="left">
                      <table style="border-spacing: 0; border-collapse: collapse; vertical-align: top; text-align: left; padding: 0;"><tr style="vertical-align: top; text-align: left; padding: 0;" align="left"><th style="color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-weight: normal; text-align: left; line-height: 19px; font-size: 16px; margin: 0; padding: 0;" align="left"> <img src="http://s33.postimg.org/vtp7ch06n/logo_2.png" style="outline: none; text-decoration: none; -ms-interpolation-mode: bicubic; width: auto; max-width: 55%; clear: both; display: block;" /></th>
                        </tr></table></th>
                  </tr></tbody></table></td>
            </tr></tbody></table></div>
        <table class="container text-center" style="border-spacing: 0; border-collapse: collapse; vertical-align: top; text-align: center; width: 810px; background: #ffffff; margin: 0 auto; padding: 0;" bgcolor="#ffffff"><tbody><tr style="vertical-align: top; text-align: left; padding: 0;" align="left"><td style="border-collapse: collapse !important; overflow-wrap: break-word; word-wrap: break-word; -ms-word-break: break-all; word-break: break-word; -ms-hyphens: auto; -moz-hyphens: auto; -webkit-hyphens: auto; hyphens: auto; vertical-align: top; text-align: left; color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-weight: normal; line-height: 19px; font-size: 16px; margin: 0; padding: 0;" align="left" valign="top">
              <table class="row" style="border-spacing: 0; border-collapse: collapse; vertical-align: top; text-align: left; width: 100%; position: relative; display: table; padding: 0;"><tbody><tr style="vertical-align: top; text-align: left; padding: 0;" align="left"><th class="small-12 large-12 columns mail-body" style="width: 564px; color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-weight: normal; text-align: left; line-height: 19px; font-size: 16px; border-bottom-style: solid; border-bottom-color: #6E969F; border-bottom-width: 12px; margin: 0 auto; padding: 40px 64px;" align="left">
                    <table style="border-spacing: 0; border-collapse: collapse; vertical-align: top; text-align: left; width: 100%; padding: 0;"><tr style="vertical-align: top; text-align: left; padding: 0;" align="left"><th style="color: #0a0a0a; font-family: 'GillSans-Light', Verdana, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-weight: normal; text-align: left; line-height: 19px; font-size: 16px; margin: 0; padding: 0;" align="left"> <br />
                          <?php print $body; ?>
                        </th>
                      </tr></table></th>
                </tr></tbody></table></td>
          </tr></tbody></table></center>
    </td>
  </tr></table></body>
</html>
