#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include "Intern.hpp"

class OfficeBlock
{
public:
	class NoIntern : public std::exception {
		virtual char const * what() const throw();
	};

	class NoSigner : public std::exception {
		virtual char const * what() const throw();
	};

	class NoExecutor : public std::exception {
		virtual char const * what() const throw();
	};

	Intern const * getIntern (void) const;
	Bureaucrat const * getSigner (void) const;
	Bureaucrat const * getExecutor (void) const;

	void setIntern (Intern & newIntern);
	void setSigner (Bureaucrat & newSigner);
	void setExecutor (Bureaucrat & newExec);

	OfficeBlock (void);
	OfficeBlock (Intern * intern, Bureaucrat * signer, Bureaucrat * executor);
	~OfficeBlock (void);
	
	void doBureaucracy(std::string const & formName, std::string const & target);

private:
	Intern * _intern;
	Bureaucrat * _signer;
	Bureaucrat * _executor;
};

std::ostream & operator << (std::ostream & o, OfficeBlock const & target);

#endif