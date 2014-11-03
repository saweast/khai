<?php
	$fileToDownload = ("./results/".$_GET['name']);
	header ("Content-Type: application/octet-stream");
	header ("Accept-Ranges: bytes");
	header ("Content-Length: ".filesize($fileToDownload));
	header ("Content-Disposition: attachment; filename=".$_GET['name']);  	
	readfile($fileToDownload);
?>