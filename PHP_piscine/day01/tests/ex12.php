#!/usr/bin/php
<?PHP
	print(">>Test: 42 - 0\n");
	system("./ex12/*");

	print(">>Test: 42 - 1\n");
	system("./ex12/*  toto");

	print(">>Test: 42 - 2\n");
	system("./ex12/*  toto \"key1:val1\" \"key2:val2\" \"toto:42\"");

	print(">>Test: 42 - 3\n");
	system("./ex12/*   toto \"toto:val1\" \"key2:val2\" \"toto:42\"");

	print(">>Test: 42 - 4\n");
	system("./ex12/*  \"toto\" \"key1:val1\" \"key2:val2\" \"0:hop\"");

	print(">>Test: 42 - 5\n");
	system("./ex12/*   \"0\" \"key1:val1\" \"key2:val2\" \"0:hop\"");

	print(">>Test: my - 0\n");
	system("./ex12/* toto 'toto:em:il'");
?>