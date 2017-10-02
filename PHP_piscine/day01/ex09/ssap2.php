#!/usr/bin/php
<?PHP
	function	ft_split($str)
	{
		if ($str == NULL)
			return (NULL);
		$words = explode(" ", $str);
		if ($words == NULL)
			return (NULL);
		return (array_filter($words, 'strlen'));
	}

	function	get_norm_spaced($str)
	{
		$str = join(" ", array_filter(explode("\t", $str), 'strlen'));
		$str = join(" ", array_filter(explode("\n", $str), 'strlen'));
		$str = join(" ", array_filter(explode("\013", $str), 'strlen'));
		$str = join(" ", array_filter(explode("\014", $str), 'strlen'));
		$str = join(" ", array_filter(explode("\015", $str), 'strlen'));
		$str = join(" ", array_filter(explode(" ", $str), 'strlen'));
		return ($str);
	}

	function		norm_space_all($sentences)
	{
		$buf = "";
		foreach ($sentences as $sentence)
			$buf = $buf . " " . get_norm_spaced($sentence);
		return (get_norm_spaced($buf));
	}

	function	print_words($words)
	{
		if ($words != NULL && count($words) > 0)
		{
			$words = array_filter($words, 'strlen');
			if ($words != NULL && count($words) > 0)
				print(join("\n", $words)."\n");
		}
	}

	function	is_alphabetic($c)
	{
		return (($c >= "a" && $c <= "z") || ($c >= "A" && $c <= "Z"));
	}

	function	my_strcmp($str1, $str2)
	{
		$str1 = strtolower($str1);
		$str2 = strtolower($str2);
		$len = min(strlen($str1), strlen($str2));
		for ($i = 0; $i < $len; $i++)
		{
			if ($str1[$i] != $str2[$i])
			{
				if (is_alphabetic($str1[$i]))
				{
					if (is_alphabetic($str2[$i]))
						return (ord($str1[$i]) - ord($str2[$i]));
					else
						return (-1);
				}
				else if (is_alphabetic($str2[$i]))
					return (1);
				if (is_numeric($str1[$i]))
				{
					if (is_numeric($str2[$i]))
						return (ord($str1[$i]) - ord($str2[$i]));
					else
						return (-1);
				}
				else if (is_numeric($str2[$i]))
					return (1);
				return (ord($str1[$i]) - ord($str2[$i]));
			}
		}
		return (strlen($str1) - strlen($str2));
	}

	if ($argc > 1)
	{
		$words = $argv;
		unset($words[0]);
		if ($words != NULL && count($words) > 0)
		{
			$words = ft_split(norm_space_all($words));
			if ($words != NULL && count($words) > 0)
			{
				usort($words, "my_strcmp");
				print_words($words);
			}
		}
	}
?>