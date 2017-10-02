<?php

$passwd_dir = "../private/";
$users_file = "passwd";
$hash_alg = "ripemd160";

/*
** Returns an empty string if the key isn't set.
*/

function	get_dex_str($key, $tab)
{
	return array_key_exists($key, $tab) ? $tab[$key] : "";
}

/*
** Checks if passwd_dir exists. Creates $passwd_dir if it doesn't exists.
** Puts an empty array, so I don't have problems with usnerialization errors.
*/

function	check_passwd_existance()
{
	global $passwd_dir, $users_file;

	$created = FALSE;
	if (!file_exists($passwd_dir))
	{
		if (mkdir($passwd_dir, 0777) == FALSE)
		{
			echo "Couldn't create the directory $passwd_dir\n";
			exit(1);
		}
		$created = TRUE;
	}
	if (!file_exists($passwd_dir . $users_file))
	{
		file_put_contents($passwd_dir . $users_file, serialize(array("")));
		$created = TRUE;
	}
}

/*
** Returns a dictionary with all registered users.
*/

function	get_users()
{
	global $passwd_dir, $users_file;

	check_passwd_existance();
	$fserialized_content = file_get_contents($passwd_dir . $users_file);
	if ($fserialized_content == FALSE)
	{
		echo "Couldn't read from $passwd_dir$users_file\n";
		exit(1);
	}
	$content = unserialize($fserialized_content);
	if ($content == FALSE)
	{
		echo "Couldn't unserialize. File is damaged\n";
		exit(1);
	}
	return (array_filter($content));
}

/*
** Saves the users to the $passwd_dir . $users_file.
** If I don't set $users = array(""); when it's empty, I will have problems
** with unserialization.
*/

function	save_users($users)
{
	global $passwd_dir, $users_file;
	
	check_passwd_existance();
	if (count($users) == 0)
		$users = array("");
	$ret = file_put_contents($passwd_dir . $users_file, serialize($users));
	echo ($ret == FALSE) ? "Couldn't write to $passwd_dir$users_file\n" : "";
}

/*
** Checks if the given $login and $passwd are registred.
** reutrns 0 if it's registered and the password is valid.
*/

function	auth($login, $passwd)
{
	global $hash_alg;

	$users = get_users();
	if (!array_key_exists($login, $users))
		return (-1);
	if ($users[$login]["passwd"] != hash($hash_alg, $passwd))
		return (-2);
	return (0);
}

function	login_exists($login, $users)
{
	return (array_key_exists($login, $users));
}

function	add_user($new_user)
{
	$users = get_users();
	if (login_exists($new_user["login"], $users))
		return ("Already registered");
	$users[$new_user["login"]] = $new_user;
	save_users($users);
	return (0);
}

/*
** Unsets a user with given login.
*/

function	unregister($login)
{
	$users = get_users();
	if (!login_exists($login, $users))
		return ("Not registered");
	unset($users[$login]);
	save_users($users);
}

function	unregister_all()
{
	save_users(array(""));
}

function	new_user($login, $passwd)
{
	global $hash_alg;

	if (array_key_exists($login, get_users()))
		return ("Already registered");
	$user["login"] = $login;
	$user["passwd"] = hash($hash_alg, $passwd);
	add_user($user);
	return (0);
}

function	set_current_user($login)
{
	$_SESSION["loggued_on_user"] = $login;
}

function	display_user_menu()
{
	if (!isset($_SESSION["loggued_on_user"]))
		return ;
	echo '
	<div align="right">
		Logged in as: <a href="modif.php">' . $_SESSION["loggued_on_user"] . '</a>
		<br />
		<a href=index.php?logout=true>Logaut</a>
		<br />
		<a href="speak.php">Chat</a>
		<hr>
	</div>
	';
}

function	create_if_isnt($path)
{
	if (!file_exists($path))
	{
		file_put_contents($path, serialize(array("")), LOCK_EX);
	}
}

function	get_chat()
{
	create_if_isnt("../private/chat");
	$fd = fopen("../private/chat", "r");
	flock($fd, LOCK_SH);
	$contents = file_get_contents("../private/chat");
	flock($fd, LOCK_UN);
	fclose($fd);
	return (unserialize($contents));
}

function	save_chat($chat)
{
	create_if_isnt("../private/chat");
	file_put_contents("../private/chat", serialize($chat), LOCK_EX);
}

function	append_to_chat($msg)
{
	$chat = get_chat();
	$chat[] = $msg;
	save_chat($chat);
}

function	create_raw_msg($content)
{
	$msg = '<div class="msg">';
	$msg .= '[' . date('i:s') . ']: ';
	$msg .= $content;
	$msg .= '</div>';
	append_to_chat($msg);
}

function	create_msg($content)
{
	$msg = '<div class="msg">';
	$msg .= '[' . date('i:s') . '] <b>' . $_SESSION['loggued_on_user'] . '</b>: ';
	$msg .= $content;
	$msg .= '</div>';
	append_to_chat($msg);
}

?>