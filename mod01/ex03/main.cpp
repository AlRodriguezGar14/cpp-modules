#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {

	{
		Weapon club("crude spike club");
		// This won't compile, HumanA always is armed
		// HumanA bubu("Bubu");
		HumanA bubu("Bubu", club);

		bubu.attack();
		club.setType("weird new type of club");
		bubu.attack();
	}
	{
		Weapon club("Dudu's new club");
		HumanB dudu("Dudu");
		dudu.attack();
		dudu.setWeapon(&club);
		dudu.attack();
		club.setType("weird new type of club");
		dudu.attack();
	}
	{
		Weapon club("original club");
		// Won't compile, HumanB doesn't take a weapon in its constructor
		// HumanB foo("Foo", &club);
		HumanB foo("Foo");
		foo.setWeapon(&club);
		foo.attack();
	}
	return 0;
}