#!/usr/bin/php
<?PHP
	system("./ex06/*.php foo bar \"yo man\" \"A moi compte, deux mots\" Xibul");
	print(">>>>>Test2:<<<<<<<\n");
	system("./ex06/*.php foo bar \"yo man\" \"A moi	\t\t\ncompte, deux mots\" Xibul");
	print(">>>>>Test3: just spaces<<<<<<<\n");
	system("./ex06/*.php \"   \" ");
	print(">>>>>Test3: no args<<<<<<<\n");
	system("./ex06/*.php");
?>
