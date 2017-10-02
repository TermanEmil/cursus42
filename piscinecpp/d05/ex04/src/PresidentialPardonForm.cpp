#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm (void) :
	Form("PresidentialPardonForm", 25, 5, "NoTarget")
{}

PresidentialPardonForm::PresidentialPardonForm (PresidentialPardonForm const & t) :
	Form("PresidentialPardonForm", 25, 5, t.getTarget())
{
	setIsSigned(t.getIsSigned());
}

PresidentialPardonForm::PresidentialPardonForm (std::string const & target) :
	Form("PresidentialPardonForm", 25, 5, target)
{}

PresidentialPardonForm::~PresidentialPardonForm (void) {}

void PresidentialPardonForm::execute (Bureaucrat const & executor) const {
	Form::execute(executor);

	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

//Operators
PresidentialPardonForm & PresidentialPardonForm::operator = (PresidentialPardonForm const & target)
{
	setIsSigned(target.getIsSigned());
	return *this;
}

std::ostream & operator << (std::ostream & o, PresidentialPardonForm const & target) {
	o << static_cast<Form> (target);
	return o;
}