Feature: Group dashboard
  As a group member and non-member
  In order to see the group latest activity and information
  I need to be able to see a dashboard with different widgets

  @api
  Scenario: Check dashboard content as group owner
    Given I am logged in as user "mariecurie"
    When  I visit the dashboard of group "Movie Popcorn Corner"
    Then  I should see the group dashboard with quick post form

  @api
  Scenario: Check dashboard is not accessable for not member of the private group.
    Given I am logged in as user "mariecurie"
    When  I change access of group "Movie Popcorn Corner" to "Private"
    And   I am logged in as user "president"
    And   I visit the dashboard of group "Movie Popcorn Corner"
    Then  I should see "Access denied"

  @api
  Scenario: Check dashboard is not accessable for not member of the group with restricted access.
    Given I am logged in as user "mariecurie"
    When  I change access of group "Movie Popcorn Corner" to "Restricted"
    And   I am logged in as user "president"
    And   I visit the dashboard of group "Movie Popcorn Corner"
    Then  I should see "Access denied"

  @api
  Scenario: Check dashboard is accessable for not member of the group with restricted access.
    Given I am logged in as user "mariecurie"
    When  I change access of group "Movie Popcorn Corner" to Restricted with "ec.europa.eu" restriction
    And   I am logged in as user "president"
    And   I visit the dashboard of group "Movie Popcorn Corner"
    Then  I should see the group dashboard without quick post form

  @api
  Scenario: Check dashboard is accessable for not member of the public group.
    Given I am logged in as user "mariecurie"
    When  I change access of group "Movie Popcorn Corner" to "Public"
    And   I am logged in as user "president"
    And   I visit the dashboard of group "Movie Popcorn Corner"
    Then  I should see the group dashboard without quick post form

  @api
  Scenario: Check Invite a member link is available for a member of an open public group.
    Given I am logged in as user "charlesbabbage"
    When  I visit the dashboard of group "Music Lovers"
    And   I click "Invite a member"
    Then  I should see the text "Invite People to Join"

  @api
  Scenario: Check Invite a member link is not available for a member of a private group.
    Given I am logged in as user "badhairday"
    When  I visit the dashboard of group "Tennis Group"
    Then  I should not see the link "Invite a member"

  @api
  Scenario: Check Invite a member link is not available for a non-member of a group.
    Given I am logged in as user "president"
    When  I visit the dashboard of group "Movie Popcorn Corner"
    Then  I should not see the link "Invite a member"

  @api
  Scenario: Check Invite a member link is available for an administrator of a private group.
    Given I am logged in as user "alfrednobel"
    When  I visit the dashboard of group "Tennis Group"
    And   I click "Invite a member"
    Then  I should see the text "Invite People to Join"

  @api
  Scenario: Check Invite a member link is available for a site administrator who is a non-member of a private group.
    Given I am logged in as user "survivalofthefittest"
    When  I visit the dashboard of group "Architecture"
    And   I click "Invite a member"
    Then  I should see the text "Invite People to Join"
