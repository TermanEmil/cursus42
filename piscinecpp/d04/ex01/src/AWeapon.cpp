#include "AWeapon.hpp"

//Getters & Setters
std::string const & AWeapon::getName (void) const {return _name;}
int AWeapon::getAPCost (void) const {return _apcost;}
int AWeapon::getDmg (void) const {return _dmg;}

//Constructors & destructors
AWeapon::AWeapon (void) : _name("AWeapon"), _apcost(0), _dmg(0) {_init();}

AWeapon::AWeapon (AWeapon const & target) :
	_name(target.getName()), _apcost(target.getAPCost()), _dmg(target.getDmg())
{
	_init();
}

AWeapon::AWeapon (std::string const & name, int apcost, int dmg) :
	_name(name), _apcost(apcost), _dmg(dmg)
{
	_init();
}

AWeapon::~AWeapon (void) {std::cout << "AWeapon destroyed" << std::endl;}

//Methods
void AWeapon::_init (void) {
	std::cout << "New AWeapon" << std::endl;
}

//Operators
std::ostream & operator << (std::ostream & o, AWeapon const & target) {
	o << "[Weapon] " << target.getName() <<
	": AP cost " << target.getAPCost() <<
	", DMG " << target.getDmg() << std::endl;

	return o;
}