#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure (void);
	Cure (Cure const & target);
	~Cure (void);

	AMateria * clone (void) const;
	void use (ICharacter & target);
};

std::ostream & operator << (std::ostream & o, Cure const & target);

#endif