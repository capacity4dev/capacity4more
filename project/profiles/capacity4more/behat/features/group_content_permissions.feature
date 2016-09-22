Feature: Test creation of the content permissions.
  Test group members' permissions.

  @javascript
  Scenario: Check Discussion creating in the own group
    Given a group "Discussion Insert 2" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    Then  I should be allowed to create a "discussion" in group "Discussion Insert 2"

  @javascript
  Scenario: Check Event creating in the own group
    Given a group "Discussion Insert 4" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    Then  I should be allowed to create a "event" in group "Discussion Insert 4"

  @api
  Scenario: There should be no access to 'create event' global form.
    Given I am logged in as user "isaacnewton"
    When  I go to "node/add/event"
    Then  I should not have access to the page

  @api
  Scenario: Group non member should not have access to group 'create event' form.
    Given I am logged in as user "badhairday"
    When  I go to "movie-corner/node/add/event"
    Then  I should not have access to the page

  @api
  Scenario: Group member should have access to group 'create event' form.
    Given I am logged in as user "isaacnewton"
    When  I go to "movie-corner/node/add/event"
    Then  I should have access to the page

  @api
  Scenario: There should be no access to 'create document' global form.
    Given I am logged in as user "isaacnewton"
    When  I go to "node/add/document"
    Then  I should not have access to the page

  @api
  Scenario: Group non member should not have access to group 'create document' form.
    Given I am logged in as user "badhairday"
    When  I go to "movie-corner/node/add/document"
    Then  I should not have access to the page

  @api
  Scenario: Group member should have access to group 'create document' form.
    Given I am logged in as user "isaacnewton"
    When  I go to "movie-corner/node/add/document"
    Then  I should have access to the page

  @api
  Scenario: There should be no access to 'create discussion' global form.
    Given I am logged in as user "isaacnewton"
    When  I go to "node/add/discussion"
    Then  I should not have access to the page

  @api
  Scenario: Group non member should not have access to group 'create discussion' form.
    Given I am logged in as user "badhairday"
    When  I go to "movie-corner/node/add/discussion"
    Then  I should not have access to the page

  @api
  Scenario: Group member should have access to group 'create discussion' form.
    Given I am logged in as user "isaacnewton"
    When  I go to "movie-corner/node/add/discussion"
    Then  I should have access to the page

  @api
  Scenario: There should be no access to 'create wiki-page' global form.
    Given I am logged in as user "isaacnewton"
    When  I go to "node/add/wiki-page"
    Then  I should not have access to the page

  @api
  Scenario: Group non member should not have access to group 'create wiki-page' form.
    Given I am logged in as user "badhairday"
    When  I go to "movie-corner/node/add/wiki-page"
    Then  I should not have access to the page

  @api
  Scenario: Group member should have access to group 'create wiki-page' form.
    Given I am logged in as user "isaacnewton"
    When  I go to "movie-corner/node/add/wiki-page"
    Then  I should have access to the page

  @api
  Scenario: There should be no access to 'create photo' global form.
    Given I am logged in as user "isaacnewton"
    When  I go to "node/add/photo"
    Then  I should not have access to the page

  @api
  Scenario: Group non member should not have access to group 'create photo' form.
    Given I am logged in as user "badhairday"
    When  I go to "movie-corner/node/add/photo"
    Then  I should not have access to the page

  @api
  Scenario: Group member should have access to group 'create photo' form.
    Given I am logged in as user "isaacnewton"
    When  I go to "movie-corner/node/add/photo"
    Then  I should have access to the page

  @api
  Scenario: There should be no access to 'create photoalbum' global form.
    Given I am logged in as user "isaacnewton"
    When  I go to "node/add/photoalbum"
    Then  I should not have access to the page

  @api
  Scenario: Group non member should not have access to group 'create photoalbum' form.
    Given I am logged in as user "badhairday"
    When  I go to "movie-corner/node/add/photoalbum"
    Then  I should not have access to the page

  @api
  Scenario: Group member should have access to group 'create photoalbum' form.
    Given I am logged in as user "isaacnewton"
    When  I go to "movie-corner/node/add/photoalbum"
    Then  I should have access to the page
