Feature: Group Invitations
  As a group member and non-member
  In order to invite users and visitors
  I need to be able to access the group invitation forms

  @api
    Scenario: Check access to invite visitors to an open group for GMs
    Given I am logged in as user "charlesbabbage"
    When  I visit the dashboard of group "Music Lovers"
    # charlesbabbage joined Music Lovers in a previous test.
    And   I click "Invite a member"
    Then  I should not see "Access denied"
    And   I should see the text "Invite new users"

  @api
    Scenario: Check access denied for inviting visitors to a private group to GMs
    Given I am logged in as user "galileo"
    When  I try to invite visitors to "Tennis Group" group
    Then  I should see the text "Access denied"

  @api
  Scenario: Check access denied for inviting users to a private group to GMs
    Given I am logged in as user "galileo"
    When  I try to invite users to "Tennis Group" group
    Then  I should see the text "Access denied"

  @api
  Scenario: Check email validation when inviting visitors
    Given I am logged in as user "galileo"
    When  I visit the dashboard of group "Music Lovers"
    And   I click "Invite a member"
    And   I send an invitation to "emailexample.com"
    Then  I should see the text "Invalid email emailexample.com"

  @api
  Scenario: Check that sending an invitation to a visitor saves the information to DB
    Given I am logged in as user "galileo"
    When  I visit the dashboard of group "Music Lovers"
    And   I click "Invite a member"
    And   I send an invitation to "email@example.com"
    Then  I should see the text "An email notification was sent to email@example.com."
