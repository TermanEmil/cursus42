#!/usr/bin/php
<?PHP
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

	if ($argc > 1)
	{
		$str = get_norm_spaced($argv[1]);
		if (strlen($str) > 0)
			print($str."\n");
	}
?>