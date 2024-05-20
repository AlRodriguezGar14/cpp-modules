#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {};
Weapon::Weapon(const Weapon &w) {
	*this = w;
}
Weapon& Weapon::operator = (const Weapon &w) {
	this->_type = w._type;
	return *this;
}
Weapon::~Weapon() {
//	std::cout << "Weapon of type " << this->_type << " destroyed" << std::endl;
}


std::string Weapon::getType() {
	return this->_type;
}

void    Weapon::setType(std::string type) {
	this->_type = type;
}