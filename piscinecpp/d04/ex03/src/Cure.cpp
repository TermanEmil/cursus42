#include "Cure.hpp"

Cure::Cure (void) : AMateria("Cure") {}

Cure::Cure (Cure const & target) : AMateria(target) {}

Cure::~Cure (void) {}

//Methods
AMateria * Cure::clone (void) const {
	return new Cure(*this);
}

void Cure::use  (ICharacter & target) {
	AMateria::use(target);

	std::cout << "* heals " << target.getName() <<
		"’s wounds *" << std::endl;
}

std::ostream & operator << (std::ostream & o, Cure const & target) {
	o << target.getType() << ": XP = " << target.getXP() << std::endl;
	return o;
}