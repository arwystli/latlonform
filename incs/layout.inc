<?php
/**
 * @file layout.inc
 * @author Bob Hutchinson hutch@arwystli.net
 * @copyright GNU GPL
 *
 * An example structure in PHP, manage site layout
 */
?>
<!DOCTYPE html>
<html lang="<?php print $vars['lang']; ?>" dir="ltr">
  <head>
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, user-scalable=no, initial-scale=1.0, minimum-scale=1.0, maximum-scale=1.0">
    <title><?php print $vars['headertitle']; ?></title>
    <link type="text/css" rel="stylesheet" media="all" href="<?php print SUB_URL; ?>/css/main.min.css" />

  </head>
  <body>
    <div id="mainpage" class="page">
    <h3 class="pagetitle"><?php print $vars['pagetitle']; ?></h3>
    <p class="strapline"><?php print $vars['strapline']; ?></p>
    <div>
      <div id="main-menu">
        <?php
          foreach($vars['pagesreg'] AS $k => $v) {
            print '<li><a href="' . SUB_URL . '/' . $k . '" class="link' . ($vars['page'] == $k ? ' active' : '') . '" >' . $v . '</a></li>';
          }
        ?>
      </div>
    </div>

<?php
include(BASE_PATH . '/incs/page_' . $vars['page'] . '.inc');
?>
    <div class="footer">hello I am A footer</div>
<?php
if ($vars['dev']) {
  echo "<hr>\n";
  include(BASE_PATH . '/incs/dump.inc');
}
?>
    </div>

    <script type="text/javascript" src="https://code.jquery.com/jquery-3.3.1.min.js"></script>
    <script type="text/javascript" src="<?php print SUB_URL; ?>/js/all.min.js"></script>

  </body>
</html>
