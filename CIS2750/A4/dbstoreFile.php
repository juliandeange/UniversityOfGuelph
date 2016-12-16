<HTML> <BODY>
<?php
$targetFile = basename($_POST["fileToConvert"]);
$toExec = "./a4 ".$targetFile." -db";
exec($toExec);
?>
The file was converted and stored in the database
</BODY>
</HTML> 