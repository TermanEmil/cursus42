#!/usr/bin/php
<?PHP
if ($argc == 1)
	return (0);
$str = join(" ", array_filter(preg_split("/[\s\t]+/", $argv[1]), 'strlen'));
if (!preg_match("/^$/", $str))
	echo "$str\n";
?>