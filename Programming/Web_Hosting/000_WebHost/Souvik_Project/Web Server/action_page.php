<?php
$pump_trig=$_GET["pump_trig"];
date_default_timezone_set("Asia/Calcutta");   //India time (GMT+5:30)
$db = new SQLite3('data.db');
$db->query("DELETE from pump");
$result = $db->query("INSERT into pump(pump_trig) values(".$pump_trig.")");
if($result)
	header("Location: index.html");
else
	echo "<h1>connot insert data.</h1>";
?>