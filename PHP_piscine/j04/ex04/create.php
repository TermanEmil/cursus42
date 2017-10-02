<?php
include("auth.php");

session_start();

print_r($_POST);

if (get_dex_str("submit", $_POST) != "OK")
{
	echo "No submit\n";
	exit(0);
}

if (get_dex_str("login", $_POST) == "" ||
	get_dex_str("passwd", $_POST) == "")
{
	$_SESSION["Warning"] = "Empty fields";
	header('Location: /j04/ex04/create_html.php');
	exit(0);
}

if (login_exists($_POST["login"], get_users()))
{
	$_SESSION["Warning"] = "Login already registred";
	header('Location: /j04/ex04/create_html.php');
	exit(0);
}

if ($_POST["passwd"] != $_POST["repeat_passwd"])
{
	$_SESSION["Warning"] = "Passwords don't match";
	header('Location: /j04/ex04/create_html.php');
	exit(0);	
}

new_user($_POST["login"], $_POST["passwd"]);
echo "OK\n";
header('Location: .');
?>