Feature: Contact
  Check functionality of the contact form.

  @api
  Scenario: Check contact page as anonymous
    Given I am an anonymous user
    When I go to "contact"
    Then I should see an enabled "#edit-name" element
    And I should see an enabled "#edit-mail" element
    And I should see an enabled "#edit-subject" element
    And I should see an enabled "#edit-cid" element
    And I should see an enabled "#edit-message" element
    And I should see an enabled ".captcha" element

  @api
  Scenario: Check contact page as logged in user
    Given I am logged in as user "isaacnewton"
    When I go to "contact"
    Then I should see a disabled "#edit-name" element
    And I should see a disabled "#edit-mail" element
    And I should see an enabled "#edit-subject" element
    And I should see an enabled "#edit-cid" element
    And I should see an enabled "#edit-message" element
    And I should see an enabled "#edit-copy" element
    And I should see an enabled ".captcha" element
