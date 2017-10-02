#!/usr/bin/php
<?PHP
	print(">> Test: 42 <<\n");
	system("./ex09/*  toto tutu 4234 \"_hop XXX\" [] \"1948372 AhAhAh\"");

	print(">> Test: no_args <<\n");
	system("./ex09/* ");

	print(">> Test: 1 arg <<\n");
	system("./ex09/*  toto");

	print(">> Test: <<\n");
	system("./ex09/* 1 2 3 a b c + - 1a\) a1\) a\)1 \)a1 \)1a");	
?>