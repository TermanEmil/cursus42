#include "ClapTrap.hpp"

//Geters

unsigned int ClapTrap::getLvl (void) const {return _lvl;};
unsigned int ClapTrap::getHP (void) const {return _hp;};
unsigned int ClapTrap::getMaxHP (void) const {return _maxHP;};
unsigned int ClapTrap::getEP (void) const {return _ep;};
unsigned int ClapTrap::getMaxEP (void) const {return _maxEP;};
unsigned int ClapTrap::getMeleDmg (void) const {return _meleDmg;};
unsigned int ClapTrap::getRangedDmg (void) const {return _rangedDmg;};
unsigned int ClapTrap::getArmor (void) const {return _armor;};
std::string ClapTrap::getName (void) const {return _name;};

//Seters

void ClapTrap::setHP (unsigned int const value) {
	_hp = value;
	if (_hp > _maxHP)
		_hp = _maxHP;
}

void ClapTrap::setEP (unsigned int const value) {
	_ep = value;
	if (_ep > _maxEP)
		_ep = _maxEP;
}

//Constructors Destructors

ClapTrap::ClapTrap (void) {
	_init("ClapTrap");

	std::cout << CLAPTRAP_CL;
	std::cout << "ClapTrap constructor [" << _name << "]";
	std::cout << C_EOC << std::endl;
}

ClapTrap::ClapTrap (std::string const & name) {
	_init(name);

	std::cout << CLAPTRAP_CL;
	std::cout << "ClapTrap constructor [" << _name << "]";
	std::cout << C_EOC << std::endl;
}

ClapTrap::ClapTrap (ClapTrap const & target) {
	*this = target;

	std::cout << CLAPTRAP_CL;
	std::cout << "ClapTrap constructor [" << _name << "]";
	std::cout << C_EOC << std::endl;
}

ClapTrap::~ClapTrap (void) {
	std::cout << CLAPTRAP_CL;
	std::cout << "ClapTrap destructor [" << _name << "]";
	std::cout << C_EOC << std::endl;	
}

//Methods

void ClapTrap::rangedAttack (std::string const & target) const {
	std::cout << CLAPTRAP_CL;
	std::cout << "[ClapTrap] " << _name << " attacks " <<
		target << " at range, causing " <<
		_rangedDmg << " points of damage!";
	std::cout << C_EOC << std::endl;
}

void ClapTrap::meleAttack (std::string const & target) const {
	std::cout << CLAPTRAP_CL;
	std::cout << "[ClapTrap] " << _name << " mele attacks " <<
		target << ", causing " <<
		_meleDmg << " points of damage!";
	std::cout << C_EOC << std::endl;
}

void ClapTrap::takeDamage (unsigned int const amount) {
	unsigned int armoredAmount;

	armoredAmount = (100 - _armor) / ((float) 100) * amount;
	if (_hp < armoredAmount)
		setHP(0);
	else
		setHP(_hp - armoredAmount);

	std::cout << CLAPTRAP_CL;
	std::cout << "[ClapTrap] " << _name << " takes " << armoredAmount <<
		" damage [(" << amount - armoredAmount << ") protected]." <<
		" HP left: " << _hp;
	std::cout << C_EOC << std::endl;
}

void ClapTrap::beRepaired (unsigned int const amount) {
	setHP(amount);

	std::cout << CLAPTRAP_CL;
	std::cout << "[ClapTrap] " << _name << " gets repaired with " <<
		amount << " hp." << " Current Hp: " << _hp;
	std::cout << C_EOC << std::endl;
}

//Operators

ClapTrap & ClapTrap::operator = (ClapTrap const & target) {
	_lvl = target.getLvl();
	_hp = target.getHP();
	_maxHP = target.getMaxHP();
	_ep = target.getEP();
	_maxEP = target.getMaxEP();
	_meleDmg = target.getMeleDmg();
	_rangedDmg = target.getRangedDmg();
	_name = target.getName();

	return *this;
}

std::ostream & operator << (std::ostream & o, ClapTrap const & target) {
	o << CLAPTRAP_CL;
	o << "Name: " << target.getName() << ", ";
	o << "Hp: " << target.getHP() << ", ";
	o << "Ep: " << target.getEP() << ", ";
	o << "MeleDmg: " << target.getMeleDmg() << ", ";
	o << "RangedDmg: " << target.getRangedDmg() << ", ";
	o << "Armor: " << target.getArmor();
	o << C_EOC << std::endl;
	return o;
}

//Initializers
void ClapTrap::_init (std::string name) {
	_initLvl();
	_initHP();
	_initMaxHp();
	_initEP();
	_initMaxEP();
	_initMeleDmg();
	_initRangedDmg();
	_initArmor();
	
	_name = name;
}

void ClapTrap::_initLvl (void) {_lvl = 1;}
void ClapTrap::_initHP (void) {_hp = 100;}
void ClapTrap::_initMaxHp (void) {_maxHP = 100;}
void ClapTrap::_initEP (void) {_ep = 50;}
void ClapTrap::_initMaxEP (void) {_maxEP = 50;}
void ClapTrap::_initMeleDmg (void) {_meleDmg = 20;}
void ClapTrap::_initRangedDmg (void) {_rangedDmg = 15;}
void ClapTrap::_initArmor (void) {_armor = 5;}