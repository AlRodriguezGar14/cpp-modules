#include "HumanA.hpp"


// Keeping in mind I have mandatory elements (weapon),
// This is the parameterized constructor
HumanA::HumanA(std::string name, Weapon& w) : _w(w), _name(name) {};

HumanA::HumanA(const HumanA &ha) : _w(ha._w) {};

HumanA& HumanA::operator = (const HumanA &ha) {
	this->_name = ha._name;
	this->_w = ha._w;
	return *this;
}

HumanA::~HumanA() {};

void    HumanA::attack() {
	std::cout << _name << " attacks with their " << _w.getType() << std::endl;
}