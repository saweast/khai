<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Новини</title>
<link href="content.css" rel="stylesheet" type="text/css">
<link href="menu.css" rel="stylesheet" type="text/css">
</head>
<body>
    <header>
    <a href="index.php"><img src="" width="180" height="90" id="logo" display:block;" /></a>NEWS ALL OF THE WORLD
    <input type="search" placeholder="пошук по сайту" autocomplete="on" display:block;>
    </header>
    <div id="menu">
      <?php include 'menu.php'; ?>
</div>
    <div id="content">
    <table width="100%" border="0">
      <tbody>
        <tr>
          <td width="50%" align="left" valign="top"><div id="popularnews">Популярні новини</div></td>
          <td width="50%" align="left" valign="top"><div id="lastnews">Останні новини
          </div></td>
          <td width="100px"><div id="commercial">Реклама</div></td>
        </tr>
      </tbody>
    </table>
    </div>
<footer>&copy; Віталій Волківський</footer>
</body>
</html>
