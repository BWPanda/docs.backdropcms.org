<?php

/**
 * @file
 * Defines a handler for documentation fields for API documentation.
 */

/**
 * Handles documentation fields for API documetation.
 *
 * Formats the fields as documentation.
 */
class api_views_handler_field_api_docs extends views_handler_field {

  /**
   * Overrides views_handler_field::init().
   *
   * Adds additional database fields that we need for formatting.
   */
  function init(&$view, &$options) {
    parent::init($view, $options);
    // Make sure we have the information we need.
    $this->additional_fields['branch_id'] = array('table' => 'api_documentation', 'field' => 'branch_id');
    $this->additional_fields['class_did'] = array('table' => 'api_documentation', 'field' => 'class_did');
    $this->additional_fields['is_backdrop'] = array('table' => 'api_documentation', 'field' => 'is_backdrop');
  }

  /**
   * Overrides views_handler_field::render().
   */
  function render($values) {
    module_load_include('inc', 'api', 'api.formatting');
    $doc = $this->get_value($values);
    $branch_id = $this->get_value($values, 'branch_id');
    $branch = api_get_branch_by_id($branch_id);
    return api_link_documentation($doc, $branch, NULL, $this->get_value($values, 'class_did'), FALSE, FALSE, $this->get_value($values, 'is_backdrop'));
  }
}
