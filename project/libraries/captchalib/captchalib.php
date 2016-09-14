<?php

/* *
  CAPTCHA based on reCAPTCHA
  AUTHORS:
  DIGIT FPFIS SUPPORT
  /* */

/* *
  Copyright (c) 2007 reCAPTCHA -- http://recaptcha.net
  AUTHORS:
  Mike Crawford
  Ben Maurer

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
  /* */

/**
 * The captcha server URL's
 */
if (!defined('CAPTCHA_VERIFY_SERVER'))
  define('CAPTCHA_VERIFY_SERVER', 'webtools.ec.europa.eu');
if (!defined('CAPTCHA_VERIFY_SERVER_PATH'))
  define('CAPTCHA_VERIFY_SERVER_PATH', '/captcha');
if (!defined('CAPTCHA_API_SERVER'))
  define('CAPTCHA_API_SERVER', 'https://' . CAPTCHA_VERIFY_SERVER . CAPTCHA_VERIFY_SERVER_PATH);
if (!defined('CAPTCHA_API_SECURE_SERVER'))
  define('CAPTCHA_API_SECURE_SERVER', 'https://' . CAPTCHA_VERIFY_SERVER . CAPTCHA_VERIFY_SERVER_PATH);
if (!defined('CAPTCHA_ADDITIONAL_HEADER'))
  define('CAPTCHA_ADDITIONAL_HEADER', '');

/**
 * Encodes the given data into a query string format
 * @param $data - array of string elements to be encoded
 * @return string - encoded request
 */
function _captcha_qsencode($data) {
  $req = "";
  foreach ($data as $key => $value)
    $req .= $key . '=' . urlencode(stripslashes($value)) . '&';

  // Cut the last '&'
  $req = substr($req, 0, strlen($req) - 1);
  return $req;
}

/**
 * Submits an HTTP POST to a captcha server
 * @param string $host
 * @param string $path
 * @param array $data
 * @param int port
 * @return array response
 */
function _captcha_http_post($host, $path, $data, $port = 443) {

  $req = _captcha_qsencode($data);
  $http_request = "POST $path HTTP/1.0\r\n";
  $http_request .= "Host: $host\r\n";
  $http_request .= "Content-Type: application/x-www-form-urlencoded;\r\n";
  $http_request .= "Content-Length: " . strlen($req) . "\r\n";
  $http_request .= "User-Agent: FPFIS Captcha/PHP" . CAPTCHA_ADDITIONAL_HEADER . "\r\n";
  $http_request .= "\r\n";
  $http_request .= $req;

  $response = '';
  if (false == ( $fs = @fsockopen('ssl://webtools.ec.europa.eu', 443, $errno, $errstr, 10) )) {
    die('Could not open socket.'.$errno.'-'.$errstr.'-'.$fs);
  }
  fwrite($fs, $http_request);

  while (!feof($fs))
    $response .= fgets($fs, 1160); // One TCP-IP packet
  fclose($fs);

  $response = explode("\r\n\r\n", $response, 2);

  return $response;
}

/**
 * Gets the challenge HTML (javascript version).
 * This is called from the browser, and the resulting captcha HTML widget
 * is embedded within the HTML form it was called from.
 * @param boolean $use_ssl Should the request be made over ssl? (optional, default is false)
 * @return string - The HTML to be embedded in the user's form.
 */
function captcha_get_html($use_ssl = false) {
  if ($use_ssl) {
    $server = CAPTCHA_API_SECURE_SERVER;
    $host = CAPTCHA_VERIFY_SERVER;
  }
  else {
    $server = CAPTCHA_API_SERVER;
    $host = CAPTCHA_VERIFY_SERVER;
  }

  $sessionid = '';

  /* Prepare request to get CAPTCHA on remote server */
  $req = _captcha_qsencode(array());
  $path = CAPTCHA_VERIFY_SERVER_PATH . '/securimage_show.php';
  $port = 80;
  $http_request = "POST $path HTTP/1.0\r\n";
  $http_request .= "Host: $host\r\n";
  $http_request .= "Content-Type: application/x-www-form-urlencoded;\r\n";
  $http_request .= "Content-Length: " . strlen($req) . "\r\n";
  $http_request .= "User-Agent: FPFIS Captcha/PHP" . CAPTCHA_ADDITIONAL_HEADER . "\r\n";
  $http_request .= "\r\n";
  $http_request .= $req;

  $response = '';
  if (false == ( $fs = @fsockopen($host, $port, $errno, $errstr, 10) )) {
    die('Could not open socket. - 2');
  }

  fwrite($fs, $http_request);

  while (!feof($fs))
    $response .= fgets($fs, 1160); // One TCP-IP packet
  fclose($fs);

  $response = explode("\r\n\r\n", $response, 2);

  if (!empty($response[0])) {
    $pattern = '/CAPTCHAID=([^;]+);/i';
    $matches = array();
    if (preg_match($pattern, $response[0], $matches)) {
      if (!empty($matches[1])) {
        $sessionid = '&amp;CAPTCHAID=' . $matches[1];
      }
    }
  }

  $strCaptcha = ('<SPAN class="captcha"></SPAN><NOSCRIPT><img src="' . $server . '/securimage_show.php?' . $sessionid . 'width=100&amp;height=40&amp;characters=5" alt="Security Image" /> <br />Please enter the security code as above: <input id="security_code" name="security_code" type="text" /></NOSCRIPT>');
  return $strCaptcha;
}

/**
 * A captchaResponse is returned from captcha_check_answer()
 */
class captchaResponse {

  var $is_valid;
  var $error;

}

/**
 * Calls an HTTP POST function to verify if the user's guess was correct
 * @param string $request
 * @param array $extra_params an array of extra variables to post to the server
 * @return captchaResponse
 */
function captcha_check_answer($request = false, $extra_params = array()) {
  if (empty($request)) {
    $request = $_REQUEST;
  }

  //discard spam submissions
  if (empty($request['security_code']) &&
    (
      empty($request['captcha_field_name']) || (!empty($request['captcha_field_name']) && empty($request[$request['captcha_field_name']]))
    )
  ) {
    $captcha_response = new captchaResponse();
    $captcha_response->is_valid = false;
    $captcha_response->error = 'incorrect-captcha-sol';
    return $captcha_response;
  }

  $response = _captcha_http_post(
    'webtools.ec.europa.eu', '/captcha' . '/captchaverify.php', $request + $extra_params
  );

  $answers = explode("\n", $response [1]);
  $captcha_response = new captchaResponse();
  if (trim($answers[0]) == 'true') {
    $captcha_response->is_valid = true;
    $captcha_response->error = $answers[1];
  }
  else {
    $captcha_response->is_valid = false;
    $captcha_response->error = $answers[1];
  }
  return $captcha_response;
}
