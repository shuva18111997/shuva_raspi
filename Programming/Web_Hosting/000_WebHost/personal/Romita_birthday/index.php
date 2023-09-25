<?php
date_default_timezone_set("Asia/Calcutta");   //India time (GMT+5:30)
if(true)	//(date("hiY") > 7302021)
{
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
	* {box-sizing: border-box;}
	body {font-family: Verdana, sans-serif;}
	.mySlides {display: none;}
	img {vertical-align: middle;}

	/* Slideshow container */
	.slideshow-container {
	  max-width: 1000px;
	  position: relative;
	  margin: auto;
	}

	/* Caption text */
	.text {
	  color: #f2f2f2;
	  font-size: 15px;
	  padding: 8px 12px;
	  position: absolute;
	  bottom: 8px;
	  width: 100%;
	  text-align: center;
	}

	/* Number text (1/3 etc) */
	.numbertext {
	  color: #f2f2f2;
	  font-size: 12px;
	  padding: 8px 12px;
	  position: absolute;
	  top: 0;
	}

	/* The dots/bullets/indicators */
	.dot {
	  height: 15px;
	  width: 15px;
	  margin: 0 2px;
	  background-color: #bbb;
	  border-radius: 50%;
	  display: inline-block;
	  transition: background-color 0.6s ease;
	}

	.active {
	  background-color: #717171;
	}

	/* Fading animation */
	.fade {
	  -webkit-animation-name: fade;
	  -webkit-animation-duration: 1.5s;
	  animation-name: fade;
	  animation-duration: 1.5s;
	}

	@-webkit-keyframes fade {
	  from {opacity: .4} 
	  to {opacity: 1}
	}

	@keyframes fade {
	  from {opacity: .4} 
	  to {opacity: 1}
	}

	/* On smaller screens, decrease text size */
	@media only screen and (max-width: 300px) {
	  .text {font-size: 11px}
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
	<div class='slideshow-container'>
	<center>
	<div class='mySlides fade'>
	  <div class='numbertext'>1 / 3</div>
	  <img src='1.jpg' style='width:100%'>
	  <div class='text'>Love makes Happy</div>
	</div>

	<div class='mySlides fade'>
	  <div class='numbertext'>2 / 3</div>
	  <img src='2.jpg' style='width:100%'>
	  <div class='text'>Love is Passion</div>
	</div>

	<div class='mySlides fade'>
	  <div class='numbertext'>3 / 3</div>
	  <img src='3.jpg' style='width:100%'>
	  <div class='text'>Love is Infatuation</div>
	</div>

	</center>
	</div>
	<br>

	<div style='text-align:center'>
	  <span class='dot'></span> 
	  <span class='dot'></span> 
	  <span class='dot'></span> 
	</div>

	<script>
	var slideIndex = 0;
	showSlides();

	function showSlides() {
	  var i;
	  var slides = document.getElementsByClassName('mySlides');
	  var dots = document.getElementsByClassName('dot');
	  for (i = 0; i < slides.length; i++) {
		slides[i].style.display = 'none';  
	  }
	  slideIndex++;
	  if (slideIndex > slides.length) {slideIndex = 1}    
	  for (i = 0; i < dots.length; i++) {
		dots[i].className = dots[i].className.replace(' active', '');
	  }
	  slides[slideIndex-1].style.display = 'block';  
	  dots[slideIndex-1].className += ' active';
	  setTimeout(showSlides, 2000); // Change image every 2 seconds
	}
	</script>
	</br></br></br>
	<center>
	<table border=2>
	<tr>
	<th><font color=red><b>❤ প্রিয় Romita ❤</b></font></th>
	</tr>
	<tr><td>
	<center><a href='/main.php'><img src='Folder.jpg' style='max-width:100%;height:auto;'></a></center>
	</td></tr>
	<tr><th><font color=red><b>এখানে আমাদের কিছু স্মৃতি আছে</b></font></th></tr></table></center>
	</br></br></br></br></br>
	</body>
	</html>
	";
}
else
{
	echo "
	<html>
	<head>
	<meta name='viewport' content='width=device-width, initial-scale=1'>
	<link rel='stylesheet' href='style.css'>
    <script src='index.js'></script>
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
		font-size: 150px;
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
	<h1>শুভ সারপ্রাইজ খোলার অনুমতি দেয়নি|</h1>
    <div id='clockContainer'>
        <div id='hour'></div>
        <div id='minute'></div>
        <div id='second'></div>
    </div>
	</center>
	</body>
	</html>";
}
?>