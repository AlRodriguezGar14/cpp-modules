#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) { this->_w = NULL; };
HumanB::HumanB(std::string name, Weapon* w) : _w(w), _name(name) {};

HumanB::HumanB(const HumanB &ha) : _w(ha._w) {};

HumanB& HumanB::operator = (const HumanB &ha) {
	this->_name = ha._name;
	this->_w = ha._w;
	return *this;
}

HumanB::~HumanB() {};

void    HumanB::setWeapon(Weapon* w) { _w = w; };

void    HumanB::attack() {
	std::cout   << _name << " attacks with their "
				<< (_w != NULL ? _w->getType() : "(none)")
				<< std::endl;
}
