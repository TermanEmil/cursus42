#!/usr/bin/php
<?PHP
	function	ft_system($cmd)
	{
		echo $cmd."\n";
		system($cmd);
	}

	echo ">>Test: 0\n";
	ft_system("./ex01/*  \"Mardi 12 Novembre 2013 12:02:21\"");

	echo ">>Test: 1\n";
	ft_system("./ex01/*  \"Mardi 29 février 2013 12:02:21\"");
	echo "Should be wrong format\n";

	echo ">>Test: 2\n";
	ft_system("./ex01/*  \"Mardi 28 février 2013 12:02:21\"");
	echo "Should be fine\n";

	echo ">>Test: 3\n";
	ft_system("./ex01/*  \"Mardi 29 février 2016 12:02:21\"");
	echo "Should be fine\n";

	echo ">>Test: 4\n";
	ft_system("./ex01/*  \"Mardi 29 février 1969 12:02:21\"");
	echo "Should be wrong format\n";

	echo ">>Test: 5\n";
	ft_system("./ex01/*  \"Mardi 9 février 2013 12:02:21\"");
	echo "Should be wrong format\n";

	echo ">>Test: 4\n";
	ft_system("./ex01/*  \"Mard 25 février 2013 12:02:21\"");
	echo "Should be wrong format\n";

	echo ">>Test: 4\n";
	ft_system("./ex01/*  \"Mardi 25 février  2013 12:02:21\"");
	echo "Should be wrong format\n";

	echo ">>Test: 4\n";
	ft_system("./ex01/*  \"Mardi 25 février 2013 24:02:21\"");
	echo "Should be wrong format\n";

	echo ">>Test: 4\n";
	ft_system("./ex01/*  \"Mardi 25 février 2013 12:60:21\"");
	echo "Should be wrong format\n";

	echo ">>Test: 4\n";
	ft_system("./ex01/*  \"M.rdi 12 Novembre 2013 12:02:21\"");
	echo "Should be wrong format\n";

	echo ">>Test: 4\n";
	ft_system("./ex01/*  \"\"");
	echo "Should be wrong format\n";
?>