#include "Zombie.hpp"

Zombie *newZombie(std::string t_name)
{
	std::cout << "newZombie: ";
	Zombie *z = new Zombie(t_name);
	return z;
}
