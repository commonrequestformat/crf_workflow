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
        { "workflow_check_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "4" : "4" } } } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_crf_req_contact" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "[node:content-type] provided for node:field-cluster:name-field in node:field-crf-request:title is now finalised",
            "message" : "Dear [node:author:name],\\r\\n\\r\\nKindly note that the [node:content-type] for node:field-cluster:name-field in the Information Request node:field-crf-request:title has been finalised.  The information can be viewed online: [node:url]\\r\\n\\r\\nNo action is required on your part at this time.\\r\\n\\r\\nKind regards,\\r\\nOCHA",
            "from" : [ "node:field-crf-req-contact:0:mail" ],
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
        { "workflow_check_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "8" : "8" } } } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_crf_req_contact" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "OCHA request information review for [node:author:name] in Request [node:field-crf-request:title]",
            "message" : "Dear [node:author:name],\\r\\n\\r\\nOCHA has reviewed your [node:content-type] submission in [node:field-crf-request:title] and has suggested some changes or a review. Kindly review the information at: [node:url].\\r\\n\\r\\nYou can choose to edit the content as well as view a comparison of historical modifications on this [node:content-type] before re-submitting it to OCHA.\\r\\n\\r\\nKind regards,\\r\\nOCHA",
            "from" : [ "node:field-crf-req-contact:0:mail" ],
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_email_ocha_focal_point_on_submission'] = entity_import('rules_config', '{ "rules_email_ocha_focal_point_on_submission" : {
      "LABEL" : "Email OCHA focal point on submission",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workflow_rules", "rules" ],
      "ON" : [ "workflow_state_changed" ],
      "IF" : [
        { "workflow_check_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "3" : "3" } } } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_crf_req_contact" } }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node-unchanged:field-crf-req-contact" ] },
            "ITEM" : { "current_contact" : "Current contact" },
            "DO" : [
              { "mail" : {
                  "to" : [ "current-contact:mail" ],
                  "subject" : "[node:content-type] provided by [node:author:name] for node:field-cluster:name-field in node:field-crf-request:title",
                  "message" : "Dear X  [where X is the manager],\\r\\n\\r\\nKindly note that [node:author:name] has uploaded a [node:content-type] for node:field-cluster:name-field in the Information Request node:field-crf-request:title to the CRF website.\\r\\n\\r\\nThe data can be reviewed at: [node:url]\\r\\n\\r\\nAt this point, we encourage you review the submission. If changes are required, you can make the necessary edits and send the information back to [node:author:name] by selecting \\u0022Request Review\\u0022. If the information is complete, you can finish the process by selecting \\u0022Finalise\\u0022\\r\\n\\r\\nKind regards.",
                  "from" : [ "node:field-crf-req-contact:0:mail" ],
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
