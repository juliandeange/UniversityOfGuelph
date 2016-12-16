<HTML> <BODY>
<?php
$targetFile = basename($_POST["fileToConvert"]);
$toExec = "./a4 ".$targetFile;
exec($toExec);
?>
The file was converted
</BODY>
</HTML> 