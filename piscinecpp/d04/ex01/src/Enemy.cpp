#include "Enemy.hpp"

//Getters and Setters
int Enemy::getHP (void) const {return _hp;};
int Enemy::getMaxHP (void) const {return _maxHP;}
std::string const & Enemy::getType (void) const {return _type;}

void Enemy::setHp (int newHp) {
	if (newHp < 0)
		_hp = 0;
	else if (newHp > getMaxHP())
		_hp = getMaxHP();
	else
		_hp = newHp;
}

//Constructors && destructors
Enemy::Enemy (void) : _hp(0), _maxHP(0), _type("DefaultEnemy") {
	std::cout << "New Enemy: " << getType() << std::endl;
}

Enemy::Enemy (Enemy const & target) :
	_hp(target.getHP()), _maxHP(target.getMaxHP()), _type(target.getType())
{
	std::cout << "New Enemy: " << getType() << std::endl;	
}

Enemy::Enemy (int hp, std::string const & type) : _maxHP(hp), _type(type) {
	setHp(_maxHP);
}

Enemy::~Enemy (void) {
	std::cout << "Enemy destroyed: " << getType() << std::endl;
}

//Methods
void Enemy::takeDamage (int amount) {
	if (amount > 0) {
		setHp(getHP() - amount);

		std::cout << "Enemy: " << getType() << " takes " << amount <<
			" damage" << std::endl;
	} else
		std::cout << "The amount of damage can't be negative" << std::endl;


}

std::ostream & operator << (std::ostream & o, Enemy const & target) {
	o << target.getType() << ", HP:" << target.getHP() << std::endl;

	return o;
}