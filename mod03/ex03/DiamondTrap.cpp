#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string t_name) : ClapTrap(t_name), ScavTrap(t_name), FragTrap(t_name) {

	m_name = ClapTrap::m_name;
	std::cout << YELLOW << "Replace the name of ClapTrap::m_name to " << t_name + "_clap_name" << DEFAULT << std::endl;
	ClapTrap::m_name = t_name + "_clap_name";
	m_hitPoints = FragTrap::m_hitPoints;
	std::cout << YELLOW << "Re-set the energyPoints to the default of ScavTrap, as it's been replaced when building FragTrap" << DEFAULT << std::endl;
	ClapTrap::m_energyPoints = 50;

	std::cout
			<< "DiamondTrap named "
			<< m_name
			<< " set its specific values from ClapTrap, FragTrap and ScavTrap"
			<< std::endl;
	std::cout << "\tNew values: "
			  << "hit points: "
			  << m_hitPoints
			  << " energy points: "
			  << m_energyPoints
			  << " attack damage : "
			  << m_attackDamage
			  << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &t_DiamondTrap) : ClapTrap(t_DiamondTrap.m_name), ScavTrap(t_DiamondTrap.m_name), FragTrap(t_DiamondTrap.m_name) {
	*this = t_DiamondTrap;
}

DiamondTrap::~DiamondTrap() {
	std::cout
			<< "DiamondTrap named "
			<< m_name
			<< " destroyed"
			<< std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& t_DiamondTrap) {
	if (&t_DiamondTrap != this)
		*this = t_DiamondTrap;
	return *this;
}

void DiamondTrap::attack(std::string const & target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout
			<< "DiamondTrap named "
			<< m_name
			<< " has its own ClapTrap name: "
			<< ClapTrap::m_name
			<< std::endl;
}

