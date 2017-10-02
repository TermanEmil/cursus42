#include "span.hpp"
#include <limits.h>

unsigned int Span::size() const {return _storage.size();}
std::vector<int> const & Span::getStorage() const {return _storage;}

Span::Span (void) {
	_N = 0;
}

Span::Span (Span const & target) {*this = target;}
Span::Span (unsigned int N) {_N = N;}
Span::~Span (void) {}

void Span::addNumber (int newNb) {
	if (_storage.size() >= _N)
		throw OutOfBounds();
	else
		_storage.push_back(newNb);
}

int Span::shortestSpan (void) const {
	if (_N <= 1)
		throw TooFewElementsStored();

	std::vector<int> tmp = _storage;
	std::sort(tmp.begin(), tmp.end());

	int min = INT_MAX;
	int i = 0;
	std::vector<int>::iterator it;

	for (it = tmp.begin() + 1; it < tmp.end(); it++) {
		if (*it - it[-1] < min)
			min = *it - it[-1];
	}
	
	return min;
}

int Span::longestSpan (void) const {
	if (_N <= 1)
		throw TooFewElementsStored();

	return *std::max_element(_storage.begin(), _storage.end()) -
		*std::min_element(_storage.begin(), _storage.end());
}

//Operators
Span & Span::operator = (Span const & target) {
	_storage.clear();
	_N = target.size();
	for (int i = 0; i < _N; i++)
		_storage.push_back(target.getStorage()[i]);
}

std::ostream & operator << (std::ostream & o, Span const & target) {
	o << "{";
	if (target.size() > 0) {
		for (int i = 0; i < target.size(); i++) {
			o << target.getStorage()[i];
			if (i != target.size() - 1)
				o << ", ";
		}
	}
	o << "}" << std::endl;
}

//Exceptions
char const * Span::OutOfBounds::what() const throw() {
	return "Out of bounds";
}

char const * Span::TooFewElementsStored::what() const throw() {
	return "Too few elements stored";
}