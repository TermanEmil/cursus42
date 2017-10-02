#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <time.h>
# include <stdlib.h>

typedef unsigned int u_i;

class FragTrap
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

	FragTrap (std::string const & name);
	FragTrap (FragTrap const & target);
	FragTrap (u_i const lvl, u_i const hp, u_i const maxHp, u_i const ep,
		u_i const maxEP, u_i const meleDmg, u_i const rangedDmg,
		u_i const armor, std::string const name);
	~FragTrap (void);

	void rangedAttack (std::string const & target) const;
	void meleAttack (std::string const & target) const;
	void takeDamage (unsigned int const amount);
	void beRepaired (unsigned int const amount);
	void vaulthunter_dot_exe(std::string const & target);

	FragTrap & operator = (FragTrap const & target);

private:
	unsigned int _lvl;
	unsigned int _hp;
	unsigned int _maxHP;
	unsigned int _eneryPoints;
	unsigned int _maxEP;
	unsigned int _meleDmg;
	unsigned int _rangedDmg;
	unsigned int _armor;
	std::string _name;
};

#endif