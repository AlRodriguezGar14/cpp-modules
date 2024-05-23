#include "Weapon.hpp"

Weapon::Weapon(std::string t_type) : m_type(t_type) {};
Weapon::Weapon(const Weapon &t_w) {
	*this = t_w;
}
Weapon& Weapon::operator = (const Weapon &t_w) {
	this->m_type = t_w.m_type;
	return *this;
}
Weapon::~Weapon() {
//	std::cout << "Weapon of type " << this->m_type << " destroyed" << std::endl;
}


std::string Weapon::getType() {
	return this->m_type;
}

void    Weapon::setType(std::string t_type) {
	this->m_type = t_type;
}