#include "StripMiner.hpp"

StripMiner::StripMiner (void) {}

StripMiner::StripMiner (StripMiner const & target) {*this = target;}

StripMiner::~StripMiner (void) {}

void StripMiner::mine (IAsteroid * target) {
	if (target == NULL)
		return;

	std::cout << "* strip mining ... got " << target->beMined(this) <<
		"! *" << std::endl;
}

StripMiner & StripMiner::operator = (StripMiner const & target) {
	(void)target;
	return *this;
}

std::ostream & operator << (std::ostream & o, StripMiner const & target) {
	o << "It's a StripMiner" << std::endl;
	(void)target;
	
	return o;
}