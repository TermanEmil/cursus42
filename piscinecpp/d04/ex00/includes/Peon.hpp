#ifndef PEON_HPP
# define PEON_HPP

# include <string>
# include <iostream>
# include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon (std::string const & name);
	Peon (Peon const & target);
	~Peon (void);

	void GetPolymorphed (void) const;

protected:
	void _init (void);

private:
	Peon (void);
};

#endif