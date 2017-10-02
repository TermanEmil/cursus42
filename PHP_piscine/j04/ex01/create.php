<?php
$dir = "../private/";
$file_path = $dir . "passwd";

function	check_file_existance($dir, $file_path)
{
	if (!file_exists($dir))
	{
		if (mkdir($dir, 0777) == FALSE)
		{
			echo "Couldn't create the directory $dir\n";
			exit(1);
		}
	}
	if (!file_exists($file_path))
		file_put_contents($file_path, serialize(array("")));
}

function	get_users($dir, $file_path)
{
	check_file_existance($dir, $file_path);
	if (($fserialized_content = file_get_contents($file_path)) == FALSE)
	{
		echo "Couldn't read from $file_path\n";
		exit(1);
	}
	$content = unserialize($fserialized_content);
	if ($content == FALSE)
	{
		echo "Couldn't unserialize. File is damaged\n";
		exit(1);
	}
	return ($content);
}

function	save_users($users, $dir, $file_path)
{
	check_file_existance($dir, $file_path);
	$ret = file_put_contents($file_path, serialize($users));
	echo ($ret == FALSE) ? "Couldn't write to $file_path\n" : "OK\n";
}

function	get_dex_str($key, $tab)
{
	return array_key_exists($key, $tab) ? $tab[$key] : "";
}

if (get_dex_str("submit", $_POST) == "")
{
	echo "ERROR\n";
	exit(0);
}

if (strlen(get_dex_str("login", $_POST)) == 0 || strlen(get_dex_str("passwd", $_POST)) == 0)
{
	echo "login and password can't be empty\n";
	exit(0);
}

$users = get_users($dir, $file_path);
if (array_key_exists($_POST["login"], $users))
{
	echo "ERROR\n";
	exit(0);
}
$users[$_POST["login"]] = hash("ripemd160", $_POST["passwd"]);
save_users($users, $dir, $file_path);
?>
