#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <sstream>

ShrubberyCreationForm::ShrubberyCreationForm (void) :
	Form("ShrubberyCreationForm", 145, 137, "NoTarget")
{}

ShrubberyCreationForm::ShrubberyCreationForm (ShrubberyCreationForm const & t) :
	Form("ShrubberyCreationForm", 145, 137, t.getTarget())
{
	setIsSigned(t.getIsSigned());
}

ShrubberyCreationForm::ShrubberyCreationForm (std::string const & target) :
	Form("ShrubberyCreationForm", 145, 137, target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm (void) {}

void ShrubberyCreationForm::execute (Bureaucrat const & executor) const {
	Form::execute(executor);

	std::ofstream file;
	std::stringstream s;
	s << getTarget() << "_shrubbery";
	file.open (s.str().c_str());
	if (!file)
		throw CouldntCreateFile();
	file << "Some ASCII trees...";
	file.close();
}

//Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator = (ShrubberyCreationForm const & target)
{
	setIsSigned(target.getIsSigned());
	return *this;
}

std::ostream & operator << (std::ostream & o, ShrubberyCreationForm const & target) {
	o << static_cast<Form> (target);
	return o;
}

//Exceptions
char const * ShrubberyCreationForm::CouldntCreateFile::what() const throw() {
	return "Couldn't create file";
}