#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char * what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char * what() const throw();	
	};

	std::string const & getName (void) const;
	int getGradeToSign (void) const;
	int getGradeToExec (void) const;
	bool getIsSigned (void) const;


	Form (Form const & target);
	Form (std::string const & name, int gradeToSign, int gradeToExec);
	~Form (void);

	void beSigned (Bureaucrat const & bureaucrat);

private:
	Form (void);

	std::string const _name;
	bool _isSigned;
	int const _requiredGradeToSign;
	int const _requiredGradeToExec;

	void _handleExceptions (int grade);

};

std::ostream & operator << (std::ostream & o, Form const & target);

#endif