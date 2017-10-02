#include "FragTrap.hpp"

//Constructors Destructors

FragTrap::FragTrap (void) : ClapTrap() {
	_init("FragTrap");
	_armor = 5;

	std::cout << FRAGTRAP_CL;
	std::cout << "FragTrap constructor [" << _name << "]";
	std::cout << C_EOC << std::endl;
}

FragTrap::FragTrap (std::string const & name) : ClapTrap(name) {
	_init(name);
	_armor = 5;

	std::cout << FRAGTRAP_CL;
	std::cout << "FragTrap constructor [" << _name << "]";
	std::cout << C_EOC << std::endl;
}

FragTrap::FragTrap (FragTrap const & target) : ClapTrap(target) {
	*this = target;

	std::cout << FRAGTRAP_CL;
	std::cout << "FragTrap constructor [" << _name << "]";
	std::cout << C_EOC << std::endl;
}

FragTrap::~FragTrap (void) {
	std::cout << FRAGTRAP_CL;
	std::cout << "FragTrap destructor [" << _name << "]";
	std::cout << C_EOC << std::endl;	
}

//Methods

void FragTrap::rangedAttack (std::string const & target) const {
	std::cout << FRAGTRAP_CL;
	std::cout << "[FragTrap] " << _name << " attacks " <<
		target << " at range, causing " <<
		_rangedDmg << " points of damage!";
	std::cout << C_EOC << std::endl;
}

void FragTrap::meleAttack (std::string const & target) const {
	std::cout << FRAGTRAP_CL;
	std::cout << "[FragTrap] " << _name << " mele attacks " <<
		target << ", causing " <<
		_meleDmg << " points of damage!";
	std::cout << C_EOC << std::endl;
}


void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	unsigned int const eneryCost = 25;
	std::string const attacks[2] = {
		"Heart attack",
		"GoT spoiler attack"
	};

	std::cout << FRAGTRAP_CL;
	if (_ep < eneryCost) {
		std::cout << "[FragTrap] Not enough energy! [" <<
			_ep << "/" << eneryCost;
	} else {
		std::cout << "[FragTrap] " << _name << " executes attack: {" <<
			attacks[rand() % 2] << "} on " << target;
	}
	std::cout << C_EOC << std::endl;
}

void FragTrap::_initLvl (void) {_lvl = 1;}
void FragTrap::_initHP (void) {_hp = 100;}
void FragTrap::_initMaxHp (void) {_maxHP = 100;}
void FragTrap::_initEP (void) {_ep = 100;}
void FragTrap::_initMaxEP (void) {_maxEP = 100;}
void FragTrap::_initMeleDmg (void) {_meleDmg = 30;}
void FragTrap::_initRangedDmg (void) {_rangedDmg = 20;}
void FragTrap::_initArmor (void) {_armor = 5;}