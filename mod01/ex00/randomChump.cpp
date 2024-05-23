#include "Zombie.hpp"

void randomChump(std::string t_name)
{
	std::cout << "randomChump: ";
	Zombie z(t_name);
	z.announce();
}
