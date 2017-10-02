#include "easyfind.hpp"
#include <list>
#include <vector>

void testWitList (void) {
	std::list<int> lst;

	lst.push_back(42);
	lst.push_back(21);
	lst.push_back(7);
	lst.push_back(3);
	easyfind(lst, 42);
	try
	{
		easyfind(lst, -42);
	}
	catch (std::exception & e)
	{
		std::cout << "Not found" << std::endl;
	}
}

void testWithVector (void) {
	std::vector<int> v;

	v.push_back(42);
	easyfind(v, 42);
	try
	{
		easyfind(v, -42);
	}
	catch (std::exception & e)
	{
		std::cout << "Not found" << std::endl;
	}
}

int main (void) {
	testWitList();
	testWithVector();
	return 0;
}