#include "Character.hpp"
#include "AMateria.hpp"

int const Character::_maxSlots = 4;

std::string const & Character::getName (void) const {return _name;}

AMateria const * Character::getItem (int idx) const {
	if (idx >= _maxSlots)
		return NULL;
	return _items[idx];
}

Character::Character (void) : _name("NoName") {_init();}

Character::Character (std::string const & name) : _name(name) {_init();}

Character::Character (Character const & target) {
	*this = target;
}

Character::~Character (void) {
	std::cout << _name << " is destryed" << std::endl;

	for (int i = 0; i < _maxSlots; i++)
		if (_items[i]) {
			delete _items[i];
		}
	delete _items;
}

void Character::equip (AMateria * m) {
	if (m == NULL)
		return;

	for (int i = 0; i < _maxSlots; i++) {
		if (_items[i] && _items[i]->getType() == m->getType()) {
			return;
		}
	}

	for (int i = 0; i < _maxSlots; i++) {
		if (_items[i] == NULL) {
			_items[i] = m;
			return;
		}
	}
}

void Character::unequip (int idx) {
	if (idx >= _maxSlots)
		return;
	_items[idx] = NULL;
}

void Character::use (int idx, ICharacter & target) {
	if (idx >= _maxSlots || _items[idx] == NULL) {
		return;
	}
	_items[idx]->use(target);
}

void Character::_init (void) {
	_items = new AMateria* [_maxSlots];
	for (int i = 0; i < _maxSlots; i++) {
		_items[i] = NULL;
	}
}

Character & Character::operator = (Character const & target) {
	for (int i = 0; i < _maxSlots; i++) {
		if (_items[i])
			delete _items[i];
		if (target.getItem(i))
			_items[i] = target.getItem(i)->clone();
		else
			_items[i] = NULL;
	}
	return *this;
}

std::ostream & operator << (std::ostream & o, Character const & target) {
	o << "I am " << target.getName() << std::endl;
	return o;
}