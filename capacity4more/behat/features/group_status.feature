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
  Scenario: Check deleted group as group owner
    Given I am logged in as user "alfrednobel"
    Then  I should not be allowed to edit a group "Deleted group"

  @api
  Scenario: Check group dashboard access by group owner
    Given I am logged in as user "alfrednobel"
    When  I visit the dashboard of group "Requested group"
    Then  I should see the group dashboard
    And   I visit the dashboard of group "Draft group"
    And   I should see the group dashboard
    And   I visit the dashboard of group "Published group"
    And   I should see the group dashboard
    And   I visit the dashboard of group "Archived group"
    And   I should see the group dashboard
    And   I visit the dashboard of group "Rejected group"
    And   I should see the group dashboard
    And   I visit the dashboard of group "Deleted group"
    And   I should see "Access denied"

  @api
  Scenario: Check group access by group owner
    Given I am logged in as user "alfrednobel"
    When  I visit "Requested group" node of type "group"
    Then  I should not see "Access denied"
    And   I should be allowed to edit a group "Requested group"
    And   I visit "Draft group" node of type "group"
    And   I should not see "Access denied"
    And   I should be allowed to edit a group "Draft group"
    And   I visit "Published group" node of type "group"
    And   I should not see "Access denied"
    And   I should be allowed to edit a group "Published group"
    And   I visit "Archived group" node of type "group"
    And   I should not see "Access denied"
    And   I should be allowed to edit a group "Archived group"
    And   I visit "Rejected group" node of type "group"
    And   I should not see "Access denied"
    And   I should be allowed to edit a group "Rejected group"
    And   I visit "Deleted group" node of type "group"
    And   I should see "Access denied"
    And   I should not be allowed to edit a group "Deleted group"

  @api
  Scenario: Check group access by group admin
    Given I am logged in as user "turing"
    When  I visit "Requested group" node of type "group"
    Then  I should see "Access denied"
    And   I should not be allowed to edit a group "Requested group"
    And   I visit "Draft group" node of type "group"
    And   I should not see "Access denied"
    And   I should be allowed to edit a group "Draft group"
    And   I visit "Published group" node of type "group"
    And   I should not see "Access denied"
    And   I should be allowed to edit a group "Published group"
    And   I visit "Archived group" node of type "group"
    And   I should not see "Access denied"
    And   I should be allowed to edit a group "Archived group"
    And   I visit "Rejected group" node of type "group"
    And   I should see "Access denied"
    And   I should not be allowed to edit a group "Rejected group"
    And   I visit "Deleted group" node of type "group"
    And   I should see "Access denied"
    And   I should not be allowed to edit a group "Deleted group"

  @api
  Scenario: Check group access by group member
    Given I am logged in as user "isaacnewton"
    When  I visit "Requested group" node of type "group"
    Then  I should see "Access denied"
    And   I visit "Draft group" node of type "group"
    And   I should not see "Access denied"
    And   I visit "Published group" node of type "group"
    And   I should not see "Access denied"
    And   I visit "Archived group" node of type "group"
    And   I should not see "Access denied"
    And   I visit "Rejected group" node of type "group"
    And   I should see "Access denied"
    And   I visit "Deleted group" node of type "group"
    And   I should see "Access denied"

  @api
  Scenario: Check group access by not member
    Given I am logged in as user "president"
    When  I visit "Requested group" node of type "group"
    Then  I should see "Access denied"
    And   I visit "Draft group" node of type "group"
    And   I should see "Access denied"
    And   I visit "Published group" node of type "group"
    And   I should not see "Access denied"
    And   I visit "Archived group" node of type "group"
    And   I should not see "Access denied"
    And   I visit "Rejected group" node of type "group"
    And   I should see "Access denied"
    And   I visit "Deleted group" node of type "group"
    And   I should see "Access denied"

  @api
  Scenario: Check group access by anonymous user
    Given I am an anonymous user
    When  I visit "Requested group" node of type "group"
    Then  I should see "Access denied"
    And   I visit "Draft group" node of type "group"
    And   I should see "Access denied"
    And   I visit "Published group" node of type "group"
    And   I should not see "Access denied"
    And   I visit "Archived group" node of type "group"
    And   I should not see "Access denied"
    And   I visit "Rejected group" node of type "group"
    And   I should see "Access denied"
    And   I visit "Deleted group" node of type "group"
    And   I should see "Access denied"
