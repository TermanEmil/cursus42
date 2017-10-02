#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

std::string const Sorcerer::color = C_CYAN;

//Getters & setters

std::string const & Sorcerer::getName (void) const {return _name;}
std::string const & Sorcerer::getTitle (void) const {return _title;}

//Constructors & Destructors

Sorcerer::Sorcerer (void) : _name("Sorcerer") {
	_title = "No Title";

	std::cout << color;
	std::cout << _name << ", " << _title << " is born!";
	std::cout << C_EOC << std::endl;
}

Sorcerer::Sorcerer (Sorcerer const & target) : _name(target.getName()) {
	_title = target.getTitle();

	std::cout << color;
	std::cout << _name << ", " << _title << " is born!";
	std::cout << C_EOC << std::endl;
}

Sorcerer::Sorcerer (std::string const & name, std::string const & title) :
	_name(name)
{
	_title = title;

	std::cout << color;
	std::cout << _name << ", " << _title << " is born!";
	std::cout << C_EOC << std::endl;
}

Sorcerer::~Sorcerer (void) {
	std::cout << color;
	std::cout << _name << ", " << _title << " is dead. Consequences will "
		"never be the same!";
	std::cout << C_EOC << std::endl;
}

//Methods
void Sorcerer::Polymorph (Victim const & target) const {
	target.GetPolymorphed();
}

//Operators

std::ostream & operator << (std::ostream & o, Sorcerer const & target) {
	o << Sorcerer::color << "I am " << target.getName() <<
	", " << target.getTitle() << " and I like ponies!" << C_EOC;
	return o;
}