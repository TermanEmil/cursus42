#include "Intern.hpp"

Intern::Intern (void) {}
Intern::Intern (Intern const & target) {*this = target;}
Intern::~Intern (void) {}

//Methods
Form * Intern::makeForm (std::string const & formName, std::string const & formTarget) {
	Form * form = NULL;

	if (formName == "shrubbery request")
		form = new ShrubberyCreationForm(formTarget);
	else if (formName == "robotomy request")
		form = new RobotomyRequestForm(formTarget);
	else if (formName == "presidential pardon request")
		form = new PresidentialPardonForm(formTarget);
	if (form == NULL)
		throw NoSuchForm();
	else {
		std::cout << "Intern creates " << *form;
		return form;
	}
}

//Operators
Intern & Intern::operator = (Intern const & target) {
	(void)target;
	return *this;
}

std::ostream & operator << (std::ostream & o, Intern const & target) {
	(void)target;
	o << "A poor intern..." << std::endl;
	return o;
}

//Excetions
char const * Intern::NoSuchForm::what() const throw() {
	return "No such form";
}