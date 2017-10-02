#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

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

	ScavTrap * alen = new ScavTrap("Alen");
	alen->rangedAttack("Andrei");
	alen->meleAttack("Andrei");
	alen->takeDamage(10);
	alen->takeDamage(500);
	alen->beRepaired(30);
	alen->takeDamage(15);
	alen->challengeNewcomer("Emil");
	delete alen;

	std::cout << std::endl;

	NinjaTrap * polina = new NinjaTrap("Polina");
	polina->rangedAttack("Andrei");
	polina->meleAttack("Andrei");
	polina->takeDamage(10);
	polina->takeDamage(500);
	polina->beRepaired(30);
	polina->takeDamage(15);
	
	ClapTrap a("ClapTrap_a");
	FragTrap b("FragTrap_b");
	ScavTrap c("ScavTrap_c");

	polina->ninjaShoebox(a);
	polina->ninjaShoebox(b);
	polina->ninjaShoebox(c);
	polina->ninjaShoebox(*polina);

	delete polina;		

	return 0;
}