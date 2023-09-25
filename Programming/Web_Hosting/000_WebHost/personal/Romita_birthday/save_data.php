<?php
  
  $fMovie = $_POST['fMovie'];
  $fTVShow = $_POST['fTVShow'];
  $fStar = $_POST['fStar'];
  $fFood = $_POST['fFood'];
  $Dream_Place = $_POST['Dream_Place'];
  $preferable = $_POST['preferable'];
  $Love_Most = $_POST['Love_Most'];
  $Marry_With = $_POST['Marry_With'];
  $wanna_tell_me = $_POST['wanna_tell_me'];

  $db = new SQLite3('Romita.db');
  
  date_default_timezone_set("Asia/Calcutta");   //India time (GMT+5:30)
  $db->query("INSERT INTO Datetime (Time, Date) values ('".date("h:i:sa")."', '".date("d-m-Y")."')");

  if ($db) {
    $db->query("CREATE TABLE Romita (Question VARCHAR(255), Ans VARCHAR(255));");
    $result = $db->query("INSERT INTO Romita VALUES ('fMovie', '".$fMovie."'),('fTVShow', '".$fTVShow."'),('fStar', '".$fStar."'),('fFood', '".$fFood."'),('Dream_Place', '".$Dream_Place."'),('preferable', '".$preferable."'),('Love_Most', '".$Love_Most."'),('Marry_With', '".$Marry_With."'),('wanna_tell_me', '".$wanna_tell_me."'),('################################', '################################')");
    if($result)
	{
		echo "
			<html>
			<head>
			<style>			.view_port
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
			#loader { 
			border: 12px solid #f3f3f3; 
			border-radius: 50%; 
			border-top: 12px solid #444444; 
			width: 70px; 
			height: 70px; 
			animation: spin 1s linear infinite; 
			} 
					  
			@keyframes spin { 
				100% { 
					transform: rotate(360deg); 
				} 
			} 
					  
			.center { 
				position: absolute; 
				top: 0; 
				bottom: 0; 
				left: 0; 
				right: 0; 
				margin: auto; 
			}
			/*#####################################*/

			body {
			  background-image: url('Background_Img.jpg');
			  background-repeat: no-repeat;
			  background-attachment: fixed;
			  background-size: 100% 100%;
			}
			h1{
				font-size: 200px;
			}
			</style>
			</head>
			<body>
			<div id='loader' class='center'></div>
			<script>
			document.onreadystatechange = function() { 
				if (document.readyState !== 'complete') { 
					document.querySelector('body').style.visibility = 'hidden'; 
					document.querySelector('#loader').style.visibility = 'visible'; 
				} else { 
					document.querySelector('#loader').style.display = 'none'; 
					document.querySelector('body').style.visibility = 'visible';
					setInterval(autoUpdate, 1000);
				}
			};
			</script>
			<center>
			<h1>Thank You for Your Responce</h1>
			</center>
			</body>
			</html>";
	}
	else
	{
		echo "
			<html>
			<head>
			<style>
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
			#loader { 
			border: 12px solid #f3f3f3; 
			border-radius: 50%; 
			border-top: 12px solid #444444; 
			width: 70px; 
			height: 70px; 
			animation: spin 1s linear infinite; 
			} 
					  
			@keyframes spin { 
				100% { 
					transform: rotate(360deg); 
				} 
			} 
					  
			.center { 
				position: absolute; 
				top: 0; 
				bottom: 0; 
				left: 0; 
				right: 0; 
				margin: auto; 
			}
			/*#####################################*/
			body {
			  background-image: url('Background_Img.jpg');
			  background-repeat: no-repeat;
			  background-attachment: fixed;
			  background-size: 100% 100%;
			}
			h1{
				font-size: 100px;
			}
			</style>
			</head>
			<body>
			<div id='loader' class='center'></div>
			<script>
			document.onreadystatechange = function() { 
				if (document.readyState !== 'complete') { 
					document.querySelector('body').style.visibility = 'hidden'; 
					document.querySelector('#loader').style.visibility = 'visible'; 
				} else { 
					document.querySelector('#loader').style.display = 'none'; 
					document.querySelector('body').style.visibility = 'visible';
					setInterval(autoUpdate, 1000);
				}
			};
			</script>
			<center>
			<h1>There is Some Problem Take a Screenshot And Contact to Shuva</h1>
			</center>
			</body>
			</html>";
	}
	//$result = $db->query("SELECT * FROM Romita");
    //var_dump($result->fetchArray(SQLITE3_ASSOC));
  } else {
    print "Connection to database failed!\n";
  }
?>