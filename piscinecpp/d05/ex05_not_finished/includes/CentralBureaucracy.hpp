#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP

# include "OfficeBlock.hpp"

class CentralBureaucracy
{
public:
	class NoSeatsAvailable : public std::exception {
		virtual char const * what() const throw();
	};

	static int const maxOfficeBlocks;

	OfficeBlock ** getOfficeBlocks (void) const;

	CentralBureaucracy (void);
	CentralBureaucracy (CentralBureaucracy const & target);
	~CentralBureaucracy (void);

	void feedBureaucrats (Bureaucrat & newBureaucrat);
	void queeUp ()
	CentralBureaucracy & operator = (CentralBureaucracy const & target);

private:
	OfficeBlock ** _officeBlocks;
	Form ** _formQuee;
	int _formQueeCount;

	void _init(void);
};

std::ostream & operator << (std::ostream & o, CentralBureaucracy const & target);

#endif