#!/usr/bin/php
<?PHP
	function	get_norm_spaced($str)
	{
		$str = join(" ", array_filter(explode(" ", $str), 'strlen'));
		return ($str);
	}

	function	ft_split($str)
	{
		if ($str == NULL)
			return (NULL);
		$words = explode(" ", $str);
		if ($words == NULL)
			return (NULL);
		return (array_filter($words, 'strlen'));
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

	function	swap_last_element($words)
	{
		if ($words != NULL && count($words) > 1)
		{
			$i = count($words) - 1;
			$tmp = $words[$i];
			$words[$i] = $words[0];
			$words[0] = $tmp;
			return ($words);
		}
		return ($words);
	}

	if ($argc > 1)
	{
		unset($argv[0]);
		$words = swap_last_element(ft_split(norm_space_all($argv)));
		if ($words != NULL && count($words) > 0)
		{
			if (count($words) != 1)
				unset($words[0]);
			print_words($words);
		}
	}
?>