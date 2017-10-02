<?php
$dir = "../private/";
$file_path = $dir . "passwd";
$hash_alg = "ripemd160";

function	ft_err()
{
	echo "ERROR\n";
	exit(0);
}

function	get_dex_str($key, $tab)
{
	return array_key_exists($key, $tab) ? $tab[$key] : "";
}

function	check_file_existance()
{
	global $dir, $file_path, $hash_alg;
	
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

function	get_users()
{
	global $dir, $file_path, $hash_alg;
	
	check_file_existance();
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

function	save_users($users)
{
	global $dir, $file_path, $hash_alg;
	
	check_file_existance();
	$ret = file_put_contents($file_path, serialize($users));
	echo ($ret == FALSE) ? "Couldn't write to $file_path\n" : "OK\n";
}

function	auth($login, $passwd)
{
	global $dir, $file_path, $hash_alg;

	$users = get_users($dir, $file_path);
	return (array_key_exists($login, $users) && $users[$login] == hash($hash_alg, $passwd));
}
?>
