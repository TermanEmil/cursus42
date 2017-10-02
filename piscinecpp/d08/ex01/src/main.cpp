#include "span.hpp"
#include <stdlib.h>
#include <time.h>

int main (void) {
	int n = 1000000;
	srand(time(NULL));
	Span sp = Span(n);
	
	for (int i = 0; i < n; i++)
		sp.addNumber(rand() - rand());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(42);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Span sp2 = Span(1);
		sp2.addNumber(1);
		sp2.shortestSpan();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}