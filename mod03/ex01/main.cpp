#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

	{
		ClapTrap hero("Hero");
		hero.attack("Enemy1");
		hero.attack("Enemy2");
		hero.takeDamage(3);
		hero.attack("Enemy3");
		hero.attack("Enemy4");
		hero.takeDamage(6);
		hero.beRepaired(2);
		hero.beRepaired(1);
		hero.beRepaired(1);
		hero.beRepaired(1);
		hero.attack("Enemy5");
		hero.attack("Enemy6");
		hero.attack("Enemy7");
		hero.beRepaired(100);
		hero.takeDamage(100);
		hero.beRepaired(100);
		hero.attack("Enemy8");
		hero.takeDamage(1);
	}

	ScavTrap keeper("Keeper");
	keeper.attack("Enemy1");
	keeper.attack("Enemy2");
	keeper.attack("Enemy3");
	keeper.guardGate();
	keeper.takeDamage(20);
	keeper.beRepaired(20);
	keeper.takeDamage(40);
	keeper.beRepaired(40);
	keeper.takeDamage(400);
	keeper.beRepaired(40);

	return 0;
}
