#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <string>
# include <iostream>

//Abastract class

class AWeapon
{
public:
	std::string const & getName (void) const;
	int getAPCost (void) const;
	int getDmg (void) const;

	AWeapon (void);
	AWeapon (AWeapon const & target);
	AWeapon (std::string const & name, int apcost, int dmg);
	virtual ~AWeapon (void);

	virtual void attack(void) const = 0;

protected:
	std::string const _name;
	int const _apcost;
	int const _dmg;

	virtual void _init ();
};

std::ostream & operator << (std::ostream & o, AWeapon const & target);

#endif