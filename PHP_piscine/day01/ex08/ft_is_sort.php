#!/usr/bin/php
<?PHP
	function	ft_is_sort($words)
	{
		if ($words == NULL)
			return (True);
		$sorted = $words;
		sort($sorted);
		return (strcmp(join("", $words), join("", $sorted)) == 0);
	}
?>