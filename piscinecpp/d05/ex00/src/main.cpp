#include "Bureaucrat.hpp"

int main (void) {

	try {
		Bureaucrat a("Emil", Bureaucrat::minGrade + 1);
	} catch (std::exception const & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat a("Emil", Bureaucrat::maxGrade - 1);
	} catch (std::exception const & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat a("Emil", Bureaucrat::maxGrade);
		std::cout << "Ok" << std::endl;
		a.gradeIncrement(1);
	} catch (std::exception const & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat a("Emil", Bureaucrat::maxGrade);
		std::cout << "Ok" << std::endl;
		a.gradeDecrement(Bureaucrat::minGrade);
	} catch (std::exception const & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}