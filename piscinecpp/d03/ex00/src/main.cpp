#include "FragTrap.hpp"

int main (void) {
	srand(time(NULL));

	FragTrap leosha("Leosha");

	leosha.rangedAttack("Andrei");
	leosha.meleAttack("Andrei");

	leosha.takeDamage(10);
	leosha.takeDamage(500);
	leosha.beRepaired(30);
	leosha.takeDamage(15);
	leosha.vaulthunter_dot_exe("Emil");
}