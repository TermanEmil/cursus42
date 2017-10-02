#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "FragTrap.hpp"

class ScavTrap : public FragTrap {
public:
	ScavTrap (void);
	ScavTrap (std::string const & name);
	ScavTrap (ScavTrap const & target);
	~ScavTrap (void);


	void rangedAttack (std::string const & target) const;
	void meleAttack (std::string const & target) const;

	void challengeNewcomer (std::string const & target);

private:
	void vaulthunter_dot_exe(std::string const & target);
};

#endif