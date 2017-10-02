#include "FragTrap.hpp"
#include <iostream>

//Geters

unsigned int FragTrap::getLvl (void) const {return _lvl;};
unsigned int FragTrap::getHP (void) const {return _hp;};
unsigned int FragTrap::getMaxHP (void) const {return _maxHP;};
unsigned int FragTrap::getEP (void) const {return _eneryPoints;};
unsigned int FragTrap::getMaxEP (void) const {return _maxEP;};
unsigned int FragTrap::getMeleDmg (void) const {return _meleDmg;};
unsigned int FragTrap::getRangedDmg (void) const {return _rangedDmg;};
unsigned int FragTrap::getArmor (void) const {return _armor;};
std::string FragTrap::getName (void) const {return _name;};

//Seters

void FragTrap::setHP (unsigned int const value) {
	_hp = value;
	if (_hp > _maxHP)
		_hp = _maxHP;
}

void FragTrap::setEP (unsigned int const value) {
	_eneryPoints = value;
	if (_eneryPoints > _maxEP)
		_eneryPoints = _maxEP;
}

//Constructors destructors

FragTrap::FragTrap (void) {
	*this = FragTrap("FragTrap");
}

FragTrap::FragTrap (std::string const & name)
{
	_lvl = 1;
	_hp = 100;
	_maxHP = 100;
	_eneryPoints = 50;
	_maxEP = 50;
	_meleDmg = 20;
	_rangedDmg = 15;
	_armor = 5;
	_name = name;
	std::cout << "New FR4G-TP: " << _name << std::endl;
}

FragTrap::FragTrap (FragTrap const & target) {
	*this = target;

	std::cout << "New FR4G-TP: " << _name << std::endl;	
}

FragTrap::~FragTrap (void) {
	std::cout << "FR4G-TP " << _name << " gets Destroyed" << std::endl;
}

//Methods

void FragTrap::rangedAttack (std::string const & target) const {
	std::cout << "FR4G-TP " << _name << " attacks " <<
		target << " at range, causing " <<
		_rangedDmg << " points of damage!" << std::endl;
}

void FragTrap::meleAttack (std::string const & target) const {
	std::cout << "FR4G-TP " << _name << " mele attacks " <<
		target << ", causing " <<
		_meleDmg << " points of damage!" << std::endl;	
}

void FragTrap::takeDamage (unsigned int const amount) {
	unsigned int armoredAmount;

	armoredAmount = (100 - _armor) / ((float) 100) * amount;
	if (_hp < armoredAmount)
		setHP(0);
	else
		setHP(_hp - armoredAmount);

	std::cout << "" << _name << " takes " << armoredAmount <<
		" damage [(" << amount - armoredAmount << ") protected]." <<
		" HP left: " << _hp <<
		std::endl;
}

void FragTrap::beRepaired (unsigned int const amount) {
	setHP(amount);

	std::cout << "" << _name << " gets repaired with " <<
		amount << " hp." << " Current Hp: " << _hp << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	unsigned int const eneryCost = 25;
	std::string const attacks[4] = {
		"heart attack", "Show an old meme attack",
		"Game of Thrones spoiler attack",
		"Bring one of your friend to Fast Kebab, make him buy a super " 
		"spicy kebab and eat it yourself, coz it's impossible to eat"
	};

	if (_eneryPoints < eneryCost) {
		std::cout << "FR4G-TP " << _name << ": not enough energy. " <<
			eneryCost << " is needed, " << _name << " has only " <<
			_eneryPoints << std::endl;
	} else {
		setEP(_eneryPoints - eneryCost);

		std::cout << "FR4G-TP " << _name << " executes the attack: " <<
			attacks[rand() % 4] << " on " << target << std::endl;
	}
}

//Operators

FragTrap & FragTrap::operator = (FragTrap const & target) {
	_lvl = target.getLvl();
	_hp = target.getHP();
	_maxHP = target.getMaxHP();
	_eneryPoints = target.getEP();
	_maxEP = target.getMaxEP();
	_meleDmg = target.getMeleDmg();
	_rangedDmg = target.getRangedDmg();
	_name = target.getName();

	return *this;
}