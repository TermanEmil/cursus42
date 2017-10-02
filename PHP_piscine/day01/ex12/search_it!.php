#!/usr/bin/php
<?PHP
	function	read_dex($argv, $argc)
	{
		$dex = [];
		for ($i = 2; $i < $argc; $i++)
		{
			if (strstr($argv[$i], ":") != NULL)
			{
				$tab = explode(":", $argv[$i], 2);
				if (count($tab) == 2)
					$dex[$tab[0]] = $tab[1];
			}
		}
		return ($dex);
	}
	if ($argc < 3)
		return (0);
	$dex = read_dex($argv, $argc);
	if (array_key_exists($argv[1], $dex))
		print($dex[$argv[1]]."\n");
?>