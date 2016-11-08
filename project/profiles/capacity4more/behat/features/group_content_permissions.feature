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
  Scenario: Group owner should not have access to group 'create wiki-page' form.
    Given I am logged in as user "alfrednobel"
    When  I go to "nobelprize/node/add/wiki-page"
    Then  I should have access to the page

  @api
  Scenario: Group admin should have access to group 'create wiki-page' form.
    Given I am logged in as user "galileo"
    When  I go to "nobelprize/node/add/wiki-page"
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

  @dev
  Scenario Outline: Access create content form, without purl prefix.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /node/add/photoalbum |
      | turing      | /node/add/photoalbum |
      | galileo     | /node/add/photoalbum |
      | alfrednobel | /node/add/photoalbum |
      | mariecurie  | /node/add/photoalbum |
      | badhairday  | /node/add/photo |
      | turing      | /node/add/photo |
      | galileo     | /node/add/photo |
      | alfrednobel | /node/add/photo |
      | mariecurie  | /node/add/photo |
      | badhairday  | /node/add/event |
      | turing      | /node/add/event |
      | galileo     | /node/add/event |
      | alfrednobel | /node/add/event |
      | mariecurie  | /node/add/event |
      | badhairday  | /node/add/document |
      | turing      | /node/add/document |
      | galileo     | /node/add/document |
      | alfrednobel | /node/add/document |
      | mariecurie  | /node/add/document |
      | badhairday  | /node/add/discussion |
      | turing      | /node/add/discussion |
      | galileo     | /node/add/discussion |
      | alfrednobel | /node/add/discussion |
      | mariecurie  | /node/add/discussion |

  @dev
  Scenario: Set "Nobel Prize" group state to 'Public'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When  I change access of group "Nobel Prize" to "Public"
    Then  I am an anonymous user
    And I go to "nobelprize"
    And I should see "Please log in"

  @dev
  Scenario Outline: As site admin, access create content form, with purl prefix of pending public group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should have access to the page

    Examples:
      | user        | path                 |
      | mariecurie  | /nobelprize/node/add/photoalbum |
      | mariecurie  | /nobelprize/node/add/photo |
      | mariecurie  | /nobelprize/node/add/event |
      | mariecurie  | /nobelprize/node/add/document |
      | mariecurie  | /nobelprize/node/add/discussion |

  @dev
  Scenario Outline: As non member, member, group admin and group owner, access create content form, with purl prefix of pending public group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /nobelprize/node/add/photoalbum |
      | turing      | /nobelprize/node/add/photoalbum |
      | galileo     | /nobelprize/node/add/photoalbum |
      | alfrednobel | /nobelprize/node/add/photoalbum |
      | badhairday  | /nobelprize/node/add/photo |
      | turing      | /nobelprize/node/add/photo |
      | galileo     | /nobelprize/node/add/photo |
      | alfrednobel | /nobelprize/node/add/photo |
      | badhairday  | /nobelprize/node/add/event |
      | turing      | /nobelprize/node/add/event |
      | galileo     | /nobelprize/node/add/event |
      | alfrednobel | /nobelprize/node/add/event |
      | badhairday  | /nobelprize/node/add/document |
      | turing      | /nobelprize/node/add/document |
      | galileo     | /nobelprize/node/add/document |
      | alfrednobel | /nobelprize/node/add/document |
      | badhairday  | /nobelprize/node/add/discussion |
      | turing      | /nobelprize/node/add/discussion |
      | galileo     | /nobelprize/node/add/discussion |
      | alfrednobel | /nobelprize/node/add/discussion |

  @dev
  Scenario: Set "Nobel Prize" group state to 'Restricted'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When  I change access of group "Nobel Prize" to "Restricted"
    Then  I am an anonymous user
    And I go to "nobelprize"
    And I should see "Please log in"

  @dev
  Scenario Outline: As site admin, access create content form, with purl prefix of pending restricted group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should have access to the page

    Examples:
      | user        | path                 |
      | mariecurie  | /nobelprize/node/add/photoalbum |
      | mariecurie  | /nobelprize/node/add/photo |
      | mariecurie  | /nobelprize/node/add/event |
      | mariecurie  | /nobelprize/node/add/document |
      | mariecurie  | /nobelprize/node/add/discussion |

  @dev
  Scenario Outline: As non member, member, group admin and group owner, access create content form, with purl prefix of pending restricted group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /nobelprize/node/add/photoalbum |
      | turing      | /nobelprize/node/add/photoalbum |
      | galileo     | /nobelprize/node/add/photoalbum |
      | alfrednobel | /nobelprize/node/add/photoalbum |
      | badhairday  | /nobelprize/node/add/photo |
      | turing      | /nobelprize/node/add/photo |
      | galileo     | /nobelprize/node/add/photo |
      | alfrednobel | /nobelprize/node/add/photo |
      | badhairday  | /nobelprize/node/add/event |
      | turing      | /nobelprize/node/add/event |
      | galileo     | /nobelprize/node/add/event |
      | alfrednobel | /nobelprize/node/add/event |
      | badhairday  | /nobelprize/node/add/document |
      | turing      | /nobelprize/node/add/document |
      | galileo     | /nobelprize/node/add/document |
      | alfrednobel | /nobelprize/node/add/document |
      | badhairday  | /nobelprize/node/add/discussion |
      | turing      | /nobelprize/node/add/discussion |
      | galileo     | /nobelprize/node/add/discussion |
      | alfrednobel | /nobelprize/node/add/discussion |

  @dev
  Scenario: Set "Nobel Prize" group state to 'Private'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When  I change access of group "Nobel Prize" to "Private"
    Then  I am an anonymous user
    And I go to "nobelprize"
    And I should see "Please log in"

  @dev
  Scenario Outline: As site admin, access create content form, with purl prefix of pending private group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should have access to the page

    Examples:
      | user        | path                 |
      | mariecurie  | /nobelprize/node/add/photoalbum |
      | mariecurie  | /nobelprize/node/add/photo |
      | mariecurie  | /nobelprize/node/add/event |
      | mariecurie  | /nobelprize/node/add/document |
      | mariecurie  | /nobelprize/node/add/discussion |

  @dev
  Scenario Outline: As non member, member, group admin and group owner, access create content form, with purl prefix of pending private group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /nobelprize/node/add/photoalbum |
      | turing      | /nobelprize/node/add/photoalbum |
      | galileo     | /nobelprize/node/add/photoalbum |
      | alfrednobel | /nobelprize/node/add/photoalbum |
      | badhairday  | /nobelprize/node/add/photo |
      | turing      | /nobelprize/node/add/photo |
      | galileo     | /nobelprize/node/add/photo |
      | alfrednobel | /nobelprize/node/add/photo |
      | badhairday  | /nobelprize/node/add/event |
      | turing      | /nobelprize/node/add/event |
      | galileo     | /nobelprize/node/add/event |
      | alfrednobel | /nobelprize/node/add/event |
      | badhairday  | /nobelprize/node/add/document |
      | turing      | /nobelprize/node/add/document |
      | galileo     | /nobelprize/node/add/document |
      | alfrednobel | /nobelprize/node/add/document |
      | badhairday  | /nobelprize/node/add/discussion |
      | turing      | /nobelprize/node/add/discussion |
      | galileo     | /nobelprize/node/add/discussion |
      | alfrednobel | /nobelprize/node/add/discussion |

  @dev
  Scenario: Change "Nobel Prize" group state to Draft.
    Given  I am logged in as user "mariecurie"
    When  The group "Nobel Prize" status is changed by admin to "Draft"
    Then  I should have access to the page

  @dev-wip
  Scenario: Set "Nobel Prize" group state to 'Public'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When  I change access of group "Nobel Prize" to "Public"
    Then  I am an anonymous user
    And I go to "nobelprize"
    And I should see "Please log in"

  @dev-wip
  Scenario Outline: As member, group admin, group owner and site admin, access create content form, with purl prefix of draft public group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should have access to the page

    Examples:
      | user        | path                 |
      | turing  | /nobelprize/node/add/photoalbum |
      | turing  | /nobelprize/node/add/photo |
      | turing  | /nobelprize/node/add/event |
      | turing  | /nobelprize/node/add/document |
      | turing  | /nobelprize/node/add/discussion |
      | galileo  | /nobelprize/node/add/photoalbum |
      | galileo  | /nobelprize/node/add/photo |
      | galileo  | /nobelprize/node/add/event |
      | galileo  | /nobelprize/node/add/document |
      | galileo  | /nobelprize/node/add/discussion |
      | galileo  | /nobelprize/node/add/photoalbum |
      | alfrednobel  | /nobelprize/node/add/photo |
      | alfrednobel  | /nobelprize/node/add/event |
      | alfrednobel  | /nobelprize/node/add/document |
      | alfrednobel  | /nobelprize/node/add/discussion |
      | mariecurie  | /nobelprize/node/add/photoalbum |
      | mariecurie  | /nobelprize/node/add/photo |
      | mariecurie  | /nobelprize/node/add/event |
      | mariecurie  | /nobelprize/node/add/document |
      | mariecurie  | /nobelprize/node/add/discussion |

  @dev-wip
  Scenario Outline: As non member, access create content form, with purl prefix of draft public group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /nobelprize/node/add/photoalbum |
      | badhairday  | /nobelprize/node/add/photo |
      | badhairday  | /nobelprize/node/add/event |
      | badhairday  | /nobelprize/node/add/document |
      | badhairday  | /nobelprize/node/add/discussion |

  @dev-wip
  Scenario: Set "Nobel Prize" group state to 'Restricted'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When  I change access of group "Nobel Prize" to "Restricted"
    Then  I am an anonymous user
    And I go to "nobelprize"
    And I should see "Please log in"

  @dev-wip
  Scenario Outline:  As member, group admin, group owner and site admin, access create content form, with purl prefix of draft restricted group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should have access to the page

    Examples:
      | user        | path                 |
      | turing  | /nobelprize/node/add/photoalbum |
      | turing  | /nobelprize/node/add/photo |
      | turing  | /nobelprize/node/add/event |
      | turing  | /nobelprize/node/add/document |
      | turing  | /nobelprize/node/add/discussion |
      | galileo  | /nobelprize/node/add/photoalbum |
      | galileo  | /nobelprize/node/add/photo |
      | galileo  | /nobelprize/node/add/event |
      | galileo  | /nobelprize/node/add/document |
      | galileo  | /nobelprize/node/add/discussion |
      | galileo  | /nobelprize/node/add/photoalbum |
      | alfrednobel  | /nobelprize/node/add/photo |
      | alfrednobel  | /nobelprize/node/add/event |
      | alfrednobel  | /nobelprize/node/add/document |
      | alfrednobel  | /nobelprize/node/add/discussion |
      | mariecurie  | /nobelprize/node/add/photoalbum |
      | mariecurie  | /nobelprize/node/add/photo |
      | mariecurie  | /nobelprize/node/add/event |
      | mariecurie  | /nobelprize/node/add/document |
      | mariecurie  | /nobelprize/node/add/discussion |

  @dev-wip
  Scenario Outline: As non member, access create content form, with purl prefix of draft restricted group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /nobelprize/node/add/photoalbum |
      | badhairday  | /nobelprize/node/add/photo |
      | badhairday  | /nobelprize/node/add/event |
      | badhairday  | /nobelprize/node/add/document |
      | badhairday  | /nobelprize/node/add/discussion |

  @dev-wip
  Scenario: Set "Nobel Prize" group state to 'Private'. Anonymous user asked to log in.
    Given  I am logged in as user "mariecurie"
    When  I change access of group "Nobel Prize" to "Private"
    Then  I am an anonymous user
    And I go to "nobelprize"
    And I should see "Please log in"

  @dev-wip
  Scenario Outline: As member, group admin, group owner and site admin, access create content form, with purl prefix of draft private group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should have access to the page

    Examples:
      | user        | path                 |
      | turing  | /nobelprize/node/add/photoalbum |
      | turing  | /nobelprize/node/add/photo |
      | turing  | /nobelprize/node/add/event |
      | turing  | /nobelprize/node/add/document |
      | turing  | /nobelprize/node/add/discussion |
      | galileo  | /nobelprize/node/add/photoalbum |
      | galileo  | /nobelprize/node/add/photo |
      | galileo  | /nobelprize/node/add/event |
      | galileo  | /nobelprize/node/add/document |
      | galileo  | /nobelprize/node/add/discussion |
      | galileo  | /nobelprize/node/add/photoalbum |
      | alfrednobel  | /nobelprize/node/add/photo |
      | alfrednobel  | /nobelprize/node/add/event |
      | alfrednobel  | /nobelprize/node/add/document |
      | alfrednobel  | /nobelprize/node/add/discussion |
      | mariecurie  | /nobelprize/node/add/photoalbum |
      | mariecurie  | /nobelprize/node/add/photo |
      | mariecurie  | /nobelprize/node/add/event |
      | mariecurie  | /nobelprize/node/add/document |
      | mariecurie  | /nobelprize/node/add/discussion |

  @dev-wip
  Scenario Outline: As non member, access create content form, with purl prefix of draft private group.
    Given  I am logged in as user "<user>"
    When  I go to "<path>"
    Then  I should not have access to the page

    Examples:
      | user        | path                 |
      | badhairday  | /nobelprize/node/add/photoalbum |
      | badhairday  | /nobelprize/node/add/photo |
      | badhairday  | /nobelprize/node/add/event |
      | badhairday  | /nobelprize/node/add/document |
      | badhairday  | /nobelprize/node/add/discussion |
