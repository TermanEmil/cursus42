#!/usr/bin/php
<?PHP
	function	str_is_numeric($str)
	{
		if ($str == "\n")
			return (False);
		$chars = str_split($str);
		foreach ($chars as $c)
		{
			if ($c == "\n")
				break ;
			if (!is_numeric($c))
				return (False);
		}
		return (True);
	}

	if (STDIN)
	{
		echo("Entrez un nombre: ");
		while (($str = fgets(STDIN, 4096)))
		{
			$str = trim($str, "\n");
			$old_str = $str;
			$str = trim($str);
			if (!str_is_numeric($str))
			{
				print("'$old_str' n'est pas un chiffre\n");
			}
			else
			{
				if ($str % 2 == 0)
					print("Le chiffre $str est Pair\n");
				else
					print("Le chiffre $str est Impair\n");
			}
			echo("Entrez un nombre: ");
		}
	}
	echo("\n");
?>