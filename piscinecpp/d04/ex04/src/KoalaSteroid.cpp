#include "KoalaSteroid.hpp"
#include "IMiningLaser.hpp"

std::string KoalaSteroid::getName (void) const {return "KoalaSteroid";}

KoalaSteroid::KoalaSteroid (void) {}

KoalaSteroid::KoalaSteroid (KoalaSteroid const & target) {*this = target;}

KoalaSteroid::~KoalaSteroid (void) {}

std::string KoalaSteroid::beMined (StripMiner const * tool) const {
	(void)tool;
	return "Krpite";
}

std::string KoalaSteroid::beMined (DeepCoreMiner const * tool) const {
	(void)tool;
	return "Zazium";
}

KoalaSteroid & KoalaSteroid::operator = (KoalaSteroid const & target) {
	(void)target;
	return *this;
}

std::ostream & operator << (std::ostream & o, KoalaSteroid const & target) {
	o << "This is: " << target.getName() << std::endl;
	return o;
}