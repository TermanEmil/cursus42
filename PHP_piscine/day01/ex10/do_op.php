#!/usr/bin/php
<?PHP
	function	valid_argv($argv)
	{
		if (
			is_numeric($argv[0]) &&
			is_numeric($argv[2]) &&
			strchr("+-/%*", $argv[1]) && strlen($argv[1]) == 1)
			return (True);
		return (False);
	}

	$delims = " \n\t\013\014\015";

	if ($argc != 4)
	{
		print("Incorrect Parameters\n");
		return (0);
	}
	unset($argv[0]);
	$new_argv = [];
	foreach ($argv as $word)
		$new_argv[] = trim($word, $delims);
	$argv = $new_argv;
	if (!valid_argv($argv))
	{
		print("Incorrect Parameters\n");
		return (0);
	}
	switch ($argv[1])
	{
		case "+":
			print ($argv[0] + $argv[2]);
			break;
		case "-":
			print ($argv[0] - $argv[2]);
			break;
		case "/":
			print ($argv[0] / $argv[2]);
			break;
		case "%":
			print ($argv[0] % $argv[2]);
			break;
		case "*":
			print ($argv[0] * $argv[2]);
			break;
		default:
			print("Incorrect Parameters");
			break;
	}
	print("\n");
?>