#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator (void) {
	std::cout << "* teleports from space" << std::endl;
}

AssaultTerminator::AssaultTerminator (AssaultTerminator const & target) {
	*this = target;
}

AssaultTerminator::~AssaultTerminator (void) {
	std::cout << "I’ll be back..." << std::endl;
}

ISpaceMarine * AssaultTerminator::clone() const {
	AssaultTerminator * myClone = new AssaultTerminator (*this);
	return myClone;
}

void AssaultTerminator::battleCry (void) const {
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void AssaultTerminator::rangedAttack (void) const {
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack (void) const {
	std::cout << "* attacks with chainfists *" << std::endl;
}

AssaultTerminator & AssaultTerminator::operator = (AssaultTerminator const & target) {
	(void)target;
	return *this;
}

std::ostream & operator << (std::ostream & o, AssaultTerminator const & target) {
	(void)target;
	o << "Me am AssaultTerminator!" << std::endl;
	return o;
}