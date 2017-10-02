#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <exception>

class Span
{
public:
	class OutOfBounds : public std::exception {
	public:
		virtual char const * what() const throw();
	};

	class TooFewElementsStored : public std::exception {
	public:
		virtual char const * what() const throw();
	};

	unsigned int size() const;
	std::vector<int> const & getStorage() const;

	Span (Span const & target);
	Span (unsigned int N);
	~Span (void);
	
	void addNumber(int newNb);
	int shortestSpan (void) const;
	int longestSpan (void) const;

	Span & operator = (Span const & target);

private:
	std::vector<int> _storage;
	unsigned int _N;



	Span (void);
};

std::ostream & operator << (std::ostream & o, Span const & target);

#endif