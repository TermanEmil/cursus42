#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* zaz = new Character("zaz");
	AMateria* tmp;

	tmp = src->createMateria("Ice");
	zaz->equip(tmp);

	tmp = src->createMateria("Cure");
	zaz->equip(tmp);

	ICharacter* bob = new Character("bob");
	zaz->use(0, *bob);
	zaz->use(0, *bob);
	zaz->use(1, *bob);

	std::cout << *(static_cast<Character*> (zaz)->getItem(0));
	std::cout << *(static_cast<Character*> (zaz)->getItem(1));

	delete bob;
	delete zaz;
	delete src;
	return 0;
}