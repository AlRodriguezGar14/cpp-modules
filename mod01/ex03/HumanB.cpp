#include "HumanB.hpp"

HumanB::HumanB(std::string t_name) : m_name(t_name) { this->m_w = NULL; };
HumanB::HumanB(std::string t_name, Weapon* t_w) : m_w(t_w), m_name(t_name) {};

HumanB::HumanB(const HumanB &t_ha) : m_w(t_ha.m_w) {};

HumanB& HumanB::operator = (const HumanB &t_ha) {
	this->m_name = t_ha.m_name;
	this->m_w = t_ha.m_w;
	return *this;
}

HumanB::~HumanB() {};

void    HumanB::setWeapon(Weapon* t_w) { m_w = t_w; };

void    HumanB::attack() {
	std::cout << m_name << " attacks with their "
				<< (m_w != NULL ? m_w->getType() : "(none)")
				<< std::endl;
}
