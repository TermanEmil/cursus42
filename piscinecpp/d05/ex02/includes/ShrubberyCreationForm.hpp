#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
	class CouldntCreateFile : public std::exception {
	public:
		virtual const char * what() const throw();
	};

	ShrubberyCreationForm (ShrubberyCreationForm const & target);
	ShrubberyCreationForm (std::string const & target);
	~ShrubberyCreationForm (void);

	void execute (Bureaucrat const & executor) const;

	ShrubberyCreationForm & operator = (ShrubberyCreationForm const & target);

private:
	ShrubberyCreationForm (void);
};

std::ostream & operator << (std::ostream & o, ShrubberyCreationForm & target);

#endif