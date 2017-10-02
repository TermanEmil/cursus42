<?php
include("auth.php");

session_start();

function	get_empty_warning($key)
{
	return (get_dex_str($key, $_POST) == "") ? "*" : "";
}

if ($_POST["submit"] != "OK")
{
	echo "No submit\n";
	exit(0);
}

if (get_dex_str("login", $_POST) == "" ||
	get_dex_str("passwd", $_POST) == "")
{
	$_SESSION["login_field"] = get_empty_warning("login");
	$_SESSION["passwd_field"] = get_empty_warning("passwd");
	header('Location: /j04/ex04/index.php');
	echo "Empty field\n";
	exit(0);
}

$ret = auth($_POST["login"], $_POST["passwd"]);
if ($ret == 0)
{
	set_current_user($_POST["login"]);
}
else if ($ret == -1)
{
	$_SESSION["login_field"] = "Not registered";
	header('Location: /j04/ex04/index.php');
	exit(0);
}
else if ($ret == -2)
{
	$_SESSION["passwd_field"] = "Incorrect";
	header('Location: index.php');
	exit(0);
}

$_SESSION["loggued_on_user"] = $_POST["login"];
create_raw_msg($_SESSION["loggued_on_user"]. " has connected");
header('Location: speak.php');
?>