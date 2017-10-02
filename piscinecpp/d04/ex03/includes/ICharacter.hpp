#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>
# include <iostream>

class AMateria;

class ICharacter
{
public:
	virtual std::string const & getName (void) const = 0;

	virtual ~ICharacter(void) {};
	
	virtual void equip (AMateria * m) = 0;
	virtual void unequip (int idx) = 0;
	virtual void use (int idx, ICharacter & target) = 0;
};

#endif