<div>
<?php
  print '<p>SERVER</p><pre>' . print_r($_SERVER, TRUE) . '</pre>';
  print '<p>REQUEST</p><pre>' . print_r($_REQUEST, TRUE) . '</pre>';
  print '<p>form_state</p><pre>' . print_r($form_state, TRUE) . '</pre>';
  print '<p>vars</p><pre>' . print_r($vars, TRUE) . '</pre>';
?>
</div>
