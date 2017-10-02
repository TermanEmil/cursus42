#include "Bureaucrat.hpp"

int const Bureaucrat::maxGrade = 1;
int const Bureaucrat::minGrade = 150;

std::string const & Bureaucrat::getName (void) const {return _name;}
int Bureaucrat::getGrade (void) const {return _grade;}

void Bureaucrat::gradeIncrement (int amount) {
	if (_grade - amount > minGrade)
		throw GradeTooLowException();
	else if (_grade - amount < maxGrade)
		throw GradeTooHighException();
	_grade -= amount;
}

void Bureaucrat::gradeDecrement (int amount) {
	if (_grade + amount > minGrade)
		throw GradeTooLowException();
	else if (_grade + amount < maxGrade)
		throw GradeTooHighException();
	_grade += amount;
}

Bureaucrat::Bureaucrat (void) : _name("Bureaucrat"), _grade(minGrade) {}

Bureaucrat::Bureaucrat (std::string const name, int grade) :
	_name(name)
{
	_grade = minGrade;
	if (grade > minGrade)
		throw GradeTooLowException();
	else if (grade < maxGrade)
		throw GradeTooHighException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat (Bureaucrat const & target) :
	_name(target.getName()), _grade(target.getGrade())
{
	_grade = minGrade;
	if (target.getGrade() > minGrade)
		throw GradeTooLowException();
	else if (target.getGrade() < maxGrade)
		throw GradeTooHighException();
	else
		_grade = target.getGrade();	
}

Bureaucrat::~Bureaucrat (void) {}

std::ostream & operator << (std::ostream & o, Bureaucrat const & target) {
	o << "[Bureaucrat] " << target.getName() <<
		": grade = " << target.getGrade() << std::endl;

	return o;
}

//Exceptions
char const  * Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too hight";
}

char const * Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}