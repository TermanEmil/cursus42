#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main (void) {
	srand(time(NULL));

	FragTrap * leosha = new FragTrap("Leosha");
	leosha->rangedAttack("Andrei");
	leosha->meleAttack("Andrei");
	leosha->takeDamage(10);
	leosha->takeDamage(500);
	leosha->beRepaired(30);
	leosha->takeDamage(15);
	leosha->vaulthunter_dot_exe("Emil");
	delete leosha;

	std::cout << std::endl;

	ScavTrap alen("Alen");
	alen.rangedAttack("Andrei");
	alen.meleAttack("Andrei");
	alen.takeDamage(10);
	alen.takeDamage(500);
	alen.beRepaired(30);
	alen.takeDamage(15);
	// leosha.vaulthunter_dot_exe("\033[31mEmil\033[0m");
	alen.challengeNewcomer("Emil");
	return 0;
}