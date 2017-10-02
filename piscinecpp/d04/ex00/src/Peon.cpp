#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"


//Constructors & destructors
Peon::Peon (std::string const & name) : Victim(name) {}
Peon::Peon (Peon const & target) : Victim(target.getName()) {}

Peon::~Peon (void) {
	std::cout << color;
	std::cout << "Bleaurk...";
	std::cout << C_EOC << std::endl;
}

//Methods
void Peon::GetPolymorphed (void) const {
	std::cout << color;
	std::cout << getName() << " has been turned into a pink ponny!";
	std::cout << C_EOC << std::endl;
}

void Peon::_init (void) {
	std::cout << color;
	std::cout << "Zog zog.";
	std::cout << C_EOC << std::endl;
}

