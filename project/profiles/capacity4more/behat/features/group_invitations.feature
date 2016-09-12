Feature: Group Invitations
  As a group member and non-member
  In order to invite users and visitors
  I need to be able to access the group invitation forms

  @api
  Scenario: Check Invite a member link is available for a member of an open public group.
  Given I am logged in as user "charlesbabbage"
  When  I visit the dashboard of group "Music Lovers"
  And   I join the open group "Music Lovers"
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

  @api
    Scenario: Check access to invite visitors to an open group for GMs
    Given I am logged in as user "charlesbabbage"
    When  I visit the dashboard of group "Football Talk"
    And   I join the open group "Football Talk"
    And   I go to "group/node/10/admin/people/invite-visitors"
    Then  I should not see "Access denied"
    And   I should see the text "Invite Visitors"

  @api
    Scenario: Check access denied for inviting visitors to a private group to GMs
    Given I am logged in as user "galileo"
    When  I go to "group/node/11/admin/people/invite-visitors"
    Then  I should see the text "Access denied"

  @api
  Scenario: Check access to invite users to an open group for GMs
    Given I am logged in as user "charlesbabbage"
    When  I visit the dashboard of group "Football Talk"
    And   I join the open group "Football Talk"
    And   I click "Invite a member"
    Then  I should not see "Access denied"
    And   I should see the text "Invite People to Join"

  @api
  Scenario: Check access denied for inviting users to a private group to GMs
    Given I am logged in as user "galileo"
    When  I go to "group/node/11/admin/people/invite-users"
    Then  I should see the text "Access denied"

  @api
  Scenario: Check email validation when inviting visitors
    Given I am logged in as user "galileo"
    When  I visit the dashboard of group "Music Lovers"
    And   I click "Invite a member"
    And   I click "Invite Visitors"
    And   I send an invitation to "emailexample.com"
    Then  I should see the text "Invalid email emailexample.com"

  @api
  Scenario: Check that sending an invitation to a visitor saves the information to MySQL
    Given I am logged in as user "galileo"
    When  I visit the dashboard of group "Music Lovers"
    And   I click "Invite a member"
    And   I click "Invite Visitors"
    And   I send an invitation to "email@example.com"
    Then  I should see the text "An email notification was sent to email@example.com."
