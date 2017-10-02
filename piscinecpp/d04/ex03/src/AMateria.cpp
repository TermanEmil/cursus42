#include "AMateria.hpp"

unsigned int AMateria::getXP (void) const {return _xp;}
std::string const & AMateria::getType (void) const {return _type;}

AMateria::AMateria (void) : _type("NoType") {
	_xp = 0;
}

AMateria::AMateria (std::string const & type) : _type(type) {
	_xp = 0;
}

AMateria::AMateria (AMateria const & target) {*this = target;}

AMateria::~AMateria (void) {
	std::cout << getType() << " is destroyed" << std::endl;
}

void AMateria::use (ICharacter & target) {
	unsigned int const xpToAdd = 10;

	_xp += xpToAdd;
	(void)target;
}

AMateria & AMateria::operator = (AMateria const & target) {
	_xp = target.getXP();
	_type = target.getType();

	return *this;
}

std::ostream & operator << (std::ostream & o, AMateria const & target) {
	o << target.getType() << ": XP = " << target.getXP() << std::endl;
	return o;
}