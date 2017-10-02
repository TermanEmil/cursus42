#include "ScavTrap.hpp"
#include <iostream>

//Constructors Destructors

ScavTrap::ScavTrap (void) : ClapTrap() {
	_init("ScavTrap");
	_armor = 3;

	std::cout << SCAVTRAP_CL;
	std::cout << "ScavTrap constructor [" << _name << "]";
	std::cout << C_EOC << std::endl;
}

ScavTrap::ScavTrap (std::string const & name) : ClapTrap(name) {
	_init(name);
	_armor = 3;

	std::cout << SCAVTRAP_CL;
	std::cout << "ScavTrap constructor [" << _name << "]";
	std::cout << C_EOC << std::endl;
}

ScavTrap::ScavTrap (ScavTrap const & target) : ClapTrap(target) {
	*this = target;

	std::cout << SCAVTRAP_CL;
	std::cout << "ScavTrap constructor [" << _name << "]";
	std::cout << C_EOC << std::endl;
}

ScavTrap::~ScavTrap (void) {
	std::cout << SCAVTRAP_CL;
	std::cout << "ScavTrap destructor [" << _name << "]";
	std::cout << C_EOC << std::endl;	
}

//Methods

void ScavTrap::rangedAttack (std::string const & target) const {
	std::cout << SCAVTRAP_CL;
	std::cout << "[ScavTrap] " << _name << " attacks " <<
		target << " at range, causing " <<
		_rangedDmg << " points of damage!";
	std::cout << C_EOC << std::endl;
}

void ScavTrap::meleAttack (std::string const & target) const {
	std::cout << SCAVTRAP_CL;
	std::cout << "[ScavTrap] " << _name << " mele attacks " <<
		target << ", causing " <<
		_meleDmg << " points of damage!";
	std::cout << C_EOC << std::endl;
}


void ScavTrap::challengeNewcomer(std::string const & target) const {
	std::string const challenges[2] = {
		"Eat a spicy kebab",
		"Hit Stefan in the face"
	};

	std::cout << SCAVTRAP_CL;
	std::cout << "[ScavTrap] " << _name << " challenges " << target <<
		". Challenge: {" << challenges[rand() % 2] << "}";
	std::cout << C_EOC << std::endl;	
}