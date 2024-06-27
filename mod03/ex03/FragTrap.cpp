#include "FragTrap.hpp"

FragTrap::FragTrap(std::string t_name): ClapTrap(t_name) {
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	std::cout
			<< "FragTrap named "
			<< m_name
			<< " set its specific values from the generic ClapTrap"
			<< std::endl;
	std::cout << "\tNew values: "
			  << "hit points: "
			  << m_hitPoints
			  << " energy points: "
			  << m_energyPoints
			  << " attack damage : "
			  << m_attackDamage
			  << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap &t_FragTrap) : ClapTrap(t_FragTrap.m_name) {
	*this = t_FragTrap;
}

FragTrap::~FragTrap() {
	std::cout
			<< "FragTrap named "
			<< m_name
			<< " destroyed"
			<< std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& t_FragTrap) {
	if (&t_FragTrap != this)
		*this = t_FragTrap;
	return *this;
}

void FragTrap::highFivesGuys(void) {
	if (m_hitPoints <= 0 || m_energyPoints <= 0) {
		std::cout
			<< m_name
			<< " is out. Can't high five with the bruv"
			<< std::endl;
		return ;
	}
	std::cout << "Hey bruv, high five!" << std::endl;
}
