#include "Character.hpp"
#include "AWeapon.hpp"
#include "PlasmRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"

void testPowerFist (void) {
	AWeapon * pf = new PowerFist();
	
	pf->attack();
	std::cout << *pf;
	delete pf;
}

void testPlasmaRifle (void) {
	AWeapon * pr = new PlasmRifle();

	pr->attack();
	std::cout << *pr;
	delete pr;
}

void testEnemies (void) {
	Enemy * mutant = new SuperMutant();

	mutant->takeDamage(10);
	mutant->takeDamage(2);
	mutant->takeDamage(999);
	std::cout << *mutant;
	delete mutant;

	Enemy * scorpion = new RadScorpion();
	scorpion->takeDamage(10);
	std::cout << *scorpion;
	delete scorpion;
}

void testCharacter (void) {
	Character* zaz = new Character("zaz");

	std::cout << *zaz;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmRifle();
	AWeapon* pf = new PowerFist();
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(NULL);
	std::cout << *zaz;
	zaz->attack(NULL);
	zaz->equip(pr);
	zaz->attack(NULL);
}

int main (void) {
	
	testPowerFist();
	std::cout << std::endl;
	testPlasmaRifle();
	std::cout << std::endl;
	testEnemies();
	testCharacter();
	return 0;
}