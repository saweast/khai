<?php
$fileIMG = $_FILES['uploadfile'];
// Каталог, в который мы будем принимать файл:
$uploaddir = './images/';
$fileIMG['name']=randstr().'.jpg';
$uploadfile = $uploaddir.basename($fileIMG['name']);

	if ($fileIMG['type'] != "image/jpeg")
		exit;		
	
// Копируем файл из каталога для временного хранения файлов:
	echo copy($fileIMG['tmp_name'], $uploadfile) ? "true" : "false";
	
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