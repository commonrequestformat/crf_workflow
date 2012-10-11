<?php
/**
 * @file
 * crf_workflow.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function crf_workflow_default_rules_configuration() {
  $items = array();
  $items['rules_email_information_focal_point_on_approval'] = entity_import('rules_config', '{ "rules_email_information_focal_point_on_approval" : {
      "LABEL" : "Email information focal point on approval",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workflow_rules", "rules" ],
      "ON" : [ "workflow_state_changed" ],
      "IF" : [
        { "workflow_check_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "4" : "4" } } } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "Your submission \\u0022[node:title]\\u0022 has been approved.",
            "message" : "Your submission \\u0022[node:title]\\u0022 has been approved.",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_email_information_focal_point_on_needs_work'] = entity_import('rules_config', '{ "rules_email_information_focal_point_on_needs_work" : {
      "LABEL" : "Email information focal point on needs work",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workflow_rules", "rules" ],
      "ON" : [ "workflow_state_changed" ],
      "IF" : [
        { "workflow_check_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "8" : "8" } } } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "Your submission \\u0022[node:title]\\u0022 needs work.",
            "message" : "Your submission \\u0022[node:title]\\u0022 needs work.",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_email_manager_on_submission'] = entity_import('rules_config', '{ "rules_email_manager_on_submission" : {
      "LABEL" : "Email manager on submission",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workflow_rules", "rules" ],
      "ON" : [ "workflow_state_changed" ],
      "IF" : [
        { "workflow_check_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "3" : "3" } } } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "4" : "4" } },
            "subject" : "New submission",
            "message" : "The [node:content-type] item \\u0022[node:title]\\u0022 got submiited."
          }
        }
      ]
    }
  }');
  return $items;
}
