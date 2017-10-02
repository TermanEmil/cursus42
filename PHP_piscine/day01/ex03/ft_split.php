#!/usr/bin/php
<?PHP
	function ft_split($str)
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
?>