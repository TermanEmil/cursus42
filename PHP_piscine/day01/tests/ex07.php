#!/usr/bin/php
<?PHP
	print(">>>Test: no args<<<\n");
	system("./ex07/rostring.php ");

	print(">>>Test: one arg<<<\n");
	system("./ex07/rostring.php 1");

	print(">>>Test: 2 args<<<\n");
	system("./ex07/rostring.php 1 2");

	print(">>>Test: 3 args<<<\n");
	system("./ex07/rostring.php 1 2 3");

	print(">>>Test: 42 - 0<<<\n");
	system("./ex07/rostring.php sdfkjsdkl sdkjfskljdf");

	print(">>>Test: 42 - 1<<<\n");
	system("./ex07/rostring.php \"hello world aaa\" fslkdjf");	
?>