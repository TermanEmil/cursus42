#!/usr/bin/php
<?PHP
	include ('ex03/ft_split.php');

	print_r (ft_split("AA    Hello World"));
	print_r (ft_split("             "));
	print_r (ft_split("0 1 2 3 4 5 0"));
	print_r (ft_split("NULL False 0"));
	print_r (ft_split(1));
	print ("Null Test: \n");
	print_r (ft_split(NULL));
	print ("End of Null test\n");
?>