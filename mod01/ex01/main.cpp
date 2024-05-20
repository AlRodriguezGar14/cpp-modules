#include "Zombie.hpp"

int main() {

	std::cout << std::endl;
	std::cout << "Create" << std::endl;
	Zombie* horde = zombieHorde(10, "Foo");

	std::cout << std::endl;
	std::cout << "Announce" << std::endl;
	for (int i = 0; i != 10; ++i)
		horde[i].announce();

	std::cout << std::endl;
	std::cout << "Deallocate" << std::endl;
	delete[] horde;
	return 0;
}
