#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define FRAGTRAP_CL C_MAGENTA

class FragTrap: virtual public ClapTrap
{
public:
	FragTrap (void);
	FragTrap (std::string const & name);
	FragTrap (FragTrap const & target);
	virtual ~FragTrap (void);

	virtual void rangedAttack (std::string const & target) const;
	virtual void meleAttack (std::string const & target) const;
	
	void vaulthunter_dot_exe(std::string const & target);

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