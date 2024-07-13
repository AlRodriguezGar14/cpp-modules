#include "Ice.hpp"
#include "AMateria.hpp"
#include "Character.hpp"

int main() {

	Character character("Foo");
	Character *character2 = new Character("Bar");
	Character character3("Baz");
	Ice *ice = new Ice();
	Ice *ice3 = new Ice();
	character.equip(ice);
	// This generates memory leaks because there's no way to delete it. Don't you dare to use it this way
	character.equip(new Ice());
	character.equip(ice3);
//	character3 = character;
//	character3.use(0, *character2);
	character.use(0, *character2);
//	delete ice3;
//	delete ice;
	delete character2;
}
