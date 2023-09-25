<?php
echo "
<html>
<head>
<meta name='viewport' content='width=device-width, initial-scale=1'>
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
table, th, td {
  border: 1px solid black;
  border-radius: 10px;
}
button {
  background-color: #ff0000;
  color: white;
  border: 2px solid #f44336;
  padding: 16px 32px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 16px;
  margin: 4px 2px;
  transition-duration: 0.4s;
  cursor: pointer;
  border-radius: 12px;;
}
button:hover {
  background-color: #008CBA;
  color: white;
  border: 2px solid #008CBA;
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
</br></br>
<center>
<table border=2>
<tr>
<th>তোমার সাথে আমার প্রথম দেখা</th>
</tr>
<tr>
<td><img src = '/Tulip/1.jpg' style='width:460;height:360;'></td>
</tr></table>
<h1>তোমায় হৃদ মাঝারে রাখবো</h1>
<table>
<tr>
<td><img src = '/Tulip/2.jpg' style='width:360;height:460;'></td>
<td><img src = '/Tulip/3.jpg' style='width:360;height:460;'></td>
<td><img src = '/Tulip/4.jpg' style='width:360;height:460;'></td>
</tr>
<tr>
<td><center>
<audio controls='controls' id= 'audio1'>
  <source src='Bol_Do_Na_Zara.mp3' type='audio/mpeg'>
</audio>
</center></td>
<td><center>
<audio controls='controls' id= 'audio2'>
  <source src='Kabhi_Tumhe_Shershaah.mp3' type='audio/mpeg'>
</audio>
</center></td>
<td><center>
<audio controls='controls' id= 'audio3'>
  <source src='Majhe_Majhe_Tobo.mp3' type='audio/mpeg'>
</audio>
</center></td>
</tr>
</table>
<h1>Birthday Girl Tulip ❤</h1>
<table>
<tr>
<td><img src = '/Tulip/bday_girl1.jpg' style='width:360;height:460;'></td>
<td><img src = '/Tulip/bday_girl2.jpg' style='width:360;height:460;'></td>
<td><img src = '/Tulip/bday_girl3.jpg' style='width:360;height:460;'></td>
</tr>
</table>
</br></br>
<script>
var audio1 = document.getElementById('audio1');
var audio2 = document.getElementById('audio2');
var audio3 = document.getElementById('audio3');

audio1.onplay = function() {
	audio2.pause();
	audio3.pause();
};
audio2.onplay = function() {
	audio1.pause();
	audio3.pause();
};
audio3.onplay = function() {
	audio1.pause();
	audio2.pause();
};
</script>
<h1>নে এবার emotional 😭 না হয়ে আমার কিছু প্রশ্নের উত্তর দে তো</h1>
<form action='/save_data.php' method='post'>
<table border = 2>
<tr>
<th><font size = 100>Your Fav. Movies??</font></th>
<td><center>
<input type='text' id='fMovie' name='fMovie' placeholder='Kabir Singh'><center>
</td>
</tr>
<tr>
<th><font size = 100>Your Fav. TV Shows??</font></th>
<td><center>
<input type='text' id='fTVShow' name='fTVShow' placeholder='Krishnakoli'><center>
</td>
</tr>
<tr>
<th><font size = 100>Your Fav. Film Stars??</font></th>
<td><center>
<input type='text' id='fStar' name='fStar' placeholder='ranbir kapoor'><center>
</td>
</tr>
<tr>
<th><font size = 100>Your Fav. Foods??</font></th>
<td><center>
<input type='text' id='fFood' name='fFood' placeholder='Biriyani, Fread Rice, chicken-do-pyaza'><center>
</td>
</tr>
<tr>
<th><font size = 100>Your Dream Places??</font></th>
<td><center>
<input type='text' id='Dream_Place' name='Dream_Place' placeholder='darjeeling'><center>
</td>
</tr>
<tr>
<th><font size = 100>What is preferable??</font></th>
<td><center>
<select id='preferable' name='preferable' style='width:80%;'>
    <option value='Key_Chain'>Key Chain</option>
    <option value='nail_polish_set'>nail polish set</option>
	<option value='Lipstick'>Lipstick</option>
	<option value='Hair_Clip'>Hair Clip</option>
</select><center>
</td>
</tr>
<tr>
<th><font size = 100>Do you Love me??</font></th>
<td><center>
<select id='Love_me' name='Love_me' style='width:80%;'>
    <option value='Yes'>Yes</option>
    <option value='No'>No</option>
</select></center>
</td>
</tr>
<tr>
<th><font size = 100>Want to Hug me??</font></th>
<td><center>
<select id='Hug_me' name='Hug_me' style='width:80%;'>
    <option value='Yes'>Yes</option>
    <option value='No'>No</option>
</select></center>
</td>
</tr>
<tr>
<th><font size = 100>Want to Kiss me??</font></th>
<td><center>
<select id='Kiss_me' name='Kiss_me' style='width:80%;'>
    <option value='Yes'>Yes</option>
    <option value='No'>No</option>
</select></center>
</td>
</tr>
<tr>
<th><font size = 100>Preferable Kiss type</font></th>
<td><center>
<select id='Kiss_type' name='Kiss_type' style='width:80%;'>
    <option value='FRENCH_Kiss'>FRENCH Kiss</option>
    <option value='SINGLE_LIP_Kiss'>SINGLE LIP Kiss</option>
	<option value='LIZZY_Kiss'>LIZZY Kiss</option>
    <option value='AMERICAN_Kiss'>AMERICAN Kiss</option>
	<option value='ICE_Kiss'>ICE Kiss</option>
    <option value='BUTTERFLY_Kiss'>BUTTERFLY Kiss</option>
	<option value='SMOOCH_Kiss' selected>SMOOCH Kiss</option>
	<option value='NECK_Kiss'>NECK Kiss</option>
	<option value='You_are_not_mine'>You'r not mine</option>
</select></center>
</td>
</tr>
<tr>
<th><font size = 100>Will you be my Wife??</font></th>
<td><center>
<select id='she_wants_my_wife' name='she_wants_my_wife' style='width:80%;'>
    <option value='Yes'>Yes</option>
    <option value='No'>No</option>
</select><center>
</td>
</tr>
<tr>
<th><font size = 100>Honeymoon with me??</font></th>
<td><center>
<input type='text' id='Honeymoon' name='Honeymoon' placeholder='Lepchakha(Boxa)'><center>
</td>
</tr>
<tr>
<th><font size = 100>How much Hate Kuheli??</font></th>
<td><center>
<select id='Hate_Kuheli' name='Hate_Kuheli' style='width:80%;'>
    <option value='0'>0%</option>
    <option value='25'>25%</option>
	<option value='50'>50%</option>
    <option value='100'>100%</option>
</select><center>
</td>
</tr>
<tr>
<th><font size = 100>How much Hate Moon??</font></th>
<td><center>
<select id='Hate_Moon' name='Hate_Moon' style='width:80%;'>
    <option value='0'>0%</option>
    <option value='25'>25%</option>
	<option value='50'>50%</option>
    <option value='100'>100%</option>
</select><center>
</td>
</tr>
<tr>
<th><font size = 100>You Love most</font></th>
<td><center>
<select id='Love_Most' name='Love_Most' style='width:80%;'>
    <option value='Sourjo'>Sourjo</option>
	<option value='Pintu'>Pintu</option>
    <option value='Koushik'>Koushik</option>
	<option value='Shuva'>Shuva</option>
	<option value='Abhishek_CGEC'>Abhishek CGEC</option>
</select><center>
</td>
</tr>
<tr>
<th><font size = 100>You Want to marry with</font></th>
<td><center>
<select id='Marry_With' name='Marry_With' style='width:80%;'>
    <option value='Koushik'>Koushik</option>
	<option value='Shuva'>Shuva</option>
</select><center>
</td>
</tr>
<tr>
<th><font size = 100>Night Stay With me??</font></th>
<td><center>
<select id='Night_Stay' name='Night_Stay' style='width:80%;'>
    <option value='Do_Nothing'>Do Nothing</option>
	<option value='Hug_Cry'>Tightly Hug & Cry</option>
    <option value='Hug_Kiss'>Hug & Kiss</option>
	<option value='Hug_Cry_Kiss'>Hug Cry then Kiss</option>
	<option value='Hug_Cry_Sex'>Hug Cry then Sex</option>
	<option value='All'>All the above</option>
</select><center>
</td>
</tr>
</table>
</br></br>
<table border = 2>
<tr>
<th><font size = 10>তোমার মনে কিছু কথা থাকলে বলো </font></th>
</tr>
<tr>
<td><center>
<textarea id='wanna_tell_me' name='wanna_tell_me' rows='20' cols='100' placeholder=' এটা একটা LOVE LETTER ভাবতে পারো , এখানে তোমার মনে আমার প্রতি যা আছে বলতে পারো।'></textarea>
<center>
</td>
</tr>
</table>
</br></br>
<button>Submit</button>
</form>
</br></br>
</center>
</br></br></br></br>
</br></br></br></br>
</br></br></br></br>
</br></br></br></br>
</br></br></br></br>
</br></br></br></br>
</body>
</html>
";
?>