<html>
<head> <link rel="stylesheet" type="text/css" href="style.css"> </head>
<body>
<?php
chdir('files'); 
$files = glob('*.txt'); 
$newFilesArray = implode(", ", $files);
chdir('..');
?>
<!-- '<?php //echo $newFilesArray ?>' -->
<button onclick="convertButton('<?php echo $newFilesArray ?>')" id = "convertButton" class = "convertButton">Convert</button>
<button onclick="uploadButton()" id = "convertButton" class = "uploadButton">Upload</button>
<script src="a3.js"></script>
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
		foreach($htmlFiles as $key => $value) {
			echo "<a href=files/".$value.">".$value."</a><BR>";
		}
		chdir('..');
	?>
</form>

<script>
function convertButton(files) {

	window.open("convertClick.php");
	
}
function uploadButton() {
	
	window.open("uploadClick.php");

}// end uploadButton
</script>

</body>
</html>
