#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Zombie created" << std::endl;
}

Zombie::Zombie(const Zombie &z) {
	*this = z;
	std::cout << z.m_name << " created" << std::endl;
}

Zombie& Zombie::operator = (const Zombie &z) {
	this->m_name = z.m_name;
	return *this;
}

Zombie::~Zombie() {
	std::cout << this->m_name << ": Zombie destroyed" << std::endl;
}

Zombie::Zombie(std::string t_name) {
	this->m_name = t_name;
	std::cout << t_name << ": Zombie created" << std::endl;
}

void Zombie::announce(void) {
	std::cout << this->m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string t_name)
{
	this->m_name = t_name;
}
