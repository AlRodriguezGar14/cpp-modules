#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main() {

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("nonexistent");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	ICharacter* random(me);

	random->use(0, *bob);
	random->use(1, *bob);
	random->use(2, *bob);

	random->unequip(1);
	random->use(1, *bob);
	random->unequip(0);
	random->use(0, *bob);
	random->equip(src->createMateria("cure"));
	random->equip(src->createMateria("ice"));
	random->equip(src->createMateria("cure"));
	random->equip(src->createMateria("ice"));
	random->equip(src->createMateria("cure"));
	random->use(0, *bob);
	random->use(1, *bob);
	random->use(2, *bob);
	random->use(3, *bob);
	random->use(4, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}
