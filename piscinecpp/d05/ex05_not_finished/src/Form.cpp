#include "Form.hpp"

std::string const & Form::getName (void) const {return _name;}
int Form::getGradeToSign (void) const {return _requiredGradeToSign;}
int Form::getGradeToExec (void) const {return _requiredGradeToExec;}
bool Form::getIsSigned (void) const {return _isSigned;}
std::string const & Form::getTarget (void) const {return _target;}

//Constructors && destructors
Form::Form (void) : _name("Form"),
	_requiredGradeToSign(Bureaucrat::minGrade),
	_requiredGradeToExec(Bureaucrat::minGrade),
	_target("NoTarget")
{
	_isSigned = false;
}

Form::Form (Form const & target) : _name(target.getName()),
	_requiredGradeToSign(target.getGradeToSign()),
	_requiredGradeToExec(target.getGradeToExec()),
	_target(target.getTarget())
{
	_isSigned = target.getIsSigned();
	_handleExceptions(_requiredGradeToSign);
	_handleExceptions(_requiredGradeToExec);
}

Form::Form (std::string const & name, int gradeToSign, int gradeToExec, std::string const target) :
	_name(name),
	_requiredGradeToSign(gradeToSign),
	_requiredGradeToExec(gradeToExec),
	_target(target)
{
	_isSigned = false;
	_handleExceptions(_requiredGradeToSign);
	_handleExceptions(_requiredGradeToExec);	
}

Form::~Form (void) {}

//Methods
void Form::beSigned (Bureaucrat const & bureaucrat) {
	if (bureaucrat.getGrade() > _requiredGradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void Form::setIsSigned (bool value) {
	_isSigned = value;
}

void Form::_handleExceptions (int grade) {
	if (grade < Bureaucrat::maxGrade)
		throw GradeTooHighException();
	else if (grade > Bureaucrat::minGrade)
		throw GradeTooLowException();
}

void Form::execute (Bureaucrat const & executor) const {
	if (!getIsSigned())
		throw FormNotSigned();

	if (executor.getGrade() > _requiredGradeToExec)
		throw GradeTooLowException();
}

//Operators
std::ostream & operator << (std::ostream & o, Form const & target) {
	o << "[Form] " << target.getName() <<
		" grade to sign: " << target.getGradeToSign() <<
		"; grade to execute: " << target.getGradeToExec() <<
		"; target: " << target.getTarget() << std::endl;
	return o;
}

//Exceptions
char const * Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

char const * Form::GradeTooHighException::what() const throw() {
	return "Grade too hight";
}

char const * Form::FormNotSigned::what() const throw() {
	return "Form not signed";
}