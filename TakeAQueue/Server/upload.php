<?php

//if ($_SERVER['REQUEST_METHOD'] != "POST")	return;

mysql_connect("localhost", "uspaun.pp.ua", "NoKlA1500NoKiA");
mysql_select_db("uspaun_pp_ua_project");
$file = $_FILES['file'];
$xml = simplexml_load_file($file["tmp_name"]);

$fileIMG = $_FILES['uploadfile'];
	//if ($fileIMG['type'] != "image/png")
		//exit;
$uploaddir = './images/';
$fileIMG['name']=randstr().'.png';
$uploadfile = $uploaddir.basename($fileIMG['name']);		
echo copy($fileIMG['tmp_name'], $uploadfile) ? " image is uploaded" : " false";
foreach($xml->children() as $people) {  
	$query = "insert into uspupl (Name, Image) values ('". $people->name ."', 'http://uspaun.pp.ua". $uploadfile ."')";
	
	$result = mysql_query($query);
	if (!$result){
		exit(mysql_error());
	}
}
echo "xml uploaded and data is inserted";
	
	function randstr($len=5)
	{
		$arr=array("A-Z","a-z","0-9");
		unset($simb);
		for($i=0;$i<count($arr);$i++)
		{
			@list($st,$end)=split("-",$arr[$i]);
			for($j=ord($st);$j<ord($end);$j++)
			{
				$simb[]=chr($j);
			}
		}
		$str="";
		for($i=0;$i<$len;$i++)
		{
			$str.=$simb[rand(0,(count($simb)-1))];
		}
		return $str;
	}
?>