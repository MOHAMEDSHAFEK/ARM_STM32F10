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