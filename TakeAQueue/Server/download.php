<?php
	 //під'єднуємось до БД
	mysql_connect("localhost", "uspaun.pp.ua", "NoKlA1500NoKiA");
	mysql_select_db("uspaun_pp_ua_project");
	$result = mysql_query("SELECT * FROM usptbl");
		//створити xml документ
	$file = new DomDocument('1.0', 'utf-8');
	$people = $file->appendChild($file->createElement('peoples'));
		
	while ($row = mysql_fetch_array($result))
	{
		$section = $people->appendChild($file->createElement('people'));
		$idAttr1 = $file->createAttribute("ID");
		$idAttr1->appendChild($file->createTextNode($row[0]));
		$section->appendChild($idAttr1);
		$name = $section->appendChild($file->createElement('Name'));
		$name->appendChild($file->createTextNode($row[1]));
	}
	$file->save("results/Test.xml");
	$test1 = $file->saveXML();
	//$ssylka = "http://uspaun.pp.ua/getFile.php?name=Test.xml";
	//echo "<meta http-equiv=refresh content=0;URL=". $ssylka .">";
	header("Content-type: text/xml");
	echo $test1;
?>