#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm (PresidentialPardonForm const & target);
	PresidentialPardonForm (std::string const & target);
	~PresidentialPardonForm (void);

	void execute (Bureaucrat const & executor) const;

	PresidentialPardonForm & operator = (PresidentialPardonForm const & target);

private:
	PresidentialPardonForm (void);
};

std::ostream & operator << (std::ostream & o, PresidentialPardonForm & target);

#endif