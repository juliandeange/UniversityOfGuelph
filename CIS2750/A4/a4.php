<html>
<head> <link rel="stylesheet" href="style.css"> </head>
<body>
<?php
chdir('files'); 
$files = glob('*.txt'); 
$newFilesArray = implode(", ", $files);
chdir('..');
?>
<button onclick="convertButton('<?php echo $newFilesArray ?>')" id = "convertButton" class = "convertButton">Convert</button>
<button onclick="uploadButton()" id = "convertButton" class = "uploadButton">Upload</button>
<button onclick="dbstoreButton()" id = "dbstoreButton" class = "dbstoreButton">DB Store</button>
<P>
<form class = "textFileForm">
	<?php
	echo '<U><B>Text Files</B></U><BR>';
	chdir('files');
	$txtFiles = glob('*.txt');
	foreach($txtFiles as $key => $value) {
		echo "<a href=files/".$value.">".$value."</a><BR>";
	}
	?>
</form>

<form class = "htmlFileForm">
	<?php
	echo '<U><B>HTML Files</B></U><BR>';
	$htmlFiles = glob('*.html');
	sort($htmlFiles);
	foreach($htmlFiles as $key => $value) {
		echo "<a href=files/".$value.">".$value."</a><BR>";
	}
	chdir('..');
	$htmlFiles = glob('.*.html');
	sort($htmlFiles);
	foreach($htmlFiles as $key => $value) {
		echo "<a href=".$value.">".substr($value, 1, -5)."</a><BR>";
	}


	?>
</form>

<script>
function convertButton(files) {
	window.open("convertClick.php");
}
function uploadButton() {
	window.open("uploadClick.php");
}
function dbstoreButton() {
	window.open("dbstoreClick.php");
}

</script>
</body>
</html>
