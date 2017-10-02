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

	class FormNotSigned : public std::exception {
	public:
		virtual const char * what() const throw();	
	};	

	std::string const & getName (void) const;
	int getGradeToSign (void) const;
	int getGradeToExec (void) const;
	bool getIsSigned (void) const;
	std::string const & getTarget (void) const;

	void setIsSigned (bool value);

	Form (Form const & target);
	Form (std::string const & name, int gradeToSign, int gradeToExec, std::string const target);
	virtual ~Form (void);

	void beSigned (Bureaucrat const & bureaucrat);
	virtual void execute (Bureaucrat const & executor) const;

private:
	Form (void);

	std::string const _name;
	bool _isSigned;
	int const _requiredGradeToSign;
	int const _requiredGradeToExec;

	void _handleExceptions (int grade);

protected:
	std::string const _target;

};

std::ostream & operator << (std::ostream & o, Form const & target);

#endif