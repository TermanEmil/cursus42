#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main (void) {
	srand(time(NULL));

	FragTrap leosha("\033[33mLeosha\033[0m");
	leosha.rangedAttack("Andrei");
	leosha.meleAttack("Andrei");

	leosha.takeDamage(10);
	leosha.takeDamage(500);
	leosha.beRepaired(30);
	leosha.takeDamage(15);
	leosha.vaulthunter_dot_exe("\033[31mEmil\033[0m");

	std::cout << std::endl;

	ScavTrap alen("\033[32mAlen\033[0m");
	alen.rangedAttack("Andrei");
	alen.meleAttack("Andrei");
	alen.takeDamage(10);
	alen.takeDamage(500);
	alen.beRepaired(30);
	alen.takeDamage(15);
	// leosha.vaulthunter_dot_exe("\033[31mEmil\033[0m");
	alen.challengeNewcomer("\033[31mEmil\033[0m");


	std::cout << std::endl;
	return 0;
}