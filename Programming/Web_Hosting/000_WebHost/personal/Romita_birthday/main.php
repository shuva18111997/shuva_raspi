<?php
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
table, th, td {
  border: 1px solid black;
  border-radius: 10px;
  font-size: 50px;
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
<body bgcolor='#000000'>
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
<td><center><img src = '/Romita/1.jpg' style='width:660;height:411;'></center></td>
</tr></table>
<h1 style = 'font-size: 50px;'>তোমায় হৃদ মাঝারে রাখবো</h1>
<table>
<tr>
<td><img src = '/Romita/2.jpg' style='width:360;height:460;'></td>
<td><img src = '/Romita/3.jpg' style='width:360;height:460;'></td>
<td><img src = '/Romita/Romita.jpg' style='width:360;height:460;'></td>
</tr>
<tr>
<td><center>
<audio controls='controls' id= 'audio1'>
  <source src='Raataan_Lambiyan.mp3' type='audio/mpeg'>
</audio>
</center></td>
<td><center>
<audio controls='controls' id= 'audio2'>
  <source src='Majhe_Majhe_Tobo.mp3' type='audio/mpeg'>
</audio>
</center></td>
<td><center>
<audio controls='controls' id= 'audio3'>
  <source src='Dil_Ke_Paas_(Unplugged).mp3' type='audio/mpeg'>
</audio>
</center></td>
</tr>
</table>
<h1 style = 'font-size: 50px;'>Love You Romita ❤</h1>
<table>
<tr>
<td><img src = '/Romita/5.jpg' style='width:360;height:362;'></td>
<td><img src = '/Romita/6.jpg' style='width:360;height:362;'></td>
<td><img src = '/Romita/7.jpg' style='width:360;height:362;'></td>
</tr>
<tr>
<td><center>
<audio controls='controls' id= 'audio4'>
  <source src='Kabhi_Tumhe_Shershaah.mp3' type='audio/mpeg'>
</audio>
</center></td>
<td><center>
<audio controls='controls' id= 'audio5'>
  <source src='Jibon_Zay.mp3' type='audio/mpeg'>
</audio>
</center></td>
<td><center>
<audio controls='controls' id= 'audio6'>
  <source src='Bol_Do_Na_Zara.mp3' type='audio/mpeg'>
</audio>
</center></td>
</tr>
</table>
</br></br>
<script>
var audio1 = document.getElementById('audio1');
var audio2 = document.getElementById('audio2');
var audio3 = document.getElementById('audio3');
var audio4 = document.getElementById('audio4');
var audio5 = document.getElementById('audio5');
var audio6 = document.getElementById('audio6');

audio1.onplay = function() {
	audio2.pause();
	audio3.pause();
	audio4.pause();
	audio5.pause();
	audio6.pause();
};
audio2.onplay = function() {
	audio1.pause();
	audio3.pause();
	audio4.pause();
	audio5.pause();
	audio6.pause();
};
audio3.onplay = function() {
	audio1.pause();
	audio2.pause();
	audio4.pause();
	audio5.pause();
	audio6.pause();
};
audio4.onplay = function() {
	audio1.pause();
	audio2.pause();
	audio3.pause();
	audio5.pause();
	audio6.pause();
};
audio5.onplay = function() {
	audio1.pause();
	audio2.pause();
	audio3.pause();
	audio4.pause();
	audio6.pause();
};
audio6.onplay = function() {
	audio1.pause();
	audio2.pause();
	audio3.pause();
	audio4.pause();
	audio5.pause();
};
</script>
<h1 style = 'font-size: 50px;'>Please আমার কিছু প্রশ্নের উত্তর দেবে ☺</h1>
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
	<option value='Perfume'>Perfume</option>
	<option value='Make_Up_Kit'>Make Up Kit</option>
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
<th><font size = 100>You Love most</font></th>
<td><center>
<select id='Love_Most' name='Love_Most' style='width:80%;'>
    <option value='Maa'>Maa</option>
	<option value='BaBa'>BaBa</option>
    <option value='Promita'>Promita</option>
	<option value='Protyush'>Protyush</option>
	<option value='Shuva'>Shuva</option>
</select><center>
</td>
</tr>
<tr>
<th><font size = 100>You Want to marry with</font></th>
<td><center>
<select id='Marry_With' name='Marry_With' style='width:80%;'>
    <option value='Your_Choise'>Your Choise</option>
	<option value='Moms_Choise'>Mom's Choise</option>
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
