Feature: Contact
  Check functionality of the contact form.

  @api
  Scenario: As admin, I see validation errors if I don't add a correct e-mail.
    Given I am logged in as user "mariecurie"
    When I go to "admin/config/c4m/contact-email"
    And I fill in "E-mail addresses" with "info@example.com, a wrong mail@example.com"
    And I press "Save configuration"
    Then I should see "The next e-mails present errors"

  @api
  Scenario: As admin, I can add mail addresses as recipients of the contact form.
    Given I am logged in as user "mariecurie"
    When I go to "admin/config/c4m/contact-email"
    And I fill in "E-mail addresses" with "info@example.com, other@example.com"
    And I press "Save configuration"
    Then I should see "The configuration options have been saved."

  @javascript
  Scenario: As a logged in user, I can see the wysiwyg when sending the contact form to an user.
    Given I am logged in as user "alfrednobel"
    When I go to user "mariecurie" contact form
    Then I should see "Contact"
    And I should see the "#cke_edit-c4m-contact-user-body-value" element

  @api
  Scenario: Check contact page as anonymous
    Given I am an anonymous user
    When I go to "contact"
    And I press "Send message"
    Then I should see "Subject field is required"
    And I should see "Message field is required."
    And I should see "Your name field is required."
    And I should see "Your e-mail address field is required."

  @api
  Scenario: Check contact page as logged in user
    Given I am logged in as user "isaacnewton"
    When I go to "contact"
    And I press "Send message"
    Then I should see "Subject field is required"
    And I should see "Message field is required."
    And I should not see "Your name field is required."
    And I should not see "Your e-mail address field is required."

  @api
  Scenario: Send the contact form as anonymous
    Given I am an anonymous user
    And I disable the captcha field
    When I go to "contact"
    And I fill in "Your name" with "Nikola Tesla"
    And I fill in "Your e-mail address" with "tesla@edison.sucks"
    And I fill in "Subject" with "I want a nobel prize"
    And I fill in "Message" with "I want a nobel prize too."
    And I press "Send message"
    And I enable the captcha field
    Then I should see "Your message has been sent."

  @api
  Scenario: Send the contact form as logged in user
    Given I am logged in as user "isaacnewton"
    And I disable the captcha field
    When I go to "contact"
    And I press "Send message"
    And I fill in "Subject" with "I want a nobel prize"
    And I fill in "Message" with "I want a nobel prize too."
    And I press "Send message"
    And I enable the captcha field
    Then I should see "Your message has been sent."
