#!/usr/bin/php
<?PHP
print(">>Test: 42 -> 0\n");
system("./ex00/*  \"This sentence 	contains      \t\tspaces				 and some tabulations\"");

print(">>Test: 42 -> 1\n");
system("./ex00/*");

print(">>Test: 42 -> 2\n");
system("./ex00/*  \" This arg\t\t is\t used \" \"but not this one\"");

print(">>Test: my -> only spaces\n");
system("./ex00/* '\t\t\t   \t' ");
?>