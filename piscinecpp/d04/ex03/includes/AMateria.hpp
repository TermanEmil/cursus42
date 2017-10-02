#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
public:
	unsigned int getXP (void) const;
	std::string const & getType (void) const;

	AMateria (void);
	AMateria (std::string const & type);
	AMateria (AMateria const & target);
	virtual ~AMateria (void);

	virtual AMateria * clone (void) const = 0;
	virtual void use (ICharacter & target);

	AMateria & operator = (AMateria const & target);

private:
	unsigned int _xp;
	std::string _type;
};

std::ostream & operator << (std::ostream & o, AMateria const & target);

#endif