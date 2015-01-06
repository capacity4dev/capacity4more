<?php
/**
 * @file
 * Context methods about Files, file field & their widgets.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


trait File {
  /**
   * @Given /^I upload the file "([^"]*)"$/
   */
  public function iUploadTheFile($file) {
    $file_path = rtrim(realpath($this->getMinkParameter('files_path')), DIRECTORY_SEPARATOR).DIRECTORY_SEPARATOR.$file;

    $fileInputXpath = './/div[contains(@name, "discussion-document-upload")]/input[contains(@type, "file")]';

    $fields = $this->getSession()->getDriver()->find($fileInputXpath);
    $field = count($fields) > 0 ? $fields[0] : NULL;
    if (null === $field) {
      throw new \Exception("File input is not found");
    }
    $this->getSession()->resizeWindow(1440, 900, 'current');

    // Attaching file is working only if input is visible.
    $this->getSession()->getDriver()->evaluateScript(
      "jQuery('.document_file').css('display', 'block');"
    );
    $field->attachFile($file_path);
    // Make input hidden after attaching the file.
    $this->getSession()->getDriver()->evaluateScript(
      "jQuery('.document_file').css('display', 'none');"
    );
  }

  /**
   * @Given /^I save document with title "([^"]*)" for a discussion$/
   */
  public function iSaveDocumentWithTitleForADiscussion($title) {
    $label_xpath = ".//*[contains(@name, \"documentForm\")]//input[contains(@name, \"label\")]";
    $save_xpath = ".//*[contains(@name, \"documentForm\")]//button[contains(@id, \"quick-submit\")]";

    $fields = $this->getSession()->getDriver()->find($label_xpath);
    $fields[0]->setValue($title);

    $javascript = "angular.element('form[name=\"documentForm\"]').find('textarea#body').scope().data.body = 'Some document text';";
    $this->getSession()->executeScript($javascript);

    $fields = $this->getSession()->getDriver()->find($save_xpath);
    $fields[0]->press();
  }

  /**
   * @Given /^I upload the file "([^"]*)" in the field "([^"]*)"$/
   */
  public function iUploadTheFileInTheField($file, $fieldname) {
    // Attaching file is working only if input is visible.
    $file_path = rtrim(realpath($this->getMinkParameter('files_path')), DIRECTORY_SEPARATOR).DIRECTORY_SEPARATOR.$file;

    $fileInputXpath = './/div[contains(@name, "' . $fieldname . '")]/input[contains(@type, "file")]';

    $fields = $this->getSession()->getDriver()->find($fileInputXpath);
    $field = count($fields) > 0 ? $fields[0] : NULL;
    if (null === $field) {
      throw new \Exception("File input is not found");
    }
    $field->attachFile($file_path);
  }

  /**
   * @Given /^I save document with title "([^"]*)"$/
   */
  public function iSaveDocumentWithTitle($title) {

    $javascript = "
      jQuery(Drupal.overlay.activeFrame[0].contentDocument).find('#label').val('" . $title . "');
//      jQuery(Drupal.overlay.activeFrame[0].contentDocument).find('#save').trigger('click');
      jQuery(Drupal.overlay.activeFrame[0].contentDocument).find('#save').click();
    ";
    $this->getSession()->executeScript($javascript);


    // Unique filename.
    $filePath = $this->debug['dump_path'];
    $fileName = rtrim(realpath($filePath), DIRECTORY_SEPARATOR)
      . DIRECTORY_SEPARATOR
      . date('YmdHis') . '_' . uniqid();
    $driver = $this->getSession()->getDriver();
    $screenshot = $driver->getScreenshot();
    file_put_contents($fileName . '.png', $screenshot);


//    $javascript = "jQuery(Drupal.overlay.activeFrame[0].contentDocument).find('#save').trigger('click');";
//    $this->getSession()->executeScript($javascript);



  }
}
