<?php
/**
 * @file
 * Default rules
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_civicrm_default_rules_configuration() {
  // Default configuration to add a purchase.
  $rule = rules_reaction_rule();
  $rule->label = t('Add to CiviCRM on new order');
  $rule->active = TRUE;
  $rule->event('commerce_checkout_complete');
  $rule->action('commerce_civicrm_create_order_civicrm', array('commerce_order:select' => 'commerce-order'));
  $configs['commerce_civicrm_contact_on_order'] = $rule;

  // configuration to update civicrm contribution when updating an order
  $rule = rules_reaction_rule();
  $rule->label = t('Update CiviCRM contribution when updating the order');
  $rule->active = TRUE;
  $rule->event('commerce_order_update');
  $rule->action('commerce_civicrm_update_order_civicrm', array('commerce_order:select' => 'commerce-order'));
  $configs['commerce_civicrm_update_order'] = $rule;


  return $configs;
}
