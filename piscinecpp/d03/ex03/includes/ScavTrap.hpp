#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define SCAVTRAP_CL C_CYAN

class ScavTrap: public ClapTrap
{
public:
	ScavTrap (void);
	ScavTrap (std::string const & name);
	ScavTrap (ScavTrap const & target);
	~ScavTrap (void);

	void rangedAttack (std::string const & target) const;
	void meleAttack (std::string const & target) const;

	void challengeNewcomer(std::string const & target) const;
};

#endif