#include "NinjaTrap.hpp"

//Constructors Destructors

NinjaTrap::NinjaTrap (void) : ClapTrap() {
	_init("NinjaTrap");

	std::cout << NINJATRAP_CL;
	std::cout << "NinjaTrap constructor [" << _name << "]";
	std::cout << C_EOC << std::endl;
}

NinjaTrap::NinjaTrap (std::string const & name) : ClapTrap(name) {
	_init(name);

	std::cout << NINJATRAP_CL;
	std::cout << "NinjaTrap constructor [" << _name << "]";
	std::cout << C_EOC << std::endl;
}

NinjaTrap::NinjaTrap (NinjaTrap const & target) : ClapTrap(target) {
	*this = target;

	std::cout << NINJATRAP_CL;
	std::cout << "NinjaTrap constructor [" << _name << "]";
	std::cout << C_EOC << std::endl;
}

NinjaTrap::~NinjaTrap (void) {
	std::cout << NINJATRAP_CL;
	std::cout << "NinjaTrap destructor [" << _name << "]";
	std::cout << C_EOC << std::endl;	
}

//Methods

void NinjaTrap::rangedAttack (std::string const & target) const {
	std::cout << NINJATRAP_CL;
	std::cout << "[NinjaTrap] " << _name << " attacks " <<
		target << " at range, causing " <<
		_rangedDmg << " points of damage!";
	std::cout << C_EOC << std::endl;
}

void NinjaTrap::meleAttack (std::string const & target) const {
	std::cout << NINJATRAP_CL;
	std::cout << "[NinjaTrap] " << _name << " mele attacks " <<
		target << ", causing " <<
		_meleDmg << " points of damage!";
	std::cout << C_EOC << std::endl;
}

void NinjaTrap::ninjaShoebox (ClapTrap const & target) {
	std::cout << NINJATRAP_CL;
	std::cout << "[NinjaTrap] " << _name << " uses "
	"ninja shoebox on [ClapTrap]: " << target;
	std::cout << C_EOC << std::endl;
}

void NinjaTrap::ninjaShoebox (FragTrap const & target) {
	std::cout << NINJATRAP_CL;
	std::cout << "[NinjaTrap] " << _name << " uses "
	"ninja shoebox on [FragTrap]: " << target;
	std::cout << C_EOC << std::endl;
}

void NinjaTrap::ninjaShoebox (ScavTrap const & target) {
	std::cout << NINJATRAP_CL;
	std::cout << "[NinjaTrap] " << _name << " uses "
	"ninja shoebox on [ScavTrap]: " << target;
	std::cout << C_EOC << std::endl;
}

void NinjaTrap::ninjaShoebox (NinjaTrap const & target) {
	std::cout << NINJATRAP_CL;
	std::cout << "[NinjaTrap] " << _name << " uses "
	"ninja shoebox on [NinjaTrap]: " << target;
	std::cout << C_EOC << std::endl;
}

void NinjaTrap::_initLvl (void) {_lvl = 1;}
void NinjaTrap::_initHP (void) {_hp = 60;}
void NinjaTrap::_initMaxHp (void) {_maxHP = 60;}
void NinjaTrap::_initEP (void) {_ep = 120;}
void NinjaTrap::_initMaxEP (void) {_maxEP = 120;}
void NinjaTrap::_initMeleDmg (void) {_meleDmg = 60;}
void NinjaTrap::_initRangedDmg (void) {_rangedDmg = 5;}
void NinjaTrap::_initArmor (void) {_armor = 0;}