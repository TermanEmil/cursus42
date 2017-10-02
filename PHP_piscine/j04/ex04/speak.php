<?php
	include("auth.php");

	session_start();

	display_user_menu();
	date_default_timezone_set('UTC');
	if (isset($_POST["submit_msg"]) &&
		isset($_POST["msg"]) &&
		strlen($_POST["msg"]) > 0 &&
		$_POST["submit_msg"] == "OK")
	{
		if ($_POST["msg"] == "sudo clear chat")
		{
			save_chat(array(""));
		}
		else
			create_msg($_POST["msg"]);
		header('Location: speak.php');
	}
?>

<html>
<head>
	<title>speak</title>
	<style type="text/css">
		#input_field {
			height: 40px;
			width: 89%;
		}

		#btn {
			height: 40px;
			width: 10%;
		}

		#chat_window {
			height: 550px;
			width: 90%;
			background-color: pink;
		}

	</style>
</head>
<body>
	<div align="center">
		<iframe id="chat_window" src="chat.php"></iframe>
		<br />
		<form method="POST" action="speak.php">
			<div>
				<input id="input_field" type="text" name="msg">
				<input id="btn" type="submit" name="submit_msg" value="OK">
			</div>
		</form>
	</div>
</body>
</html>