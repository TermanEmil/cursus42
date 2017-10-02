#include "NinjaTrap.hpp"

void NinjaTrap::_init (std::string name) {
	_lvl = 1;
	_hp = 60;
	_maxHP = 60;
	_ep = 120;
	_maxEP = 120;
	_meleDmg = 60;
	_rangedDmg = 5;
	_armor = 0;
	_name = name;
}

//Constructors Destructors

NinjaTrap::NinjaTrap (void) : ClapTrap() {
	_init("NinjaTrap");
	_armor = 5;

	std::cout << NINJATRAP_CL;
	std::cout << "NinjaTrap constructor [" << _name << "]";
	std::cout << C_EOC << std::endl;
}

NinjaTrap::NinjaTrap (std::string const & name) : ClapTrap(name) {
	_init(name);
	_armor = 5;

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
	std::cout << "[NinjaTrap] " << _name << " ninja shoebox on [ClapTrap]: "
		<< target;
	std::cout << C_EOC << std::endl;
}

void NinjaTrap::ninjaShoebox (FragTrap const & target) {
	std::cout << NINJATRAP_CL;
	std::cout << "[NinjaTrap] " << _name << " ninja shoebox on [FragTrap]: "
		<< target;
	std::cout << C_EOC << std::endl;
}

void NinjaTrap::ninjaShoebox (ScavTrap const & target) {
	std::cout << NINJATRAP_CL;
	std::cout << "[NinjaTrap] " << _name << " ninja shoebox on [ScavTrap]: "
		<< target;
	std::cout << C_EOC << std::endl;
}

void NinjaTrap::ninjaShoebox (NinjaTrap const & target) {
	std::cout << NINJATRAP_CL;
	std::cout << "[NinjaTrap] " << _name << " ninja shoebox on [NinjaTrap]: "
		<< target;
	std::cout << C_EOC << std::endl;
}
