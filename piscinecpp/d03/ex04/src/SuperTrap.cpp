#include "SuperTrap.hpp"

//Constructors Destructors

SuperTrap::SuperTrap (void) : ClapTrap(), FragTrap(), NinjaTrap() {
	FragTrap::_init("SuperTrap");

	std::cout << SUPERTRAP_CL;
	std::cout << "SuperTrap constructor [" << FragTrap::_name << "]";
	std::cout << C_EOC << std::endl;
}

SuperTrap::SuperTrap (std::string const & name) :
	ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
	FragTrap::_init(name);
	FragTrap::_armor = 5;

	std::cout << SUPERTRAP_CL;
	std::cout << "SuperTrap constructor [" << FragTrap::_name << "]";
	std::cout << C_EOC << std::endl;
}

SuperTrap::SuperTrap (SuperTrap const & target) :
	ClapTrap(target), FragTrap(target), NinjaTrap(target)
{
	*this = target;

	std::cout << SUPERTRAP_CL;
	std::cout << "SuperTrap constructor [" << FragTrap::_name << "]";
	std::cout << C_EOC << std::endl;
}

SuperTrap::~SuperTrap (void) {
	std::cout << SUPERTRAP_CL;
	std::cout << "SuperTrap destructor [" << FragTrap::_name << "]";
	std::cout << C_EOC << std::endl;	
}

//Methods

void SuperTrap::rangedAttack (std::string const & target) const {
	std::cout << SUPERTRAP_CL << "[SuperTrap]";
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleAttack (std::string const & target) const {
	std::cout << SUPERTRAP_CL << "[SuperTrap]";
	NinjaTrap::meleAttack(target);
}

void SuperTrap::_initLvl (void) {FragTrap::_lvl = 1;}
void SuperTrap::_initHP (void) {FragTrap::_initHP();}
void SuperTrap::_initMaxHp (void) {FragTrap::_initMaxHp();}
void SuperTrap::_initEP (void) {NinjaTrap::_initEP();}
void SuperTrap::_initMaxEP (void) {NinjaTrap::_initMaxEP();}
void SuperTrap::_initMeleDmg (void) {NinjaTrap::_initMeleDmg();}
void SuperTrap::_initRangedDmg (void) {FragTrap::_initRangedDmg();}
void SuperTrap::_initArmor (void) {FragTrap::_initArmor();}