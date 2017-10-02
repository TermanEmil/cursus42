<?php
	include("auth.php");
	
	session_start();
	display_user_menu();
	if (isset($_POST["submit"]) &&
		isset($_SESSION["loggued_on_user"]) && $_SESSION["loggued_on_user"] != "")
	{
		$users = get_users();
		if (hash($hash_alg, $_POST["oldpw"]) != $users[$_SESSION["loggued_on_user"]]["passwd"])
		{
			echo "Wrong password";
		}
		else
		{
			$users[$_SESSION["loggued_on_user"]]["passwd"] = hash($hash_alg, $_POST["newpw"]);
			save_users($users);
			echo "Password has been changed";
		}
	}
	else if (!isset($_SESSION["loggued_on_user"]))
		header('Location: index.php');
?>

<html>
<head>
	<title>Modify password</title>
</head>
<body>
	<div align="center">
	<form method="POST">
		<table>
			<tr>
				<td>Old password</td>
				<td><input type="password" name="oldpw"></td>
			</tr>
			<tr>
				<td>New password</td>
				<td><input type="password" name="newpw"></td>
			</tr>
			<tr>
				<td><input type="submit" name="submit"></td>
			</tr>
		</table>
	</form>
	</div>
</body>
</html>