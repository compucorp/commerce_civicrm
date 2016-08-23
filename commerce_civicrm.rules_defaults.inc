<?php
/**
 * @file
 * Default rules
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_civicrm_default_rules_configuration() {
  $rule = rules_reaction_rule();
  $rule->label = t('checkout complete rule');
  $rule->active = TRUE;
  $rule->event('commerce_checkout_complete');
  $rule->action('commerce_civicrm_action_checkout_complete', array('commerce_order:select' => 'commerce-order'));
  $configs['commerce_civicrm_checkout_complete'] = $rule;

  $rule = rules_reaction_rule();
  $rule->label = t('order update rule');
  $rule->active = TRUE;
  $rule->event('commerce_order_update');
  $rule->action('commerce_civicrm_action_order_update', array('commerce_order:select' => 'commerce-order'));
  $configs['commerce_civicrm_order_update'] = $rule;

  $rule = rules_reaction_rule();
  $rule->label = t('order delete rule');
  $rule->active = TRUE;
  $rule->event('commerce_order_delete');
  $rule->action('commerce_civicrm_action_order_delete', array('commerce_order:select' => 'commerce-order'));
  $configs['commerce_civicrm_order_delete'] = $rule;

  $rule = rules_reaction_rule();
  $rule->label = t('product insert rule');
  $rule->active = TRUE;
  $rule->event('commerce_product_insert');
  $rule->action('commerce_civicrm_action_product_insert', array('commerce_product:select' => 'commerce-product'));
  $configs['commerce_civicrm_product_insert'] = $rule;

  $rule = rules_reaction_rule();
  $rule->label = t('product update rule');
  $rule->active = TRUE;
  $rule->event('commerce_product_update');
  $rule->action('commerce_civicrm_action_product_update', array('commerce_product:select' => 'commerce-product'));
  $configs['commerce_civicrm_product_update'] = $rule;

  $rule = rules_reaction_rule();
  $rule->label = t('product delete rule');
  $rule->active = TRUE;
  $rule->event('commerce_product_delete');
  $rule->action('commerce_civicrm_action_product_delete', array('commerce_product:select' => 'commerce-product'));
  $configs['commerce_civicrm_product_delete'] = $rule;

  return $configs;
}
