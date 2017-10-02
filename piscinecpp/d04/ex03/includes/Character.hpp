#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	std::string const & getName (void) const;
	AMateria const * getItem (int idx) const;

	Character (Character const & target);
	Character (std::string const & name);
	~Character (void);
	
	void equip (AMateria * m);
	void unequip (int idx);
	void use (int idx, ICharacter & target);

	Character & operator = (Character const & target);

private:
	static int const _maxSlots;

	std::string _name;
	AMateria ** _items;

	Character (void);

	void _init(void);
};

std::ostream & operator << (std::ostream & o, Character const & target);

#endif