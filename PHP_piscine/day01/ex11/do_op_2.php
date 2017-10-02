#!/usr/bin/php
<?PHP
	function	valid_argv($argv)
	{
		if (
			count($argv) == 3 &&
			is_numeric($argv[0]) &&
			is_numeric($argv[2]) &&
			strchr("+-/%*", $argv[1]) && strlen($argv[1]) == 1)
			return (True);
		return (False);
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

	function	split_by_opperator($str, $opp)
	{
		if (strstr($str, $opp))
			return (join(" $opp ", array_filter(explode($opp, $str), 'strlen')));
		return (False);
	}

	$delims = " \n\t\013\014\015";
	$opps = "*/%+-";
	
	if ($argc != 2)
	{
		print("Incorrect Parameters\n");
		return (0);
	}
	$str = $argv[1];
	for ($i = 0; $i < 5; $i++)
	{
		$ret = split_by_opperator($str, $opps[$i]);
		if ($ret != False)
		{
			$str = $ret;
			break;
		}
	}
	$params = explode(" ", get_norm_spaced($str));
	if (!valid_argv($params))
	{
		print("Syntax Error\n");
		return (0);
	}
	switch ($params[1])
	{
		case "+":
			print ($params[0] + $params[2]);
			break;
		case "-":
			print ($params[0] - $params[2]);
			break;
		case "/":
			print ($params[0] / $params[2]);
			break;
		case "%":
			print ($params[0] % $params[2]);
			break;
		case "*":
			print ($params[0] * $params[2]);
			break;
		default:
			print("Syntax Error");
			break;
	}
	print("\n");
?>