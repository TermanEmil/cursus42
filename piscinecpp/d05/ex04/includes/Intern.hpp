#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	class NoSuchForm : public std::exception {
		virtual const char * what() const throw();
	};

	Intern (void);
	Intern (Intern const & target);
	~Intern (void);

	Form * makeForm (std::string const & formName, std::string const & formTarget);

	Intern & operator = (Intern const & target);
};

std::ostream & operator << (std::ostream & o, Intern const & target);

#endif