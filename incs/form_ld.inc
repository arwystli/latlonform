<?php
/**
 * @file form_ld.inc
 * @author Bob Hutchinson hutch@arwystli.net
 * @copyright GNU GPL
 *
 * An example structure in PHP, form
 */
 ?>

<form action="<?php print SUB_URL . '/' . $vars['page'] ?>" method="post">

  <div class="form-wrapper-ld">
    <div class="form-container-l">
      <div class="form-container-l-label" >Point one:</div>
      <div class="form-container">
        <div class="form-input-item-label" >Latitude:</div>
        <div class="form-input-item" ><input type="text" name="lat1" id="lat1" title="Please enter a latitude" autocomplete="off" /></div>
      </div>
      <div class="form-container">
        <div class="form-input-item-label" >Longitude:</div>
        <div class="form-input-item" ><input type="text" name="lon1" id="lon1" title="Please enter a longitude" autocomplete="off" /></div>
      </div>
    </div>

    <div class="form-container-r">
      <div class="form-container-r-label" >Point two:</div>
      <div class="form-container">
        <div class="form-input-item-label" >Latitude:</div>
        <div class="form-input-item" ><input type="text" name="lat2" id="lat2" title="Please enter a latitude" autocomplete="off" /></div>
      </div>
      <div class="form-container">
        <div class="form-input-item-label" >Longitude:</div>
        <div class="form-input-item" ><input type="text" name="lon2" id="lon2" title="Please enter a longitude" autocomplete="off" /></div>
      </div>
    </div>

    <div class="form-container-u">
      <div class="form-container-u-label" >Units:</div>
      <select id="unit" name="unit">
    <?php
    $units = latlonform_get_unit_names();
    foreach ($units AS $k => $v) {
      print "<option value='" . $k . "' >" . $v . "</option>";
    }
    ?>
      </select>
    </div>
    <div class="button-container-ld"><div class="button-item"><input type="submit" value="Calculate" id="fmsubmbtn" /></div></div>
    <input type="hidden" name="page" value="<?php print $vars['page']; ?>">
  </div>

</form>
