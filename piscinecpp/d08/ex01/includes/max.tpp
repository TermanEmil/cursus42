#ifndef MAX_TPP
# define MAX_TPP

template <typename T>
T const & max(T const & a, T const & b) {
	return (a >= b) ? a : b;
}


#endif