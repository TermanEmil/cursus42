#!/usr/bin/php
<?PHP
	function	ft_error()
	{
		echo "Wrong Format\n";
		return (0);
	}

	function	valid_clock($clock_str)
	{
		return (preg_match("/^(([01][0-9])|([2][0-3])):[0-5][0-9]:[0-5][0-9]$/",
			$clock_str));
	}

	function	is_leap_year($year)
	{
		return ((($year % 4) == 0) && ((($year % 100) != 0) || (($year % 400) == 0)));
	}

	function	get_days_in_month($m, $y)
	{
		switch ($m)
		{
			case 1:
				return (is_leap_year($y)) ? 29 : 28;
			
			case 8:
			case 3:
			case 5:
			case 10:
				return (30);

			default:
				return (31);
		}
	}

	function	ft_indexof($table, $el)
	{
		for ($i = 0; $i < count($table); $i++)
			if (preg_match("/^".$table[$i]."$/", $el))
				return ($i);
		return (-1);
	}

	function	check_format($months, $argv)
	{
		$days = ["[lL]undi", "[mM]ardi", "[mM]ercredi", "[jJ]eudi",
			"[vV]endredi", "[sS]amedi", "[dD]imanche"];


		$days_expr = "(".join("|", $days).")";
		$months_expr = "(".join("|", $months).")";

		$date_expr = "(([0-2][0-9])|(3[01]))";
		$clock_expr = "(([01][0-9])|([2][0-3])):[0-5][0-9]:[0-5][0-9]";
		$year_expr = "((19[7-9][0-9])|([2-9][0-9]{3}))";

		$expr = "/^" . $days_expr . " " . $date_expr . " " . $months_expr . " " .
			$year_expr . " " . $clock_expr . "$/";

		if (!preg_match($expr, $argv))
			return (-1);

		$parts = preg_split("/ /", $argv);

		if ($parts[1] > get_days_in_month(ft_indexof($months, $parts[2]), $parts[3]))
			return (-1);
		return (0);
	}

	if ($argc == 1)
		return (0);

	date_default_timezone_set('Europe/Paris');

	$months = ["[jJ]anvier", "(([fF]évrier)|([fF]evrier))", "[mM]ars", "[aA]vril", "[mM]ai",
		"[jJ]uin", "[jJ]uillet", "(([aA]oût)|([aA]out))", "[sS]eptembre", "[oO]ctobre",
		"[nN]ovembre", "(([dD]écembre)|([dD]ecembre))"];

	if (check_format($months, $argv[1]) == -1)
		return (ft_error());

	$parts = preg_split("/ /", $argv[1]);
	$clock = preg_split("/:/", $parts[4]);
	$tm = mktime($clock[0], $clock[1], $clock[2], ft_indexof($months, $parts[2]) + 1, $parts[1], $parts[3]);
	print("$tm\n");
?>