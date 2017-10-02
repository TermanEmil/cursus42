#include "MateriaSource.hpp"

int const MateriaSource::_maxMatsToLearn = 4;

AMateria * MateriaSource::getMat (int idx) const {
	if (idx >= _maxMatsToLearn)
		return NULL;
	return _learnedMateria[idx];
}

int MateriaSource::getCountMatsLearned (void) const {
	int n, i;
 
 	n = 0;
	for (i = 0; i < _maxMatsToLearn; i++) {
		if (_learnedMateria[i])
			n++;
	}
	return n;
}

MateriaSource::MateriaSource (void) {
	_learnedMateria = new AMateria* [_maxMatsToLearn];
	for (int i = 0; i < _maxMatsToLearn; i++)
		_learnedMateria[i] = NULL;
}

MateriaSource::MateriaSource (MateriaSource const & target) {
	*this = target;
}

MateriaSource::~MateriaSource (void) {
	delete _learnedMateria;
}

void MateriaSource::learnMateria (AMateria * target) {
	for (int i = 0; i < _maxMatsToLearn; i++)
		if (_learnedMateria[i] == NULL) {
			_learnedMateria[i] = target;
			return;
		}
}

AMateria * MateriaSource::createMateria (std::string const & type) {
	for (int i = 0; i < _maxMatsToLearn; i++)
		if (_learnedMateria[i] && _learnedMateria[i]->getType() == type) {
			std::cout << "Clone mat " << std::endl; 
			return _learnedMateria[i]->clone();
		}
	return NULL;
}

MateriaSource & MateriaSource::operator = (MateriaSource const & target) {
	for (int i = 0; i < _maxMatsToLearn; i++) {
		_learnedMateria[i] = target.getMat(i);
	}
	return *this;
}

std::ostream & operator << (std::ostream & o, MateriaSource const & target) {
	o << "[MateriaSource] learned mats: " << target.getCountMatsLearned() <<
		std::endl;

	return o;
}