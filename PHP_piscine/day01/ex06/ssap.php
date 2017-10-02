#!/usr/bin/php
<?PHP
	function	ft_split($str)
	{
		if ($str == NULL)
			return (NULL);
		$words = explode(" ", $str);
		if ($words == NULL)
			return (NULL);
		if (sort($words) == False)
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

	if ($argc > 1)
	{
		unset($argv[0]);
		$str_table = ft_split(norm_space_all($argv));
		if ($str_table != NULL && count($str_table) > 0)
		{
			foreach ($str_table as $word)
				print("$word\n");
		}
	}
?>