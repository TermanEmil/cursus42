<?php
include("auth.php");

session_start();

if (!array_key_exists("loggued_on_user", $_SESSION) ||
	$_SESSION["loggued_on_user"] == "")
	ft_err();
echo $_SESSION["loggued_on_user"]."\n";
?>
