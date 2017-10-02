#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner (void) {}

DeepCoreMiner::DeepCoreMiner (DeepCoreMiner const & target) {*this = target;}

DeepCoreMiner::~DeepCoreMiner (void) {}

void DeepCoreMiner::mine (IAsteroid * target) {
	if (target == NULL)
		return;

	std::cout << "* mining deep ... got " << target->beMined(this) <<
		"! *" << std::endl;
}

DeepCoreMiner & DeepCoreMiner::operator = (DeepCoreMiner const & target) {
	(void)target;
	return *this;
}

std::ostream & operator << (std::ostream & o, DeepCoreMiner const & target) {
	o << "It's a DeepCoreMiner" << std::endl;
	(void)target;
	return o;
}