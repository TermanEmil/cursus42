#ifndef NinjaTrap_HPP
# define NinjaTrap_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

# define NINJATRAP_CL C_YELLOW

class NinjaTrap: virtual public ClapTrap
{
public:
	NinjaTrap (void);
	NinjaTrap (std::string const & name);
	NinjaTrap (NinjaTrap const & target);
	virtual ~NinjaTrap (void);

	virtual void rangedAttack (std::string const & target) const;
	virtual void meleAttack (std::string const & target) const;
	
	void ninjaShoebox (ClapTrap const & target);
	void ninjaShoebox (FragTrap const & target);
	void ninjaShoebox (ScavTrap const & target);
	void ninjaShoebox (NinjaTrap const & target);

protected:
	virtual void _initLvl (void);
	virtual void _initHP (void);
	virtual void _initMaxHp (void);
	virtual void _initEP (void);
	virtual void _initMaxEP (void);
	virtual void _initMeleDmg (void);
	virtual void _initRangedDmg (void);
	virtual void _initArmor (void);
};

#endif