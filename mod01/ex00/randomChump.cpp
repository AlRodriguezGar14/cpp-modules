#include "Zombie.hpp"

void randomChump(std::string name)
{
	std::cout << "randomChump: ";
	Zombie z(name);
	z.announce();
}
