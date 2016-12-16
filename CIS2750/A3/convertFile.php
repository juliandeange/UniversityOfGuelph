<HTML> <BODY>
<?php
$targetFile = basename($_POST["fileToConvert"]);
$toExec = "./a3 ".$targetFile;
exec($toExec);
?>
The file was converted
</BODY>
</HTML> 