Feature: Unified Workflow
  Test unified workflow

  @api
  Scenario: As a visitor I can request a membership of a moderated group.
    Given  I am an anonymous user
     And   I disable the captcha field
     When  I visit the dashboard of group "Nobel Prize"
     And   I click "Request membership for this group"
     Then  I should see "To join the Nobel Prize group you need to register with capacity4more by filling in your details below"
     When  I fill in "mail" with "unified_workflow_user@example.com"
     And   I fill in "edit-c4m-first-name-und-0-value" with "New"
     And   I fill in "edit-c4m-last-name-und-0-value" with "User"
     And   I fill in "c4m_organisation[und][0][value]" with "Unified organisation"
     And   I select "european_institutions" from "c4m_organisation_type[und]"
     And   I select "IL" from "c4m_country[und]"
     And   I fill in "name" with "unified_workflow"
     And   I fill in "edit-pass-pass1" with "drupal"
     And   I fill in "edit-pass-pass2" with "drupal"
     And   I press "Register to join"
     And   I enable the captcha field
    Then   I should see "Hey New User, thank you for submitting your details. Please activate your account by clicking the link sent to your e-mail to join the Nobel Prize group."

  @api
  Scenario: As a banned user I am not allowed to join the group.
    Given I am logged in with a temporal user
    When  I visit the dashboard of group "Football Talk"
    And   I click "Join this group"
    Then  I should see "Welcome to group Football Talk"
    When  I am logged in as user "mariecurie"
    Then  I block "temporal_user" from "Football Talk"
    When  I am logged in with a temporal user again
    And   I visit the dashboard of group "Football Talk"
    Then  I should not see the text "Join this group"
    When  I try to join the "Football Talk" group via url
    Then  I should not have access to the page
