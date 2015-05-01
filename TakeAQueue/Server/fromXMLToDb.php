<html>
	<form method="POST" enctype="multipart/form-data">
		<input type="file" name="xml" />
		<input type="submit" />
	</form>
</html>

<?php

if ($_SERVER['REQUEST_METHOD'] != "POST")
	return;
	//var_dump($_FILES);
mysql_connect("localhost", "uspaun.pp.ua", "NoKlA1500NoKiA");
mysql_select_db("uspaun_pp_ua_project");
$urls = $_FILES['xml']['tmp_name'];

//echo $urls;

//echo file_get_contents($urls);

$xml = simplexml_load_file($urls);

//var_dump($xml);

foreach($xml->children() as $people) {  
	//var_dump($people);
	$query = "insert into uspupl (Name) value ('". $people->Name ."')";
	$result = mysql_query($query);

	//echo $query."<br>";	

	if (!$result){
		exit(mysql_error());
	}
	
	  echo "вставлено!";
}
?>