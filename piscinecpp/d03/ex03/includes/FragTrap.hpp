#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define FRAGTRAP_CL C_MAGENTA

class FragTrap: public ClapTrap
{
public:
	FragTrap (void);
	FragTrap (std::string const & name);
	FragTrap (FragTrap const & target);
	~FragTrap (void);

	void rangedAttack (std::string const & target) const;
	void meleAttack (std::string const & target) const;
	
	void vaulthunter_dot_exe(std::string const & target);
};

#endif