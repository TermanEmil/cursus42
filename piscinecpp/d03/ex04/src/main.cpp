#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

void TestFirstPart (void) {
	FragTrap * leosha = new FragTrap("Leosha");
	leosha->rangedAttack("Andrei");
	leosha->meleAttack("Andrei");
	leosha->takeDamage(10);
	leosha->takeDamage(500);
	leosha->beRepaired(30);
	leosha->takeDamage(15);
	leosha->vaulthunter_dot_exe("Emil");

	leosha->beRepaired(999);
	std::cout << *leosha << std::endl;
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
	
	alen->beRepaired(999);
	std::cout << *alen << std::endl;
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

	polina->beRepaired(999);
	std::cout << *polina << std::endl;
	delete polina;
}

void testSuperTrap (void) {
	SuperTrap * stefan = new SuperTrap("Stefan");

	stefan->rangedAttack("Andrei");
	stefan->meleAttack("Andrei");
	stefan->takeDamage(10);
	stefan->takeDamage(500);
	stefan->beRepaired(30);
	stefan->takeDamage(15);
	stefan->beRepaired(9999);

	ClapTrap a("ClapTrap_a");
	FragTrap b("FragTrap_b");
	ScavTrap c("ScavTrap_c");
	NinjaTrap d("NinjaTrap_d");

	stefan->vaulthunter_dot_exe("Emil");

	std::cout << std::endl;

	stefan->ninjaShoebox(a);
	stefan->ninjaShoebox(b);
	stefan->ninjaShoebox(c);
	stefan->ninjaShoebox(d);
	stefan->ninjaShoebox(*static_cast<FragTrap*>(stefan));
	stefan->ninjaShoebox(*static_cast<NinjaTrap*>(stefan));
	stefan->ninjaShoebox(*static_cast<ClapTrap*>(stefan));

	std::cout << std::endl;
	delete stefan;
}

int main (void) {
	srand(time(NULL));

	TestFirstPart();
	testSuperTrap();
	
	return 0;
}