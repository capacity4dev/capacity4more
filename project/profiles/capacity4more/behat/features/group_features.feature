Feature: Group features
  As a group administrator I can enable and disable features.

  @api
  Scenario: Check I can manage features as group owner.
    Given I am logged in as user "mariecurie"
    When  I manage the features of group "Movie Popcorn Corner"
    Then  I should have access to the page
    And   I should see "Manage features"

  @api
  Scenario: Check I can't manage features as group member.
    Given I am logged in as user "isaacnewton"
    When  I manage the features of group "Movie Popcorn Corner"
    Then  I should not have access to the page

  @api
  Scenario: Check I can disable features as group owner.
    Given I am logged in as user "mariecurie"
    When  I manage the features of group "Movie Popcorn Corner"
    And   I disable the group feature "wiki"
    And   I disable the group feature "photoalbums"
    And   I disable the group feature "discussions"
    And   I disable the group feature "documents"
    And   I disable the group feature "events"
    And   I disable the group feature "members"
    And   I press "Save configuration"
    And   I wait
    Then  I should not see the "Wiki" link on the group menu
    Then  I should not see the "Discussions" link on the group menu
    Then  I should not see the "Library" link on the group menu
    Then  I should not see the "Events" link on the group menu
    Then  I should not see the "Members" link on the group menu

  @api
  Scenario: Check I can enable features as group owner.
    Given I am logged in as user "mariecurie"
    When  I manage the features of group "Movie Popcorn Corner"
    And   I enable the group feature "wiki"
    And   I enable the group feature "photoalbums"
    And   I enable the group feature "discussions"
    And   I enable the group feature "documents"
    And   I enable the group feature "events"
    And   I enable the group feature "members"
    And   I press "Save configuration"
    And   I wait
    Then  I should see the "Wiki" link on the group menu
    Then  I should see the "Discussions" link on the group menu
    Then  I should see the "Library" link on the group menu
    Then  I should see the "Events" link on the group menu
    Then  I should see the "Members" link on the group menu
