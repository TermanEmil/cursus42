<?php
	function	get_dex_str($key, $tab)
	{
		return array_key_exists($key, $tab) ? $tab[$key] : "";
	}

	function	init_session()
	{
		if (!array_key_exists("login", $_SESSION))
		{
			$_SESSION["login"] = "";
			$_SESSION["passwd"] = "";
		}
	}
	session_start();
	init_session();
	if (get_dex_str("submit", $_GET) == "OK")
	{
		$_SESSION["login"] = get_dex_str("login", $_GET);
		$_SESSION["passwd"] = get_dex_str("passwd", $_GET);
	}
?>

<html>
<head>
	<title>index.php</title>
</head>
<body>
	<form action="index.php" method="GET">
		Username: <input type="text" name="login" value=<?php echo get_dex_str("login", $_SESSION); ?>>
		<br />
		Password: <input type="password" name="passwd" value=<?php echo get_dex_str("passwd", $_SESSION); ?>>
		<br />
		<input type="submit" name="submit" value="OK">
	</form>
</body>
</html>
