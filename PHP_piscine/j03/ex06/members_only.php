<?php
	$user_key = "PHP_AUTH_USER";
	$password_key = "PHP_AUTH_PW";
	$desired_user = "zaz";
	$desired_pwd = "jaimelespetitsponeys";
	if (array_key_exists($user_key, $_SERVER) && array_key_exists($password_key, $_SERVER))
	{
		if ($_SERVER[$user_key] == $desired_user && $_SERVER[$password_key] == $desired_pwd)
		{
			$im = file_get_contents('../img/42.png');
			$imdata = base64_encode($im);
			echo "<html><body>Bonjour Zaz<br /><img src='data:image/png;base64,$imdata'></body></html>";
		}
		else
		{
			header("WWW-Authenticate: Basic realm=''Espace membres''");
			header("HTTP/1.0 401 Unauthorized");
			echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>\n";
		}
	}
?>
