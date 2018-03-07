Feature: Testing user creation/manipulations.

  @api
  Scenario: Testing the user firstname+lastname URL alias path.
     Given I am an anonymous user
      When I visit "/users/charles-darwin"
      Then I should have access to the page

  @api
  Scenario: Testing the user profile fields
     Given I am an anonymous user
      When I visit "/users/galileo-galilei"
      Then I should see a "Country" field
      Then I should see a "Topics" field
       And I should see a "Topics of Expertise" field
       And I should see a "Regions & Countries" field
       And I should see a "About You" field
       And I should see a "Notable Contributions" field

  @api
  Scenario: Testing "my content" page
     Given I am logged in as user "alfrednobel"
      When I click "Hello Alfred Nobel"
      And  I click "My content"
       And I should see "Sort by:"
      Then I should see "Type"
      Then I should see "Status"
      Then I should see "Topics"
      When I fill in "search" with "medals"
      And  I press "edit-submit-my-content"
      Then I should see "2 in total, 1 - 2 shown"

  @javascript
  Scenario: Testing "my comments" page
     Given I am logged in as user "badhairday"
      When I click "Hello Albert Einstein"
      And  I click "My content"
      And  I follow "My comments (2)"
      Then I should see "Type"
      And  I should see "Topics"
      And  I should see "Sort by:"
      And  I should see "2 in total, 1 - 2 shown"
      Then I follow "Back to my content"
      And  I follow "My comments (2)"
      When I follow "Fire (1)"
      Then I should see "1 in total, 1 - 1 shown"
      And  I should see "Act only according to that maxim whereby you can at the same time will that it should become a universal law without contradiction"
      When I fill in "search" with "world"
      And I check the box "edit-search-within-results"
      And  I press "edit-submit-my-comments"
      Then I should not see "1 in total, 1 - 1 shown"
      But  I click the "span.facetapi-deactivate" element
      Then I should see "1 in total, 1 - 1 shown"
      And  I should see "What is the world?"
      When I follow "Nobel Prize ceremony"
      Then I should see "Add new comment"

  @api
  Scenario: The user tries to leave the platform but still has groups.
    Given I am logged in as user "mariecurie"
     When I visit the leave platform page of the current user
     Then I should see "You can't leave the platform"

  @javascript
  Scenario: The user leaves the platform.
    Given The window is maximized
      And I am logged in with a temporal user
     When I visit the leave platform page of the current user
      And I check the box "I no longer want my name to appear on contents I have contributed - please make all my content anonymous"
      And I fill in "edit-feedback" with "Just testing leaving the platform."
      And I press "Confirm"
      # For some reason travis can not handle the batch operation that
      # triggered when an account is being canceled, hence we skip the last
      # step.
#     Then I should not be able to log in with the temporal user again

  @api
  Scenario: System administrator creates a user.
    Given I am logged in as user "mariecurie"
    When I go to "admin/people/create"
    And  I fill in "mail" with "tempuser@behat.com"
    And  I fill in "c4m_first_name[und][0][value]" with "test"
    And  I fill in "c4m_last_name[und][0][value]" with "user"
    And  I fill in "c4m_organisation[und][0][value]" with "user organisation"
    And  I select "government" from "c4m_organisation_type[und]"
    And  I select "IL" from "c4m_country[und]"
    And  I fill in "name" with "behatuser"
    And  I fill in "pass[pass1]" with "1111"
    And  I fill in "pass[pass2]" with "1111"
    And  I press "Create new account"
    Then I should see the text "Created a new user account for behatuser"
