Feature: Group Wiki pages
  As a group member and non-member
  I need to be able to see a WIKI detail page
  As a group member I need to see an unpublished WIKI detail page if I have
  the OG permission to 'view unpublished group content'
  As a non-member I cannot see an unpublished WIKI detail page even if I have
  the OG permission to 'view unpublished group content'

  @api
  Scenario: Check Wiki detail as an anonymous user
    Given I am an anonymous user
    When I visit the group "wiki_page" detail page "Prizes"
    Then I should see the Wiki detail page

  @api
  Scenario: Check Wiki detail as group owner
    Given I am logged in as user "alfrednobel"
    When I visit the group "wiki_page" detail page "Prizes"
    Then I should see the Wiki detail page

  @api @wip
  Scenario: Check if group member can see unpublished WIKI page
    Given I am logged in as user "alfredsgroupie"
    When I visit the group "wiki_page" detail page "Unpublished"
    Then I should see the Wiki detail page

  @api @wip
  Scenario: Check if non-member can see unpublished WIKI page
    Given I am logged in as user "alfredsgroupie"
    When I visit the group "wiki_page" detail page "Wonders"
    Then I should see an Access denied page