#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include "ft_colors.h"

# define CLAPTRAP_CL C_BLUE

class ClapTrap
{
public:
	unsigned int getLvl (void) const;
	unsigned int getHP (void) const;
	unsigned int getMaxHP (void) const;
	unsigned int getEP (void) const;
	unsigned int getMaxEP (void) const;
	unsigned int getMeleDmg (void) const;
	unsigned int getRangedDmg (void) const;
	unsigned int getArmor (void) const;
	std::string getName (void) const;

	void setHP (unsigned int const value);
	void setEP (unsigned int const value);

	ClapTrap (void);
	ClapTrap (std::string const & name);
	ClapTrap (ClapTrap const & target);
	~ClapTrap (void);

	void rangedAttack (std::string const & target) const;
	void meleAttack (std::string const & target) const;
	void takeDamage (unsigned int const amount);
	void beRepaired (unsigned int const amount);
	
	ClapTrap & operator = (ClapTrap const & target);

protected:
	unsigned int _lvl;
	unsigned int _hp;
	unsigned int _maxHP;
	unsigned int _ep;
	unsigned int _maxEP;
	unsigned int _meleDmg;
	unsigned int _rangedDmg;
	unsigned int _armor;
	std::string _name;

	void _init (std::string name);
};

std::ostream & operator << (std::ostream & o, ClapTrap const & target);

#endif