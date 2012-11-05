<?php
/**
 * @file
 * crf_workflow.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crf_workflow_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_workflow_default_workflows().
 */
function crf_workflow_workflow_default_workflows() {
  $workflows = array();

  // Exported workflow: CRF Workflow
  $workflows['CRF Workflow'] = array(
    'name' => 'CRF Workflow',
    'tab_roles' => '52310416,30037204',
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
        'roles' => 'workflow_features_author_name,editor,manager,administrator',
        'state' => '(creation)',
        'target_state' => 'Save Draft',
      ),
      1 => array(
        'roles' => 'workflow_features_author_name,editor,manager,administrator',
        'state' => '(creation)',
        'target_state' => 'Submit to OCHA',
      ),
      2 => array(
        'roles' => 'manager,administrator',
        'state' => '(creation)',
        'target_state' => 'Finalise',
      ),
      3 => array(
        'roles' => 'manager,administrator',
        'state' => '(creation)',
        'target_state' => 'Request Review',
      ),
      4 => array(
        'roles' => 'workflow_features_author_name,editor,manager,administrator',
        'state' => 'Save Draft',
        'target_state' => 'Submit to OCHA',
      ),
      5 => array(
        'roles' => 'manager,administrator',
        'state' => 'Save Draft',
        'target_state' => 'Finalise',
      ),
      6 => array(
        'roles' => 'manager,administrator',
        'state' => 'Save Draft',
        'target_state' => 'Request Review',
      ),
      7 => array(
        'roles' => 'manager,administrator',
        'state' => 'Submit to OCHA',
        'target_state' => 'Finalise',
      ),
      8 => array(
        'roles' => 'manager,administrator',
        'state' => 'Submit to OCHA',
        'target_state' => 'Request Review',
      ),
      9 => array(
        'roles' => 'manager,administrator',
        'state' => 'Finalise',
        'target_state' => 'Save Draft',
      ),
      10 => array(
        'roles' => 'manager,administrator',
        'state' => 'Finalise',
        'target_state' => 'Submit to OCHA',
      ),
      11 => array(
        'roles' => 'manager,administrator',
        'state' => 'Finalise',
        'target_state' => 'Request Review',
      ),
      12 => array(
        'roles' => 'workflow_features_author_name,editor,manager,administrator',
        'state' => 'Request Review',
        'target_state' => 'Submit to OCHA',
      ),
      13 => array(
        'roles' => 'manager,administrator',
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
