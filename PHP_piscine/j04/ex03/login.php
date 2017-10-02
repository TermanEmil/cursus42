<?php
include("auth.php");

session_start();

if (get_dex_str("login", $_GET) == "" ||
	get_dex_str("passwd", $_GET) == "" ||
	!auth($_GET["login"], $_GET["passwd"]))
{
	$_SESSION["loggued_on_user"] = "";
	echo "ERROR\n";
}
else
{
	$_SESSION["loggued_on_user"] = $_GET["login"];
	echo "OK\n";
}
?>
