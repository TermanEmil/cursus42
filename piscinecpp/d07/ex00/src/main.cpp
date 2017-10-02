#include <iostream>
#include <string>

template <typename T>
void swap(T & a, T & b) {
	T aux = a;
	a = b;
	b = aux;
}

template <typename T>
T const & min(T const & a, T const & b) {
	return (a < b) ? a : b;
}

template <typename T>
T const & max(T const & a, T const & b) {
	return (a >= b) ? a : b;
}

void testSwap (void) {
	int a = 10;
	int b = 20;
	
	swap(a, b);
	std::cout << a << std::endl;
}

void testMin (void) {
	std::cout << min(10, 20) << std::endl;
}

void testMax (void) {
	std::cout << max(10, 20) << std::endl;
}

int main (void) {

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}