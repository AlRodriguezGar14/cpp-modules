#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

	{
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
	}


	{
		FragTrap frag("Frag-Bro");
		frag.attack("Enemy1");
		frag.highFivesGuys();
		frag.attack("Enemy2");
		frag.attack("Enemy3");
		frag.takeDamage(50);
		frag.beRepaired(1000);
		frag.takeDamage(100);
		frag.beRepaired(100);
		frag.takeDamage(1000);
		frag.beRepaired(1000);
		frag.highFivesGuys();
		frag.attack("Enemy4");
		frag.takeDamage(2000);
		frag.beRepaired(3000);
		frag.highFivesGuys();
	}

	std::cout
		<< CYAN
		<< "From now, only DiamondTrap will have it's unique name"
		<< DEFAULT
		<< std::endl;
	DiamondTrap diamond("Diamond");
	diamond.attack("Enemy1");
	diamond.highFivesGuys();
	diamond.whoAmI();
	diamond.takeDamage(50);
	diamond.beRepaired(1000);
	diamond.guardGate();
	diamond.takeDamage(1050);
	diamond.beRepaired(1000);
	diamond.highFivesGuys();
	diamond.guardGate();
	diamond.whoAmI();


	return 0;
}
