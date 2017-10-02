#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <stdlib.h>
#include <time.h>

int main (void) {
	srand(time(NULL));

	Intern leosha;
	Form * aForm;

	aForm = leosha.makeForm("shrubbery request", "Unicorn");
	delete aForm;

	aForm = leosha.makeForm("robotomy request", "Unicorn");
	delete aForm;

	aForm = leosha.makeForm("presidential pardon request", "Unicorn");
	delete aForm;

	try
	{
		aForm = leosha.makeForm("Some inexistent form", "Unicorn");
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}