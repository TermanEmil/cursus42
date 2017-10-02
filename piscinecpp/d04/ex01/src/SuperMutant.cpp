#include "SuperMutant.hpp"

SuperMutant::SuperMutant (void) : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant (void) {
	std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage (int amount) {
	Enemy::takeDamage(amount - 3);
}