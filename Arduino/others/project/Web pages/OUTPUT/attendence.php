<html>
<head>
<title>attendence</title>
<meta name="viewport" content="width=device-width, initial-scale=1" />
</head>
<body bgcolor="lime">
<center>
<?php
$roll=$_POST["roll"];
$dept=$_POST["dept"];
$year=$_POST["year"];
if($roll=='7'||$roll=='8'||$roll=='9')
{
$server="localhost";
$user="root";
$pass="";
$dbname="attendence_system";
$conn=mysqli_connect($server,$user,$pass,$dbname);

if($conn)
	echo "<h1><font color=red><center>connected succesfully</center></font></h1>";
else
	die("do not connect to server".mysqli_connect_error());
echo "</br>";

$qury="SELECT * from rkmsm WHERE roll=('$roll')";

$result=mysqli_query($conn,$qury);
$num_rows=mysqli_num_rows($result);
if($num_rows>=1)
{
echo "<table border='5' bordercolor=green>
<tr>
<th><font color=red>Id</font></th>
<th><font color=blue>Name</font></th>
<th><font color=green>Dept</font></th>
<th><font color=red>Roll</font></th>
<th><font color=#0D3014>Year</font></th>
<th><font color=#2F60B5>Date&Time</font></th>
</tr>";
while($rows=mysqli_fetch_array($result))
{
echo "<tr>";
echo "<td>".$rows['id']."</td>";
echo "<td>".$rows['name']."</td>";
echo "<td>".$rows['dept']."</td>";
echo "<td>".$rows['roll']."</td>";
echo "<td>".$rows['year']."</td>";
echo "<td>".$rows['Time']."</td>";
echo "</tr>";
}
echo "</table>";
}
else
{
echo "<h1><font color=blue>"."Sorry no record found!!!!!"."</font></h1>";
}
mysqli_close($conn);
echo "</br></br><img src='01.jpg'>";
}
else
{
	echo "<h1><font color=red>"."Alert This is not a valid data!!!!!"."</font></h1>";	
}
?>
</center>
</body>
</html>