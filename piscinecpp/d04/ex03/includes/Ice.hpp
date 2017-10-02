#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice (void);
	Ice (Ice const & target);
	~Ice (void);

	AMateria * clone (void) const;
	void use (ICharacter & target);
};

std::ostream & operator << (std::ostream & o, Ice const & target);

#endif