#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {

	{
		Weapon club("crude spike club");
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
		HumanB foo("Foo", &club);
		foo.attack();
	}
	return 0;
}