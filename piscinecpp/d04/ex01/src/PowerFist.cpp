#include "PowerFist.hpp"

//Constructors && destructors
PowerFist::PowerFist (void) : AWeapon("PowerFist", 8, 50) {
	std::cout << "New PowerFist" << std::endl;
}

PowerFist::~PowerFist (void) {std::cout << _name << " destryed" << std::endl;}

//Methods
void PowerFist::attack (void) const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}