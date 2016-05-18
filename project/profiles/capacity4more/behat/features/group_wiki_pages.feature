Feature: Group Wiki pages
  As a group member, group administrator and non-member
  I need to be able to see a WIKI detail page
  As a group member I need to see an unpublished WIKI detail page if I have
  the OG permission to 'view unpublished group content'
  As a non-member I cannot see an unpublished WIKI detail page even if I have
  the OG permission to 'view unpublished group content'
  As anonymous user I cannot see an unpublished WIKI detail page

  @api
  Scenario: Check Wiki detail as an anonymous user
    Given I am an anonymous user
    When I visit the page "wiki/prizes" in the group "Nobel Prize"
    Then I should see the Wiki detail page
      And I should not see the wiki create links

  @api
  Scenario: Check Wiki detail as group owner
    Given I am logged in as user "alfrednobel"
    When I visit the page "wiki/prizes" in the group "Nobel Prize"
    Then I should see the Wiki detail page
      And I should see the wiki create links

  @api
  Scenario: Check Wiki detail as group administrator
    Given I am logged in as user "galileo"
    When I visit the page "wiki/prizes" in the group "Nobel Prize"
    Then I should see the Wiki detail page
      And I should see the wiki create links

  @api
  Scenario: Check if group member can see unpublished WIKI page
    Given I am logged in as user "alfrednobel"
    When I visit the group "wiki_page" detail page "Unpublished Wiki Page (Tennis)" with status "unpublished"
    Then I should see an unpublished Wiki detail page

  @api
  Scenario: Check if non-member can see unpublished WIKI page
    Given I am logged in as user "alfrednobel"
    When I visit the group "wiki_page" detail page "Unpublished Wiki Page (Popcorn)" with status "unpublished"
    Then I should see "Access denied"

  @api
  Scenario: Check if anonymous user can see unpublished WIKI page
    Given I am an anonymous user
    When I visit the group "wiki_page" detail page "Unpublished Wiki Page (Tennis)" with status "unpublished"
    Then I should see "Please log in to continue"