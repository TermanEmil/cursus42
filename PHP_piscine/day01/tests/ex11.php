#!/usr/bin/php
<?PHP
	print(">>Test: 42 - 0<<\n");
	system("./ex11/*");

	print(">>Test: 42 - 1<<\n");
	system("./ex11/* toto");

	print(">>Test: 42 - 2<<\n");
	system("./ex11/* \"42*2\"");

	print(">>Test: 42 - 3<<\n");
	system("./ex11/* \" 42 / 2 \"");	

	print(">>Test: 42 - 4<<\n");
	system("./ex11/*  \"six6*7sept\"");	

	print(">>Test: 42 - 5<<\n");
	system("./ex11/*  '`rm -rf ~/`;'");	

	print(">>Test: 10*-1<<\n");
	system("./ex11/*  \"10*-1\" ");

	print(">>Test: 10--1<<\n");
	system("./ex11/*  \"10--1\" ");		

	print(">>Test: -1*10<<\n");
	system("./ex11/*  \"-1*10\" ");

	print(">>Test: -0*-0<<\n");
	system("./ex11/*  \"-0*-0\" ");	

	print(">>Test: 0<<\n");
	system("./ex11/*  \"0\" ");
?>