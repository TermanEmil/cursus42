#include "Ice.hpp"

Ice::Ice (void) : AMateria("Ice") {}

Ice::Ice (Ice const & target) : AMateria(target) {}

Ice::~Ice (void) {}

//Methods
AMateria * Ice::clone (void) const {
	return new Ice(*this);
}

void Ice::use  (ICharacter & target) {
	AMateria::use(target);

	std::cout << "* shoots an ice bolt at " << target.getName() <<
		" *" << std::endl;
}

std::ostream & operator << (std::ostream & o, Ice const & target) {
	o << target.getType() << ": XP = " << target.getXP() << std::endl;
	return o;
}