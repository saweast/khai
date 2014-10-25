<?php

//if ($_SERVER['REQUEST_METHOD'] != "POST")	return;

mysql_connect("localhost", "uspaun.pp.ua", "NoKlA1500NoKiA");
mysql_select_db("uspaun_pp_ua_project");
$file = $_FILES['file'];
$xml = simplexml_load_file($file["tmp_name"]);

foreach($xml->children() as $people) {  
	$query = "insert into uspupl (Name) value ('". $people->name ."')";
	
	$result = mysql_query($query);
	if (!$result){
		exit(mysql_error());
	}
}
?>