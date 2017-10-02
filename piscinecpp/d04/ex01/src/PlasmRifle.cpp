#include "PlasmRifle.hpp"

//Constructors && destructors
PlasmRifle::PlasmRifle (void) : AWeapon("Plasma Rifle", 5, 21) {
	std::cout << "New PlasmaRifle" << std::endl;
}

PlasmRifle::~PlasmRifle (void) {std::cout << _name << " destryed" << std::endl;}

//Methods
void PlasmRifle::attack (void) const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}