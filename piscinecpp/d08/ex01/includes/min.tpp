#ifndef MIN_TPP
# define MIN_TPP

template <typename T>
T const & min(T const & a, T const & b) {
	return (a < b) ? a : b;
}

#endif