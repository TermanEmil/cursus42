#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap (void) {
	_lvl = 1;
	_hp = 100;
	_maxHP = 100;
	_eneryPoints = 50;
	_maxEP = 50;
	_meleDmg = 20;
	_rangedDmg = 15;
	_armor = 3;
	_name = "ScavTrap";
}

ScavTrap::ScavTrap (std::string const & name)
{
	_lvl = 1;
	_hp = 100;
	_maxHP = 100;
	_eneryPoints = 50;
	_maxEP = 50;
	_meleDmg = 20;
	_rangedDmg = 15;
	_armor = 3;
	_name = name;
	std::cout << "New ScavTrap: " << _name << std::endl;
}

ScavTrap::ScavTrap (ScavTrap const & target) : FragTrap(target) {
	*this = target;

	std::cout << "New ScavTrap: " << _name << std::endl;
}

ScavTrap::~ScavTrap (void) {
	std::cout << "ScavTrap " << _name << " gets Destroyed" << std::endl;
}

void ScavTrap::rangedAttack (std::string const & target) const {
	std::cout << "ScavTrap " << _name << " attacks " <<
		target << " at range, causing " <<
		_rangedDmg << " points of damage!" << std::endl;
}

void ScavTrap::meleAttack (std::string const & target) const {
	std::cout << "ScavTrap " << _name << " mele attacks " <<
		target << ", causing " <<
		_meleDmg << " points of damage!" << std::endl;	
}

void ScavTrap::challengeNewcomer (std::string const & target) {
	std::string const attacks[3] = {
		"Eat a very spicy kebab",
		"Hit Stefan in his face",
		"Don't watch Game of Thrones for a week"
	};

	std::cout << "ScavTrap " << _name << " challenge: " <<
		attacks[rand() % 3] << " on " << target << std::endl;
}