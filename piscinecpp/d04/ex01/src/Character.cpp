#include "Character.hpp"

//Getters and setters
std::string const & Character::getName (void) const {return _name;}
int Character::getAP (void) const {return _ap;}
int Character::getMaxAP (void) const {return _maxAP;}
AWeapon * Character::getWeapon (void) const {return _weapon;}

void Character::setAP (int amount) {
	if (amount > getMaxAP())
		_ap = _maxAP;
	else if (amount < 0)
		_ap = 0;
	else
		_ap = amount;
}

//Constructors & destructors
Character::Character (void) : _name("NoName"), _maxAP(40) {_init();}

Character::Character (Character const & target) :
	_name(target.getName()), _maxAP(target.getMaxAP())
{
	_ap = target.getAP();
	equip(target.getWeapon());
	std::cout << "New Character: " << getName() << std::endl;	
}

Character::Character (std::string const & name) : _name(name), _maxAP(40) {
	_init();
}

//Methods
void Character::recoverAP (void) {
	setAP(getAP() + 10);

	std::cout << "Character: " << getName() << " recovers AP, up to " <<
		getAP() << std::endl;
}

void Character::equip (AWeapon * newWeapon) {
	_weapon = newWeapon;
}

void Character::attack (Enemy * enemy) {
	if (getWeapon() == NULL) {
		std::cout << getName() << " can't attack without a weapon" << std::endl;
		return;
	}

	if (getWeapon()->getAPCost() > getAP()) {
		std::cout << getName() << " not enough AP" << std::endl;
		return;
	}

	_ap -= getWeapon()->getAPCost();

	std::string target = (enemy == NULL) ? "air" : enemy->getType();

	std::cout << getName() << " attacks " << target <<
		" loosing " << getWeapon()->getAPCost() << " AP " <<
		" with " << getWeapon()->getName() << std::endl;
	getWeapon()->attack();

	if (enemy != NULL)
		enemy->takeDamage(getWeapon()->getDmg());

	if (enemy != NULL && enemy->getHP() <= 0) {
		std::cout << getName() << " kills the " << target << std::endl;
		delete enemy;
	}
}

void Character::_init (void) {
	_ap = _maxAP;
	_weapon = NULL;

	std::cout << "New Character: " << getName() << std::endl;
}

std::ostream & operator << (std::ostream & o, Character const & target) {
	o << target.getName() << " has " << target.getAP() << " AP ";

	if (target.getWeapon())
		o << "and wields " << target.getWeapon()->getName();
	else
		o << "and is unarmed";

	o << std::endl;

	return o;
}