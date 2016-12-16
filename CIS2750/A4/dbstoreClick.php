<html>
<head> <link rel="stylesheet" type="text/css" href="style.css"> </head>
<body>
<B><U>
Enter a file to convert and store in the database from the following list<BR>
(Press Return / Enter when ready)</U>:
<BR></B>
<form action="dbstoreFile.php" method="post" enctype="multipart/form-data">
<BR>
	<?php
	echo '<U><B>Text Files</B></U><BR>';
	chdir('files');
	$txtFiles = glob('*.txt');
	foreach($txtFiles as $key => $value) {
		echo $value."<BR>";
	}
	chdir('..');
	?>
<P>
File Name:
<input type="text" name="fileToConvert" id="fileToConvert" class="fileToConvert">
</form>
</body>
</html>