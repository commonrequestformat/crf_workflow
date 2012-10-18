<?php
/**
 * @file
 * crf_workflow.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function crf_workflow_user_default_permissions() {
  $permissions = array();

  // Exported permission: access workflow summary views.
  $permissions['access workflow summary views'] = array(
    'name' => 'access workflow summary views',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
      3 => 'trusted',
    ),
    'module' => 'workflow_views',
  );

  // Exported permission: administer workflow.
  $permissions['administer workflow'] = array(
    'name' => 'administer workflow',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'workflow_admin_ui',
  );

  // Exported permission: schedule workflow transitions.
  $permissions['schedule workflow transitions'] = array(
    'name' => 'schedule workflow transitions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'workflow',
  );

  return $permissions;
}
