<?php

	if (count($_GET) == 0 || !array_key_exists("action", $_GET) || !array_key_exists("name", $_GET))
		return (0);
	if ($_GET["action"] == "set")
	{
		if (!array_key_exists("value", $_GET))
			return (0);
		if (!setcookie($_GET["name"], $_GET["value"], time() + 60 * 60 * 24 * 7, "/"))
			echo "Couldn't set a cookie...\n";
	}
	else if ($_GET["action"] == "get")
	{
		if (!setcookie($_GET["name"], $_GET["value"], time() + 60 * 60 * 24 * 7, "/"))
			echo "Couldn't set a cookie...\n";
		if ($_GET["name"] == "all")
			foreach ($_COOKIE as $key => $value)
				echo "$key: $value\n";
		else
		{
			if (!array_key_exists($_GET["name"], $_COOKIE))
				return (0);
			else
				echo $_COOKIE[$_GET["name"]]."\n";
		}
	}
	else if ($_GET["action"] == "del")
	{
		if (!setcookie($_GET["name"], "", time() - 10000, "/"))
			echo "Couldn't set a cookie...\n";
	}
?>