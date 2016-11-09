Feature: Group Discussions
  As a group member and non-member
  In order to see and search into all discussions
  I need to be able to see a discussions overview page
  I need to be able to see a discussion detail page

  @api
  Scenario: Check discussions overview as an anonymous user
    Given I am an anonymous user
    When I visit the discussions overview of group "Nobel Prize"
    Then I should see the discussions overview
    And I should not see the "Add a new Discussion" link above the overview

  @api
  Scenario: Check discussions overview as group owner
    Given I am logged in as user "alfrednobel"
    When I visit the discussions overview of group "Nobel Prize"
    Then I should see the discussions overview
    And I should see the "Add a new Discussion" link above the overview

  @api
  Scenario: Check discussions detail as an anonymous user
    Given I am an anonymous user
    When I visit the group "discussion" detail page "Nobel Foundation"
    Then I should see the discussion detail page

  @api
  Scenario: Check discussions detail as group owner
    Given I am logged in as user "alfrednobel"
    When I visit the group "discussion" detail page "Nobel Foundation"
    Then I should see the discussion detail page

  @javascript
  Scenario: Check group reference field is filled from context and hidden
    Given I am logged in as user "mariecurie"
    When  I start creating "discussion" "Some new discussion1" in group "Architecture" with file field "c4m-related-document"
    And   I check the related topic checkbox
    And   I should not see an "edit-og-group-ref-und-0-default" element
    And   I press "Publish"
    Then  I should see "Some new discussion1" in the activity stream of the group "Architecture"

  @javascript
  Scenario: Check group reference field is filled from context and hidden
    Given I am logged in as user "mariecurie"
    When  I start editing "discussion" "Some new discussion1" in group "Architecture"
    Then  I should not see an "edit-og-group-ref-und-0-default" element

  @javascript
  Scenario: Check edit own discussion of member group.
    Given I am logged in as user "galileo"
    When  a discussion "Some new discussion3" in group "Tennis Group" is created
    And   I start editing "discussion" "Some new discussion3" in group "Tennis Group"
    Then  I should see "Edit discussion"
    And   I should see "Some new discussion3"

  @api @c
  Scenario: Check GA can edit a discussion's author
    Given I am logged in as user "galileo"
    When I visit the group "discussion" detail page "Medals"
    And I click "Edit" in the "primary tabs" region
    Then I should see the text "Edit Discussion Medals"
    And I should see the text "Authoring information"

  @api
  Scenario: Check SA can edit a discussion's author
    Given I am logged in as user "survivalofthefittest"
    When I visit the group "discussion" detail page "Medals"
    And I click "Edit" in the "primary tabs" region
    Then I should see the text "Edit Discussion Medals"
    And I should see the text "Authoring information"

  @javascript
  Scenario: Check unpublish button on node edit forms as an authenticated user
    Given I am logged in as user "alfrednobel"
    And   a discussion "Edit this discussion" in group "NobelPrize" is created
    When  I start editing "discussion" "Edit this discussion" in group "Nobel Prize"
    Then  I should see "Unpublish" in the "#edit-draft" element

  @javascript
  Scenario: Promote buttons shouldn't be displayed to anonymous users.
    Given  I am an anonymous user
    When I visit the discussions overview of group "Nobel Prize"
    Then  I should not see the ".fa-thumb-tack" element

  @javascript
  Scenario: Promote buttons shouldn't be displayed to users without access.
    Given  I am logged in as user "isaacnewton"
    When I visit the discussions overview of group "Nobel Prize"
    Then  I should not see the ".fa-thumb-tack" element

  @javascript
  Scenario Outline: Promote and highlight buttons should be displayed to users with access.
    Given  I am logged in as user "<user>"
    When I visit the discussions overview of group "Nobel Prize"
    Then  I should see the ".fa-star-o" element
    And   I should see the ".fa-thumb-tack" element

    Examples:
      | user        |
      | alfrednobel |
      | mariecurie  |

