# website for IOT System 

This is a sample web site for test esp wifi module 

* This page have two pessed to cotrol the led 
* the turen on press give me 0 in status 
* the turen off press give me 1 in status 

* *HTML code*
```
<html>
<head>
<title>	Mohamed Shafek	IOT System	</title>
</head>
<body>
<h1 style="background-color:rgb(255, 99, 71);"> Hello IOT </h1>
<p style="color:white"> This website is implmentad by Mohamed Shafek
<br>It would be used to control the light in the room
<br>I hobe you enjoy the game    </p>
<h3 style="background-color:rgb(150, 170, 50);"> LED Control </h2>
<p style="color:white"> To turn on the LED 
<a href="script.php?status=on">Press Here </a> <p>

<p style="color:white"> To turn off the LED 
<a href="script.php?status=off">Press Here </a> <p>

</body>

</html>
```
* *PHP code*
```
<?php

echo '<span style="color: white;" /> Hello From PHP!</span>';

if(isset ($_GET['status']) )
{
	/* Open the file */
	$myfile = fopen("status.txt","w");  //open file status.txt and write and return opjct myfile is a vraible
	
	if(($_GET['status'])== 'on')
	{
		fwrite($myfile,'1');
		header ("Location: on.html");
	}
	elseif(($_GET['status'])== 'off')
	{
		fwrite($myfile,'0');
		header ("Location: off.html");
	}
	/*close the file*/
	fclose($myfile);
}

?>
```
* *my web site*
[title](http://mshafek.freevar.com/)
