Feature: Group Status
  Test group status field

  @api
  Scenario: Check requested group as admin
    Given I am logged in as user "mariecurie"
    When  I start editing group "Requested group"
    Then  the "#edit-c4m-og-status-und" element should not contain "archived"
    And   the "#edit-c4m-og-status-und" element should not contain "published"

  @api
  Scenario: Check requested group as group owner
    Given I am logged in as user "alfrednobel"
    When  I start editing group "Requested group"
    Then  the "#edit-c4m-og-status-und" element should not contain "rejected"
    And   the "#edit-c4m-og-status-und" element should not contain "draft"
    And   the "#edit-c4m-og-status-und" element should not contain "published"
    And   the "#edit-c4m-og-status-und" element should not contain "archived"

  @api
  Scenario: Check rejected group group as admin
    Given I am logged in as user "mariecurie"
    When  I start editing group "Rejected group"
    Then  the "#edit-c4m-og-status-und" element should not contain "requested"
    And   the "#edit-c4m-og-status-und" element should not contain "draft"
    And   the "#edit-c4m-og-status-und" element should not contain "published"
    And   the "#edit-c4m-og-status-und" element should not contain "archived"

  @api
  Scenario: Check rejected group group as group owner
    Given I am logged in as user "alfrednobel"
    When  I start editing group "Rejected group"
    Then  I should not see an "#edit-c4m-og-status-und" element

  @api
  Scenario: Check draft group as admin
    Given I am logged in as user "mariecurie"
    When  I start editing group "Draft group"
    Then  the "#edit-c4m-og-status-und" element should not contain "archived"
    And   the "#edit-c4m-og-status-und" element should not contain "rejected"
    And   the "#edit-c4m-og-status-und" element should not contain "requested"

  @api
  Scenario: Check draft group as group owner
    Given I am logged in as user "alfrednobel"
    When  I start editing group "Draft group"
    Then  the "#edit-c4m-og-status-und" element should not contain "rejected"
    And   the "#edit-c4m-og-status-und" element should not contain "requested"
    And   the "#edit-c4m-og-status-und" element should not contain "archived"

  @api
  Scenario: Check published group as admin
    Given I am logged in as user "mariecurie"
    When  I start editing group "Published group"
    Then  the "#edit-c4m-og-status-und" element should not contain "rejected"
    And   the "#edit-c4m-og-status-und" element should not contain "requested"

  @api
  Scenario: Check published group as group owner
    Given I am logged in as user "alfrednobel"
    When  I start editing group "Published group"
    Then  the "#edit-c4m-og-status-und" element should not contain "rejected"
    And   the "#edit-c4m-og-status-und" element should not contain "requested"
    And   the "#edit-c4m-og-status-und" element should not contain "draft"

  @api
  Scenario: Check archived group as admin
    Given I am logged in as user "mariecurie"
    When  I start editing group "Archived group"
    Then  the "#edit-c4m-og-status-und" element should not contain "rejected"
    And   the "#edit-c4m-og-status-und" element should not contain "requested"
    And   the "#edit-c4m-og-status-und" element should not contain "draft"

  @api
  Scenario: Check archived group as group owner
    Given I am logged in as user "alfrednobel"
    When  I start editing group "Archived group"
    Then  I should not see an "#edit-c4m-og-status-und" element

  @api
  Scenario: Check deleted group as admin
    Given I am logged in as user "mariecurie"
    When  I start editing group "Deleted group"
    Then  the "#edit-c4m-og-status-und" element should not contain "rejected"
    And   the "#edit-c4m-og-status-und" element should not contain "requested"

  @api
  Scenario: Check Requested group access by group owner
    Given I am logged in as user "alfrednobel"
    When  I visit the dashboard of group "Requested group"
    Then  I should see "User account"

  @api
  Scenario: Check Draft group dashboard access by group owner
    Given I am logged in as user "alfrednobel"
    When  I visit the dashboard of group "Draft group"
    Then  I should have access to the page
    And   I visit "Draft group" node of type "group"
    And   I should not see "User account"
    And   I should be allowed to edit a group "Draft group"

  @api
  Scenario: Check Published group dashboard access by group owner
    Given I am logged in as user "alfrednobel"
    When  I visit the dashboard of group "Published group"
    Then  I should have access to the page
    And   I visit "Published group" node of type "group"
    And   I should not see "User account"
    And   I should be allowed to edit a group "Published group"

  @api
  Scenario: Check Archived group dashboard access by group owner
    Given I am logged in as user "alfrednobel"
    When  I visit the dashboard of group "Archived group"
    Then  I should have access to the page
    And   I visit "Archived group" node of type "group"
    And   I should not see "User account"
    And   I should be allowed to edit a group "Archived group"

  @api
  Scenario: Check Rejected group dashboard access by group owner
    Given I am logged in as user "alfrednobel"
    When  I visit the dashboard of group "Rejected group"
    Then  I should see "User account"

  @api
  Scenario: Check Deleted group dashboard access by group owner
    Given I am logged in as user "alfrednobel"
    When  I visit the dashboard of group "Deleted group"
    Then  I should see "User account"

  @api
  Scenario: Check Requested group access by group admin
    Given I am logged in as user "turing"
    When  I visit "Requested group" node of type "group"
    Then  I should see "User account"

  @api
  Scenario: Check Draft group access by group admin
    Given I am logged in as user "turing"
    When  I visit "Draft group" node of type "group"
    Then  I should not see "User account"
    And   I should be allowed to edit a group "Draft group"

  @api
  Scenario: Check Published group access by group admin
    Given I am logged in as user "turing"
    When  I visit "Published group" node of type "group"
    Then  I should not see "User account"
    And   I should be allowed to edit a group "Published group"

  @api
  Scenario: Check Archived group access by group admin
    Given I am logged in as user "turing"
    When  I visit "Archived group" node of type "group"
    Then  I should not see "User account"
    And   I should be allowed to edit a group "Archived group"

  @api
  Scenario: Check Rejected group access by group admin
    Given I am logged in as user "turing"
    When  I visit "Rejected group" node of type "group"
    Then  I should see "User account"

  @api
  Scenario: Check Deleted group access by group admin
    Given I am logged in as user "turing"
    When  I visit "Deleted group" node of type "group"
    Then  I should see "User account"

  @api
  Scenario: Check Requested group access by group member
    Given I am logged in as user "isaacnewton"
    When  I visit "Requested group" node of type "group"
    Then  I should see "User account"

  @api
  Scenario: Check Draft group access by group member
    Given I am logged in as user "isaacnewton"
    When  I visit "Draft group" node of type "group"
    Then  I should not see "User account"
    And   I should not be allowed to edit a group "Draft group"

  @api
  Scenario: Check Published group access by group member
    Given I am logged in as user "isaacnewton"
    When  I visit "Published group" node of type "group"
    Then  I should not see "User account"
    And   I should not be allowed to edit a group "Published group"

  @api
  Scenario: Check Archived group access by group member
    Given I am logged in as user "isaacnewton"
    When  I visit "Archived group" node of type "group"
    Then  I should not see "User account"
    And   I should not be allowed to edit a group "Archived group"

  @api
  Scenario: Check Rejected group access by group member
    Given I am logged in as user "isaacnewton"
    When  I visit "Rejected group" node of type "group"
    Then  I should see "User account"

  @api
  Scenario: Check Deleted group access by group member
    Given I am logged in as user "isaacnewton"
    When  I visit "Deleted group" node of type "group"
    Then  I should see "User account"

  @api
  Scenario: Check Requested group access by not member
    Given I am logged in as user "president"
    When  I visit "Requested group" node of type "group"
    Then  I should see "User account"

  @api
  Scenario: Check Draft group access by not member
    Given I am logged in as user "president"
    When  I visit "Draft group" node of type "group"
    Then  I should see "User account"

  @api
  Scenario: Check Published group access by not member
    Given I am logged in as user "president"
    When  I visit "Published group" node of type "group"
    Then  I should not see "User account"
    And   I should not be allowed to edit a group "Published group"

  @api
  Scenario: Check Archived group access by not member
    Given I am logged in as user "president"
    When  I visit "Archived group" node of type "group"
    Then  I should not see "User account"
    And   I should not be allowed to edit a group "Archived group"

  @api
  Scenario: Check Rejected group access by not member
    Given I am logged in as user "president"
    When  I visit "Rejected group" node of type "group"
    Then  I should see "User account"

  @api
  Scenario: Check Deleted group access by not member
    Given I am logged in as user "president"
    When  I visit "Deleted group" node of type "group"
    Then  I should see "User account"

  @api
  Scenario: Check Requested group access by anonymous user
    Given I am an anonymous user
    When  I visit "Requested group" node of type "group"
    Then  I should see "User account"

  @api
  Scenario: Check Draft group access by anonymous user
    Given I am an anonymous user
    When  I visit "Draft group" node of type "group"
    Then  I should see "User account"

  @api
  Scenario: Check Published group access by anonymous user
    Given I am an anonymous user
    When  I visit "Published group" node of type "group"
    Then  I should not see "User account"
    And   I should not be allowed to edit a group "Published group"

  @api
  Scenario: Check Archived group access by anonymous user
    Given I am an anonymous user
    When  I visit "Archived group" node of type "group"
    Then  I should not see "User account"
    And   I should not be allowed to edit a group "Archived group"

  @api
  Scenario: Check Rejected group access by anonymous user
    Given I am an anonymous user
    When  I visit "Rejected group" node of type "group"
    Then  I should see "User account"

  @api
  Scenario: Check Deleted group access by anonymous user
    Given I am an anonymous user
    When  I visit "Deleted group" node of type "group"
    Then  I should see "User account"
