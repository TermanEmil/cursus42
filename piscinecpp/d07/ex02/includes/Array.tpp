#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
public:
	class IndexOutOfRange : public std::exception {
		virtual char const * what() const throw() {
			return "Index out of range";
		}
	};

	unsigned int size (void) const {return _length;};

	Array<T> (void) {
		_tab = NULL;
		_length = 0;
	};

	Array<T> (unsigned int n) {
		_tab = new T [n];
		_length = n;
		for (int i = 0; i < _length; i++)
			_tab[i] = 0;
	};

	Array<T> (Array<T> const & target) {*this = target;}

	~Array<T> (void) {
		if (_tab)
			delete _tab;
	};

	Array<T> & operator = (Array<T> const & target) {
		_length = target.size();

		if (_tab)
			delete _tab;

		_tab = new T [_length];
		
		for (int i = 0; i < _length; i++)
			_tab[i] = target[i];
		return *this;
	};

	T & operator [] (unsigned int i) const {
		if (i >= size())
			throw IndexOutOfRange();
		return _tab[i];	
	};

private:
	T * _tab;
	unsigned int _length;

};

template <typename T>
std::ostream & operator << (std::ostream & o, Array<T> const & target) {
	o << "{";
	for (int i = 0; i < target.size(); i++){
		o << target[i];
		if (i != target.size() - 1)
			o << ", ";
	}
	o << "}";

	return o;
}

#endif