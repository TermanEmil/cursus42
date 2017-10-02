#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "ClapTrap.hpp"
# include "NinjaTrap.hpp"

# define SUPERTRAP_CL C_GREEN

class SuperTrap: public FragTrap, public NinjaTrap
{
public:
	using FragTrap::rangedAttack;
	
	SuperTrap (void);
	SuperTrap (std::string const & name);
	SuperTrap (SuperTrap const & target);
	~SuperTrap (void);

	void rangedAttack (std::string const & target) const;
	void meleAttack (std::string const & target) const;

protected:
	void _initLvl (void);
	void _initHP (void);
	void _initMaxHp (void);
	void _initEP (void);
	void _initMaxEP (void);
	void _initMeleDmg (void);
	void _initRangedDmg (void);
	void _initArmor (void);
};

#endif