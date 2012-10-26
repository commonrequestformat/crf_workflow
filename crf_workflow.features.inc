<?php
/**
 * @file
 * crf_workflow.features.inc
 */

/**
 * Implements hook_workflow_default_workflows().
 */
function crf_workflow_workflow_default_workflows() {
  $workflows = array();

  // Exported workflow: CRF Workflow
  $workflows['CRF Workflow'] = array(
    'name' => 'CRF Workflow',
    'tab_roles' => '',
    'options' => 'a:3:{s:16:"comment_log_node";i:0;s:15:"comment_log_tab";i:0;s:13:"name_as_title";i:0;}',
    'states' => array(
      0 => array(
        'state' => '(creation)',
        'weight' => '-50',
        'sysid' => '1',
        'status' => '1',
      ),
      1 => array(
        'state' => 'Save Draft',
        'weight' => '0',
        'sysid' => '0',
        'status' => '1',
      ),
      2 => array(
        'state' => 'Submit to OCHA',
        'weight' => '0',
        'sysid' => '0',
        'status' => '1',
      ),
      3 => array(
        'state' => 'Finalise',
        'weight' => '0',
        'sysid' => '0',
        'status' => '1',
      ),
      4 => array(
        'state' => 'Request Review',
        'weight' => '0',
        'sysid' => '0',
        'status' => '1',
      ),
    ),
    'transitions' => array(
      0 => array(
        'roles' => 'workflow_features_author_name',
        'state' => '(creation)',
        'target_state' => 'Save Draft',
      ),
      1 => array(
        'roles' => 'workflow_features_author_name',
        'state' => '(creation)',
        'target_state' => 'Submit to OCHA',
      ),
      2 => array(
        'roles' => 'workflow_features_author_name',
        'state' => 'Save Draft',
        'target_state' => 'Submit to OCHA',
      ),
      3 => array(
        'roles' => 'administrator',
        'state' => 'Submit to OCHA',
        'target_state' => 'Save Draft',
      ),
      4 => array(
        'roles' => 'administrator',
        'state' => 'Submit to OCHA',
        'target_state' => 'Finalise',
      ),
      5 => array(
        'roles' => 'administrator',
        'state' => 'Submit to OCHA',
        'target_state' => 'Request Review',
      ),
      6 => array(
        'roles' => 'administrator',
        'state' => 'Finalise',
        'target_state' => 'Save Draft',
      ),
      7 => array(
        'roles' => 'administrator',
        'state' => 'Finalise',
        'target_state' => 'Submit to OCHA',
      ),
      8 => array(
        'roles' => 'administrator',
        'state' => 'Finalise',
        'target_state' => 'Request Review',
      ),
      9 => array(
        'roles' => 'workflow_features_author_name,administrator',
        'state' => 'Request Review',
        'target_state' => 'Submit to OCHA',
      ),
      10 => array(
        'roles' => 'administrator',
        'state' => 'Request Review',
        'target_state' => 'Finalise',
      ),
    ),
    'node_types' => array(
      0 => 'assessments_batch',
      1 => 'hr_sitrep',
      2 => 'indicator_data_batch',
      3 => 'sectoral_analysis',
    ),
  );

  return $workflows;
}
