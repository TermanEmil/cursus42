#!/usr/bin/php
<?PHP
	if ($argc == 1)
		return (0);
	if (!($content = file_get_contents($argv[1])))
		return (0);

	function	title_match($str)
	{
		return preg_replace_callback('/([a-z]+\s*=\s*)("[^"]*")/', function($matches)
		{
			return $matches[1] . strtoupper($matches[2]);
		}, $str);
	}

	function	between_match($str)
	{
		return preg_replace_callback('/([^<]*)(<([^>]*)>)?/', function($matches)
		{
			return 
				strlen($matches[1]) == 0 ? "" : strtoupper($matches[1]) .
				(count($matches) != 4 ? "" : (strlen($matches[3]) == 0 ? "" : "<" . title_match($matches[3]) . ">"));
		}, $str);
	}

	function	link_match($str)
	{
		return preg_replace_callback('/<a([^>]*)>(.+?)<\/a>/s', function($matches)
			{
				return "<a" . title_match($matches[1]) . ">" . between_match($matches[2]) . "</a>";
			}, $str);
	}
	print (link_match($content)."\n");
?>