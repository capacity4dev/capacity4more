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

  @api
  Scenario: Check GA can edit a wiki page's author
    Given I am logged in as user "galileo"
    When I visit the group "wiki_page" detail page "Award Process"
    And I click "Edit" in the "primary tabs" region
    Then I should see the text "Edit Wiki page Award Process"
    And I should see the text "Authoring information"

  @api
  Scenario: Check SA can edit a wiki page's author
    Given I am logged in as user "survivalofthefittest"
    When I visit the group "wiki_page" detail page "Award Process"
    And I click "Edit" in the "primary tabs" region
    Then I should see the text "Edit Wiki page Award Process"
    And I should see the text "Authoring information"

  @api
  Scenario: Check GM can edit a wiki page which is allowed to edit by GM
    # Check GM can not edit a wiki page which is not allowed to edit by GM.
    Given I am logged in with a temporal user
    When I visit the group "wiki_page" detail page "2011-2012"
    Then I should not be able to see the edit link

    # Allow all members to edit the wiki page.
    When I am logged in as user "badhairday"
    When I visit the group "wiki_page" detail page "2011-2012"
    And I click "Edit" in the "primary tabs" region
    Then I should see the text "Edit Wiki page 2011-2012"
    Then I check the box "Editable by members"
    And  I press "Save"
    Then I should see the text "Wiki page 2011-2012 has been updated."

    # Make sure the user is now able to edit the wiki page.
    When  I am logged in with a temporal user again
    When I visit the dashboard of group "Football Talk"
    And  I click "Join this group"
    When I visit the group "wiki_page" detail page "2011-2012"
    And  I click "Edit" in the "primary tabs" region
    Then I should see the text "Edit Wiki page 2011-2012"
