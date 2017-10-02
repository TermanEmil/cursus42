#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm (void) :
	Form("RobotomyRequestForm", 72, 45, "NoTarget")
{}

RobotomyRequestForm::RobotomyRequestForm (RobotomyRequestForm const & t) :
	Form("RobotomyRequestForm", 72, 45, t.getTarget())
{
	setIsSigned(t.getIsSigned());
}

RobotomyRequestForm::RobotomyRequestForm (std::string const & target) :
	Form("RobotomyRequestForm", 72, 45, target)
{}

RobotomyRequestForm::~RobotomyRequestForm (void) {}

void RobotomyRequestForm::execute (Bureaucrat const & executor) const {
	Form::execute(executor);

	std::cout << "Drilling noise..." << std::endl;
	if (rand() % 2 == 0)
		std::cout << getName() << " has been robotimized successfully" << std::endl;
	else
		std::cout << "Robotization: FAIL" << std::endl;
}

//Operators
RobotomyRequestForm & RobotomyRequestForm::operator = (RobotomyRequestForm const & target)
{
	setIsSigned(target.getIsSigned());
	return *this;
}

std::ostream & operator << (std::ostream & o, RobotomyRequestForm const & target) {
	o << static_cast<Form> (target);
	return o;
}