#include "MiningBarge.hpp"

int const MiningBarge::_maxMiningLasers = 4;

IMiningLaser * MiningBarge::getMiningLaser (int index) const {
	if (index >= _maxMiningLasers)
		return NULL;
	else
		return _miningLasers[index];
}

int MiningBarge::getMiningLaserCount (void) const {
	int n;

	n = 0;
	for (int i = 0; i < _maxMiningLasers; i++)
		if (_miningLasers[i])
			n++;
	return n;
}

MiningBarge::MiningBarge (void) {_init();}

MiningBarge::MiningBarge (MiningBarge const & target) {*this = target;}

MiningBarge::~MiningBarge (void) {
	if (_miningLasers)
		delete _miningLasers;
}

void MiningBarge::equip (IMiningLaser * newMiningLaser) {
	for (int i = 0; i < _maxMiningLasers; i++)
		if (_miningLasers[i] == NULL) {
			_miningLasers[i] = newMiningLaser;
			std::cout << "Equiped new mining laser" << std::endl;
			return;
		}
	std::cout << "Can't equip any more lasers" << std::endl;
}

void MiningBarge::mine (IAsteroid * asteroid) const {
	for (int i = 0; i < _maxMiningLasers; i++)
		if (_miningLasers[i])
			_miningLasers[i]->mine(asteroid);
}

void MiningBarge::_init (void) {
	_miningLasers = new IMiningLaser* [_maxMiningLasers];

	for (int i = 0; i < _maxMiningLasers; i++)
		_miningLasers[i] = NULL;
}

MiningBarge & MiningBarge::operator = (MiningBarge const & target) {
	for (int i = 0; i < _maxMiningLasers; i++) {
		_miningLasers[i] = target.getMiningLaser(i);
	}
	return *this;
}

std::ostream & operator << (std::ostream & o, MiningBarge const & target) {
	o << "MiningBarge: currently equiped " << target.getMiningLaserCount() <<
		" mining lasers" << std::endl;
	return o;
}