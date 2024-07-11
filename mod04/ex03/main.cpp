#include "Ice.hpp"
#include "AMateria.hpp"
#include "Character.hpp"

int main() {

	Character character("Foo");
	Character *character2 = new Character("Bar");
	Ice *ice = new Ice();
	Ice ice2;
	Ice *ice3 = new Ice();
	Ice ice4;
	Ice ice5;
	Ice ice6;
	character.equip(ice);
	// This generates memory leaks because there's no way to delete it. Don't you dare to use it this way
//	character.equip(new Ice());
	character.equip(&ice2);
	character.equip(ice3);
	character.equip(&ice4);
	character.equip(&ice5);
	character.equip(&ice6);
	character.unequip(0);
	character.equip(&ice6);
	character.use(0, *character2);
	delete ice3;
	delete ice;
	delete character2;
}
