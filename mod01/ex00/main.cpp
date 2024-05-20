#include "Zombie.hpp"

int main() {

	Zombie *z = newZombie("Foo");
	z->announce();

	std::cout << std::endl;
	randomChump("Bar");

	std::cout << std::endl;
	std::cout << "Foo needs to be destroyed manually" << std::endl;
	delete z;

	return 0;
}
