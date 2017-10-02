#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine (void) {
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine (TacticalMarine const & target) {
	*this = target;
}

TacticalMarine::~TacticalMarine (void) {
	std::cout << "Aaargh ..." << std::endl;
}

ISpaceMarine * TacticalMarine::clone() const {
	TacticalMarine * myClone = new TacticalMarine (*this);
	return myClone;
}

void TacticalMarine::battleCry (void) const {
	std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack (void) const {
	std::cout << "* attacks with bolter *" << std::endl;
}

void TacticalMarine::meleeAttack (void) const {
	std::cout << "* attacks with chainsword *" << std::endl;
}

TacticalMarine & TacticalMarine::operator = (TacticalMarine const & target) {
	(void)target;
	return *this;
}

std::ostream & operator << (std::ostream & o, TacticalMarine const & target) {
	(void)target;
	o << "Me am TacticalMarine!" << std::endl;
	return o;
}