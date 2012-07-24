<?php

/**
 * @file
 * amdin configuration for jglidemenu
 */
 
 /**
 * Settings form as implemented by hook_menu
 */
function jglidemenu_admin_settings($form, &$form_state) {
  $form['jglidemenu_number'] = array(
    '#type' => 'textfield',
    '#description' => t('The total number of independent jglidemenu blocks you want. Enter a number between 0 and 99. If you set this to 0, you will have no blocks created but you can still use the jglidemenu theme functions directly in your theme.'),
    '#default_value' => variable_get('jglidemenu_number', '2'),
    '#size' => 2,
  );
  $form['jglidemenu_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced options'),
    '#description' => t('You can change the default options by filling out the desired values here.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['jglidemenu_options']['scrollspeed'] = array(
    '#type' => 'textfield',
    '#title' => t('scrollspeed'),
    '#description' => t('The scrollspeed in milliseconds when tiles sliede horizontally.'),
    '#default_value' => variable_get('jglidemenu_scrollspeed', 750),
    '#size' => 5,
  );
  $form['jglidemenu_options']['verticalscroll'] = array(
    '#type' => 'select',
    '#title' => t('Animation speed'),
    '#multiple' => FALSE,
    '#description' => t('Speed of the menu scroll vertically.'),
    '#options' => array(
      'slow' => t('slow'),
      'normal' => t('normal'),
      'fast' => t('fast'),
    ),
    '#default_value' => variable_get('jglidemenu_verticalscroll', 'normal'),
  );

  // Custom validation to make sure the user is entering numbers.
  $form['#validate'][] = 'jglidemenu_settings_validate';
  // $menu = menu_navigation_links('navigation');
  // echo '<pre>',' menu_navigation_links is',  print_r($menu),'</pre>';
  //  //$temp = drupal_render($menu);
  // $menu = menu_tree('main-menu');
  // echo '<pre>',' menu tree is',  print_r($menu),'</pre>';
  // $rendermenu = render($menu);
  // print $rendermenu;

   //  $main_menu = menu_tree_all_data('main-menu');
   //  echo '<pre>',' menu tree all data  is bb',  print_r($main_menu),'</pre>';
   // $page_menu = menu_tree_page_data('main-menu');
   // echo '<pre>',' menu tree page data  is bb',  print_r($page_menu),'</pre>';
   // $trail = jglidemenu_build_page_trail($page_menu);
   // echo '<pre> build page trail',  print_r($trail),'</pre>';
  return system_settings_form($form);
}

/**
 * Custom validation for the settings form.
 */
function jglidemenu_settings_validate($form, &$form_state) {
  $number = $form_state['values']['jglidemenu_number'];
  // Check to make sure it is a number and that is a maximum of 2 digits.
  if (!is_numeric($number) || strlen($number) > 2) {
    form_set_error('jglidemenu_number', t('You must enter a number from 0 to 99.'));
  }
}

?>