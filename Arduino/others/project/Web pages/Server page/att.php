<?php

$RollNo=$_GET["roll"];

date_default_timezone_set('Asia/Kolkata');
echo date('d-m-Y H:i');
$d=date('d');
$t=date('Hi');
 
	
$server="localhost";
$user="root";
$pass="";
$dbname="attendence_system";
$conn=mysqli_connect($server,$user,$pass,$dbname);

if($conn)
	echo "connected succesfully";
else
	die("do not connect to server".mysqli_connect_error());
echo "</br>";

//if($t>815 && $t<955)
 //{
	if($RollNo==7)
	{
		$Name='Shuvabrata Dey';
		$DEPT='ETCE';
		$Roll='7';
		$Year='3rd';
		echo $Name." ".$DEPT." ".$Roll." ".$Year;
		
$qury="INSERT INTO rkmsm(roll,name,dept,year)VALUES('$Roll','$Name','$DEPT','$Year')";

$result=mysqli_query($conn,$qury);

if($result)
	echo "NEW RECORD created SUCCESSFULLY";
else
	echo "ERROR SEND DATA".mysqli_error($conn);

	}
	if($RollNo==8)
	{
		$Name='koushik Bhadra';
		$DEPT='ETCE';
		$Roll='8';
		$Year='3rd';
		echo $Name." ".$DEPT." ".$Roll." ".$Year;
		
$qury="INSERT INTO rkmsm(roll,name,dept,year)VALUES('$Roll','$Name','$DEPT','$Year')";

$result=mysqli_query($conn,$qury);

if($result)
	echo "NEW RECORD created SUCCESSFULLY";
else
	echo "ERROR SEND DATA".mysqli_error($conn);

	}
	if($RollNo==9)
	{
		$Name='Kunal Mukherjee';
		$DEPT='ETCE';
		$Roll='9';
		$Year='3rd';
		echo $Name." ".$DEPT." ".$Roll." ".$Year;
		
$qury="INSERT INTO rkmsm(roll,name,dept,year)VALUES('$Roll','$Name','$DEPT','$Year')";

$result=mysqli_query($conn,$qury);

if($result)
	echo "NEW RECORD created SUCCESSFULLY";
else
	echo "ERROR SEND DATA".mysqli_error($conn);

	}

 //}
	mysqli_close($conn);

?>