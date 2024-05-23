#include "HumanA.hpp"


// Keeping in mind I have mandatory elements (weapon),
// This is the parameterized constructor
HumanA::HumanA(std::string t_name, Weapon& t_w) : m_w(t_w), m_name(t_name) {};

HumanA::HumanA(const HumanA &t_ha) : m_w(t_ha.m_w) {};

HumanA& HumanA::operator = (const HumanA &t_ha) {
	this->m_name = t_ha.m_name;
	this->m_w = t_ha.m_w;
	return *this;
}

HumanA::~HumanA() {};

void    HumanA::attack() {
	std::cout << m_name << " attacks with their " << m_w.getType() << std::endl;
}