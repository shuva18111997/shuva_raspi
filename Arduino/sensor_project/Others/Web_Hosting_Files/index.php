<?php
$server="localhost";
$user="id8493294_shuva";
$pass="39039820";
$dbname="id8493294_sensors";
$conn=mysqli_connect($server,$user,$pass,$dbname);

if($conn)
	echo "
  <br><br>";
else
	die("<center>do not connect to server".mysqli_connect_error());
echo "</br>";

date_default_timezone_set('Asia/Kolkata');
$current_date = date('d-m-Y');
$current_time = date('H:i:s',strtotime('-3 second'));

$last_update_date = 0;
$last_update_time = 0;

$status;

$temp = 0;
$hum = 0;
$pre = 0;

$qury="SELECT * from sensortable";

$result=mysqli_query($conn,$qury);
$num_rows=mysqli_num_rows($result);
if($num_rows>=1)
{
	while($rows=mysqli_fetch_array($result))
	{
		$temp = $rows['Temp'];
		$hum = $rows['Hum'];
		$pre = $rows['Pre'];
		$last_update_date = $rows['Date'];
		$last_update_time = $rows['Time'];
	}
}

echo "<html>
  <head>
  <meta http-equiv=refresh content=1 />
<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />
  <style type=\"text/css\">
body
{	
background-image:url(pictures/weather.jpg);
background-position:center;
background-repeat:no-repeat;
background-size:cover;
width:90%;
}
.view_port
{
	font-size:45px;
}
.view_img
{
	width:32;
}
@media only screen and (max-width:600px)
{
	.view_port
	{
		font-size:35px;
	}
	.view_img
	{
		width:23;
	}
}
</style>
</head>
<body>
<center>";
if(($current_date == $last_update_date)&&($last_update_time>=$current_time))
{
	echo "<h1 class=\"view_port\"><font color='lime'>&nbsp&nbsp&nbsp&nbsp&nbspStatus Onilne</font>
	<img class=\"view_img\" src=\"pictures/online.png\" alt=\"Nature image\"/></h1>";
}
else if(($current_date != $last_update_date)||($current_date == $last_update_date)&&($last_update_time<$current_time))
{
	echo "<h1 class=\"view_port\"><font color='red'>&nbsp&nbsp&nbsp&nbsp&nbspStatus Offilne</font>
	<img class=\"view_img\" src=\"pictures/offline.png\" alt=\"Nature image\"/></h1>";
}
echo"<table>

<tr><h1><th><font size='6px' color=cc0000>&nbsp&nbsp&nbsp&nbsp&nbsp&nbspTemp:-</font></th><th>
<font size='6px' color=00bfff>".$temp."</font></th><th><img src=\"pictures/temp.jpeg\" alt=\"Nature image\" width=\"50\"/></th></h1></tr>
  
<tr><h1><th><font size='6px' color=rgb(85,193,129)>&nbsp&nbsp&nbsp&nbsp&nbsp&nbspHum:-</font></th><th>
<font size='6px' color=00bfff>".$hum."</font></th><th><img src=\"pictures/hum.jpeg\" alt=\"Nature image\" width=\"50\"/></th></h1></tr>
  
<tr><h1><th><font size='6px' color='blue'>&nbsp&nbsp&nbsp&nbsp&nbspPre:-</font></th><th>
<font size='6px' color=00bfff>".$pre."</font></th><th><img src=\"pictures/pre.png\" alt=\"Nature image\" width=\"50\"/></th></h1></tr>
</table>

</center></body></html>";

mysqli_close($conn);
?>