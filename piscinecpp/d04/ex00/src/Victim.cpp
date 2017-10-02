#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

std::string const Victim::color = C_RED;

std::string const & Victim::getName(void) const {return _name;}

//Constructors & destructors

Victim::Victim (void) : _name("Victim") {_init();}
Victim::Victim (Victim const & target) : _name(target.getName()) {_init();}
Victim::Victim (std::string const & name) : _name(name) {_init();}

Victim::~Victim (void) {
	std::cout << color;
	std::cout << "Victim " << _name << " just died for no apparent reason!";
	std::cout << C_EOC << std::endl;
}

//Methods

void Victim::GetPolymorphed (void) const {
	std::cout << color;
	std::cout << getName() << " has been turned into a cute little sheep!";
	std::cout << C_EOC << std::endl;
}

void Victim::_init (void) {
	std::cout << color;
	std::cout << "Some random victim called " << _name << " just popped!";
	std::cout << C_EOC << std::endl;
}

//Operators
std::ostream & operator << (std::ostream & o, Victim const & target) {
	o << Victim::color;
	o << "I'm " << target.getName() << " and I like otters!";
	o << C_EOC;

	return o;
}