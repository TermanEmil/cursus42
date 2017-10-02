#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
public:
	std::string const & getName (void) const;
	int getAP (void) const;
	int getMaxAP (void) const;
	AWeapon * getWeapon (void) const;

	void setAP (int amount);

	Character (Character const & target);
	Character (std::string const & name);
	~Character (void);

	void recoverAP (void);
	void equip (AWeapon * newWeapon);
	void attack (Enemy * enemy);

protected:
	std::string const _name;
	int _ap;
	int const _maxAP;
	AWeapon * _weapon;

private:
	Character (void);

	void _init (void);
};

std::ostream & operator << (std::ostream & o, Character const & target);

#endif