#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Zombie created" << std::endl;
}

Zombie::Zombie(const Zombie &z) {
	*this = z;
	std::cout << z._name << " created" << std::endl;
}

Zombie& Zombie::operator = (const Zombie &z) {
	this->_name = z._name;
	return *this;
}

Zombie::~Zombie() {
	std::cout << this->_name << ": Zombie destroyed" << std::endl;
}

Zombie::Zombie(std::string name) {
	this->_name = name;
	std::cout << name << ": Zombie created" << std::endl;
}

void Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}
