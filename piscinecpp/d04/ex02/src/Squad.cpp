#include "Squad.hpp"

int Squad::getCount (void) const {
	int i;
	int n;

	for (i = 0, n = 0; i < _squad_size; i++) {
		if (_units[i])
			n++;
	}

	return n;
}

ISpaceMarine * Squad::getUnit (int i) const {
	if (i >= getCount())
		return NULL;
	return _units[i];
}

//Constructors && destructors
Squad::Squad (void) {
	_units = new ISpaceMarine * [0];
	_squad_size = 0;
}

Squad::Squad (Squad const & target) {
	*this = target;
}

Squad::~Squad (void) {
	for (int i = 0; i < _squad_size; i++)
		if (_units[i])
			delete _units[i];
	delete _units;
}

//Methods
int Squad::push (ISpaceMarine * newUnit) {
	int i, j;

	if (newUnit == NULL)
		return getCount();

	for (i = 0; i < _squad_size; i++) {
		if (newUnit == _units[i])
			return getCount();
	}
	
	ISpaceMarine ** newUnits = new ISpaceMarine * [getCount() + 2];

	j = 0;
	for (i = 0; _units[i] != NULL; i++)
		if (_units[i]) {
			newUnits[j] = _units[i];
			j++;
		}
	newUnits[i] = newUnit;
	_units = newUnits;
	_squad_size = j + 1;
	return _squad_size;
}

Squad & Squad::operator = (Squad const & target) {
	ISpaceMarine * aux;

	delete _units;

	_units = new ISpaceMarine* [target.getCount()];
	for (int i = 0; (aux = target.getUnit(i)); i++) {
		_units[i] = aux->clone();
	}

	return *this;
}

std::ostream & operator << (std::ostream & o, Squad const & target) {
	o << "[Squad]: Size = " << target.getCount() << std::endl;
	(void)target;
	return o;
}