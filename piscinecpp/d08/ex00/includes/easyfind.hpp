#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <typeinfo>

template <typename T>
void easyfind (T & container, int toFind) {
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw std::exception();
	else
		std::cout << "Found element" << std::endl;
}

#endif