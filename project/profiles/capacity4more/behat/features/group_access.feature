Feature: Group access
  Test group access

  @javascript
  Scenario: Check public group
    Given a group "My bad hair day new group 111" with "Public" access is created with group manager "turing"
      And a discussion "My content 111" in group "My bad hair day new group 111" is created
     When I am logged in as user "isaacnewton"
     Then I visit "My bad hair day new group 111" node of type "group"
      And I should not see "Access denied"
      And I visit "My content 111" node of type "discussion"
      And I should not see "Access denied"
      And I should see "My bad hair day new group 111" on the "groups" overview

  @javascript
  Scenario: Check private group
    Given a group "My bad hair day new group 2" with "Private" access is created with group manager "turing"
      And a discussion "My content 2" in group "My bad hair day new group 2" is created
     When I am logged in as user "isaacnewton"
     Then I visit "My bad hair day new group 2" node of type "group"
      And I should see "Access denied"
      And I should not see "My bad hair day new group 2" on the "groups" overview
      And I visit "My content 2" node of type "discussion"
      And I should see "Access denied"

  @javascript
  Scenario: Check restricted group accessed by accepted user
    Given a moderated group "My bad hair day new group 3" with "gravity.com" restriction is created with group manager "turing"
      And a discussion "My content 3" in group "My bad hair day new group 3" is created
     When I am logged in as user "isaacnewton"
     Then I visit "My bad hair day new group 3" node of type "group"
      And I should not see "Access denied"
      And I should see "My bad hair day new group 3" on the "groups" overview
      And I visit "My content 3" node of type "discussion"
      And I should not see "Access denied"
      And I am logged in as user "badhairday"
      And I visit "My bad hair day new group 3" node of type "group"
      And I should see "Access denied"
      And I should not see "My bad hair day new group 3" on the "groups" overview
      And I visit "My content 3" node of type "discussion"
      And I should see "Access denied"

  @javascript
  Scenario: Check restricted group accessed by accepted organization user
    Given a moderated group "My bad hair day new group 5" with "EC/EEAS" organization restriction is created with group manager "turing"
      And a discussion "My content 5" in group "My bad hair day new group 5" is created
     When I am logged in as user "president"
     Then I visit "My bad hair day new group 5" node of type "group"
      And I should not see "Access denied"
      And I should see "My bad hair day new group 5" on the "groups" overview
      And I visit "My content 5" node of type "discussion"
      And I should not see "Access denied"
      And I am logged in as user "isaacnewton"
      And I visit "My bad hair day new group 5" node of type "group"
      And I should see "Access denied"
      And I should not see "My bad hair day new group 5" on the "groups" overview
      And I visit "My content 5" node of type "discussion"
      And I should see "Access denied"

  @api
  Scenario: Check hidden fields for an authorized user while creating a new group.
    Given I am logged in as user "isaacnewton"
    When I visit "node/add/group"
    Then I should not see an ".field-name-c4m-related-projects" element
    And I should not see an ".field-name-c4m-related-group" element
    And I should not see an ".node-form .field-name-c4m-og-status" element
    And I should not see an ".tabbable.tabs-left.vertical-tabs" element

  @api
  Scenario: Visitor should not see a private group
    Given I am an anonymous user
    Then  I should not see "Architecture" on the "groups" overview
    When  I visit "Architecture" node of type "group"
    Then  I should not have access to the page
    And   I should see "Please log in to continue"

  @api
  Scenario: Visitor should not see a restricted group
    Given I am an anonymous user
    Then  I should not see "Restricted group with EC/EEAS" on the "groups" overview
    When  I visit "Restricted group with EC/EEAS" node of type "group"
    Then  I should not have access to the page
    And   I should see "Please log in to continue"

  @api
  Scenario: Non member should not see a private group
    Given I am logged in as user "president"
    Then  I should not see "Architecture" on the "groups" overview
    When  I visit "Architecture" node of type "group"
    Then  I should not have access to the page
    And   I should see "Access denied"

  @api
  Scenario: Non member without restrictions bypass should not see a restricted group
    Given I am logged in as user "president"
    Then  I should not see "Restricted group with EC/EEAS" on the "groups" overview
    When  I visit "Restricted group with EC/EEAS" node of type "group"
    Then  I should not have access to the page
    And   I should see "Access denied"

  @api
  Scenario: Non member with restrictions bypass should see the restricted group
    Given I am logged in as user "president"
    Then  I should see "Restricted group with EU" on the "groups" overview
    When  I visit "Restricted group with EU" node of type "group"
    Then  I should have access to the page
    And   I should not see "Access denied"

  @api
  Scenario: New user with organization domain should have access to organization restriction group.
    Given I am logged in with a temporal user with email domain "gizra.com"
    Then  I should see "Restricted group with partner access" on the "groups" overview
    When  I visit "Restricted group with partner access" node of type "group"
    Then  I should have access to the page
    And   I should not see "Access denied"

  @javascript
  Scenario: Restricted group by organization and domains access for new users.
    Given I am logged in with a temporal user with email domain "ec.europa.eu"
    Then  a non moderated restricted group "Drink water out of the faucet" with "ec.europa.eu muppets.co.uk" domains and with "Gizra,Amplexor" organizations is created by the temporal user
    Then  I should see "Drink water out of the faucet" on the "groups" overview
    Given I am logged in with a temporal user with email domain "eeas.europa.eu"
    Then  I should not see "Drink water out of the faucet" on the "groups" overview
    When  I am logged in with a temporal user with email domain "ec.europa.eu"
    Then  I should see "Drink water out of the faucet" on the "groups" overview
    When  I am an anonymous user
    Then  I should not see "Drink water out of the faucet" on the "groups" overview
    When  I am logged in as user "mariecurie"
    Then  I should see "Drink water out of the faucet" on the "groups" overview
