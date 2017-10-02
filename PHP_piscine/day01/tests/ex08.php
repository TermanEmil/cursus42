#!/usr/bin/php
<?PHP
	include("ex08/ft_is_sort.php");

	function	print_is_sort($tab)
	{
		if (ft_is_sort($tab))
			echo "The array is sorted\n";
		else
			echo "The array is not sorted\n";
	}

	print(">>Test: 42<<\n");
	$tab = array("!/@#;^", "42", "Hello World", "hi", "zZzZzZz");
	$tab[] = "What are we doing now ?";
	print_is_sort($tab);

	print(">>Test: 42<<\n");
	$tab = array("!/@#;^", "42", "Hello World", "hi", "zZzZzZz");
	// $tab[] = "What are we doing now ?";
	print_is_sort($tab);

	print(">>Test: 1<<\n");
	print_is_sort(array("1", "2"));

	print(">>Test: 2<<\n");
	print_is_sort(array("1", "2", "3"));

	print(">>Test: 3<<\n");
	print_is_sort(array("3", "2"));
?>