Feature: Contact
  Check functionality of the contact form.

  @api @c
  Scenario: As admin, I see validation errors if I don't add a correct e-mail.
    Given I am logged in as user "mariecurie"
    When I go to "admin/config/c4m/contact-email"
    And I fill in "E-mail addresses" with "info@example.com, a wrong mail@example.com"
    And I press "Save configuration"
    Then I should see "The next e-mails present errors" in the status messages

  @api @c
  Scenario: As admin, I can add mail addresses as recipients of the contact form.
    Given I am logged in as user "mariecurie"
    When I go to "admin/config/c4m/contact-email"
    And I fill in "E-mail addresses" with "info@example.com, other@example.com"
    And I press "Save configuration"
    Then I should see "The configuration options have been saved." in the status messages

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
