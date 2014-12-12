Feature: Group Wiki pages
  As a group member and non-member
  I need to be able to see a WIKI detail page

  @api @wip
  Scenario: Check Wiki detail as an anonymous user
    Given I am an anonymous user
    When I visit the group "wiki_page" detail page "Lusail Soccer Stadium"
    Then I should see the Wiki detail page

  @api @wip
  Scenario: Check Wiki detail as group owner
    Given I am logged in as user "alfrednobel"
    When I visit the group "wiki_page" detail page "Lusail Soccer Stadium"
    Then I should see the Wiki detail page
