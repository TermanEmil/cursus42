#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <cfloat>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <limits>

void process_as_char (std::string & s) {
	std::cout << "char: ";

	long long int nb = atoll(s.c_str());

	if (nb == 0) {
		if (s[0] == '0' || (s[1] == '0' && (s[0] == '-' || s[0] == '+')))
			std::cout << "0" << std::endl;
		else if (s.length() == 1 && isprint(s[0]))
			std::cout << s[0] << std::endl;
		else
			std::cout << "impossible" << std::endl;
	} else if (nb > 255 || nb < -256) {
		std::cout << "impossible" << std::endl;
	} else if (isprint(static_cast<char> (nb))) {
		std::cout << "'" << static_cast<char> (nb) << "'" << std::endl;
	}
	else {
		std::cout << "Non displayable" << std::endl;
	}
}

void process_as_int (std::string & s) {
	std::cout << "int: ";

	long long int nb = atoll(s.c_str());

	if (nb == 0) {
		if (s[0] == '0' || (s[1] == '0' && (s[0] == '-' || s[0] == '+')))
			std::cout << "0" << std::endl;
		else
			std::cout << "impossible" << std::endl;
	} else if (nb > INT_MAX || nb < INT_MIN) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << static_cast<int> (nb) << std::endl;
	}
}

void process_as_float (std::string & s) {
	std::cout << "float: ";

	double nb = atof(s.c_str());

	if (nb == 0 && (s[0] == '0' || (s[1] == '0' && (s[0] == '-' || s[0] == '+'))))
		std::cout << "0.0f" << std::endl;
	else if (static_cast<float> (nb) == INFINITY)
		std::cout << "inff" << std::endl;
	else if (static_cast<float> (nb) == -INFINITY)
		std::cout << "-inff" << std::endl;
	else if (nb < FLT_MIN || nb > FLT_MAX)
		std::cout << "impossible" << std::endl;
	else {
		if (static_cast<int> (nb) == static_cast<float> (nb))
			std::cout << static_cast<float> (nb) << ".0f" << std::endl;
		else
			std::cout << static_cast<float> (nb) << "f" << std::endl;
	}
}

void process_as_double (std::string & s) {
	std::cout << "double: ";

	double nb = atof(s.c_str());

	if (nb == 0 && (s[0] == '0' || (s[1] == '0' && (s[0] == '-' || s[0] == '+'))))
		std::cout << "0.0" << std::endl;
	else if (nb == INFINITY)
		std::cout << "inf" << std::endl;
	else if (nb == -INFINITY)
		std::cout << "-inf" << std::endl;
	else if (nb < DBL_MIN || nb > DBL_MAX)
		std::cout << "impossible" << std::endl;
	else {
		if (static_cast<int> (nb) == nb)
			std::cout << nb << ".0" << std::endl;
		else
			std::cout << nb << std::endl;
	}
}


int main(int argc, char ** argv) {
	if (argc != 2) {
		std::cout << "Program can take only 2 arguments" << std::endl;
		return 0;
	}
	std::string s(argv[1]);

	process_as_char(s);
	process_as_int(s);
	process_as_float(s);
	process_as_double(s);
	return 0;
}