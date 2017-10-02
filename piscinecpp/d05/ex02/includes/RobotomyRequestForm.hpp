#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm (RobotomyRequestForm const & target);
	RobotomyRequestForm (std::string const & target);
	~RobotomyRequestForm (void);

	void execute (Bureaucrat const & executor) const;

	RobotomyRequestForm & operator = (RobotomyRequestForm const & target);

private:
	RobotomyRequestForm (void);
};

std::ostream & operator << (std::ostream & o, RobotomyRequestForm & target);

#endif