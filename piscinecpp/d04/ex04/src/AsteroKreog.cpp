#include "AsteroKreog.hpp"
#include "IMiningLaser.hpp"

std::string AsteroKreog::getName (void) const {return "AsteroKreog";}

AsteroKreog::AsteroKreog (void) {}

AsteroKreog::AsteroKreog (AsteroKreog const & target) {*this = target;}

AsteroKreog::~AsteroKreog (void) {}

std::string AsteroKreog::beMined (StripMiner const * tool) const {
	(void)tool;
	return "Flavium";
}

std::string AsteroKreog::beMined (DeepCoreMiner const * tool) const {
	(void)tool;
	return "Thorite";
}

AsteroKreog & AsteroKreog::operator = (AsteroKreog const & target) {
	(void)target;
	return *this;
}

std::ostream & operator << (std::ostream & o, AsteroKreog const & target) {
	o << "This is: " << target.getName() << std::endl;
	return o;
}