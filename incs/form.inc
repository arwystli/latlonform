<?php
/**
 * @file form.inc
 * @author Bob Hutchinson hutch@arwystli.net
 * @copyright GNU GPL
 *
 * An example structure in PHP, form
 */
 ?>

<form action="<?php print SUB_URL . '/' . $vars['page'] ?>" method="post">
  <div class="form-container">
    <div class="form-input-item-label" >Latitude:</div>
    <div class="form-input-item" ><input type="text" name="lat" id="lat" title="Please enter a latitude" autocomplete="off" /></div>
  </div>

  <div class="form-container">
    <div class="form-input-item-label" >Longitude:</div>
    <div class="form-input-item" ><input type="text" name="lon" id="lon" title="Please enter a longitude" autocomplete="off" /></div>
  </div>

  <input type="hidden" name="page" value="<?php print $vars['page']; ?>">
  <div class="button-container"><div class="button-item"><input type="submit" value="Go" id="fmsubmbtn" /></div></div>
</form>
