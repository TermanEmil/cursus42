#ifndef NinjaTrap_HPP
# define NinjaTrap_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

# define NINJATRAP_CL C_YELLOW

class NinjaTrap: public ClapTrap
{
public:
	NinjaTrap (void);
	NinjaTrap (std::string const & name);
	NinjaTrap (NinjaTrap const & target);
	~NinjaTrap (void);

	void rangedAttack (std::string const & target) const;
	void meleAttack (std::string const & target) const;
	
	void ninjaShoebox (ClapTrap const & target);
	void ninjaShoebox (FragTrap const & target);
	void ninjaShoebox (ScavTrap const & target);
	void ninjaShoebox (NinjaTrap const & target);

protected:
	void _init (std::string name);
};

#endif