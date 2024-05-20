#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	std::cout << "newZombie: ";
	Zombie *z = new Zombie(name);
	return z;
}
