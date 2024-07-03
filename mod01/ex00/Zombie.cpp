#include "Zombie.hpp"

// Zombie::Zombie() {
// 	std::cout << "Zombie created" << std::endl;
// }

Zombie::Zombie(const Zombie &t_z) {
	*this = t_z;
	std::cout << "Zombie created" << std::endl;
}

Zombie& Zombie::operator = (const Zombie &t_z) {
	this->m_name = t_z.m_name;
	return *this;
}

Zombie::~Zombie() {
	std::cout << this->m_name << ": Zombie destroyed" << std::endl;
}

Zombie::Zombie(std::string t_name) {
	this->m_name = t_name;
	std::cout << m_name << ": Zombie created" << std::endl;
}

void Zombie::announce(void) {
	std::cout << this->m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
