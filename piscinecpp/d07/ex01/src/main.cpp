#include <iostream>
#include <string>

template <typename T>
void iter(T * tab, size_t tabLen, void (&f)(T *)) {
	for (size_t i = 0; i < tabLen; i++) {
		f(&(tab[i]));
	}
}

void printInt (int * a) {
	std::cout << *a << std::endl;
}

void printStr (std::string * a) {
	std::cout << *a << std::endl;
}

void printStrPtr (std::string ** a) {
	if (*a == NULL)
		std::cout << "(null)" << std::endl;
	else
		std::cout << **a << std::endl;
}

int main (void) {
	int * a = new int[10];
	for (int i = 0; i < 10; i++) {
		a[i] = 42;
	}
	iter(a, 10, printInt);

	std::cout << std::endl;

	std::string * str = new std::string[10];
	for (int i = 0; i < 10; i++)
		str[i] = "Emil";
	iter(str, 10, printStr);

	std::cout << std::endl;

	std::string ** strs = new std::string * [10];
	for (int i = 0; i < 10; i++)
		strs[i] = new std::string("Emil");
	strs[5] = NULL;
	iter(strs, 10, printStrPtr);
}