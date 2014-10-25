<?php
@mkdir("xmls", 0777);
//$url='D:\Test.xml';
$url=$_GET['urld'];
$f=fopen($url,'rb');
$rands = randstr();
$f1=fopen('xmls/'. $rands .'.xml','wb');
while (!feof($f))
{
     $str=fread($f,1024);
     fwrite($f1,$str);
}
fclose($f);
fclose($f1);

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
$ssylka = "http://uspaun.pp.ua/fromXMLToDb.php?urls=xmls/". $rands .".xml";
echo "<meta http-equiv=refresh content=0;URL=". $ssylka .">";
?>