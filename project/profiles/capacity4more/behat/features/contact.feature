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

  @javascript @c
  Scenario: As a logged in user, I can see the wysiwyg when sending the contact form to an user.
    Given I am logged in as user "alfrednobel"
    When I go to user "mariecurie" contact form
    Then I should see "Contact"
    And I see the wysiwyg
