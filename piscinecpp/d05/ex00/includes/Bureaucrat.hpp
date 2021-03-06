#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat
{
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char * what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual char const * what() const throw();
	};

	static int const minGrade;
	static int const maxGrade;

	std::string const & getName (void) const;
	int getGrade (void) const;

	void gradeIncrement (int amount);
	void gradeDecrement (int amount);

	Bureaucrat (Bureaucrat const & target);
	Bureaucrat (std::string const name, int grade);
	~Bureaucrat (void);
	
private:
	std::string const _name;
	int _grade;

	Bureaucrat (void);
};

std::ostream & operator << (std::ostream & o, Bureaucrat const & target);

#endif