#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string t_name) {
	m_name = t_name;
	m_hitPoints = 10;
	m_energyPoints = 10;
	m_attackDamage = 0;
	std::cout
		<< "ClapTrap "
		<< m_name
		<< " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& t_ClapTrap) {
	m_name = t_ClapTrap.m_name;
	m_hitPoints = t_ClapTrap.m_hitPoints;
	m_energyPoints = t_ClapTrap.m_energyPoints;
	m_attackDamage = t_ClapTrap.m_attackDamage;
}

ClapTrap::~ClapTrap() {
	std::cout
			<< "ClapTrap "
			<< m_name
			<< " destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& t_ClapTrap) {
	if (this != &t_ClapTrap) {
		m_name = t_ClapTrap.m_name;
		m_hitPoints = t_ClapTrap.m_hitPoints;
		m_energyPoints = t_ClapTrap.m_energyPoints;
		m_attackDamage = t_ClapTrap.m_attackDamage;
    }
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (m_hitPoints <= 0 || m_energyPoints <= 0) {
		std::cout
				<< m_name
				<< " is out. Can't attack anymore"
				<< std::endl;
		return ;
		return ;
	}
	--m_energyPoints;
	std::cout
		<< GREEN
		<< "The ClapTrap "
		<< m_name
		<< " attacks "
		<< target
		<< ", causing "
		<< m_attackDamage
		<< " points of damage"
		<< "\n\tEnergy points left: "
		<< m_energyPoints
		<< DEFAULT
		<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (m_hitPoints <= 0) {
		std::cout
			<< m_name
			<< " can't take more damage, it's dead"
			<< std::endl;
		return ;
	}
	m_hitPoints -= amount;
	std::cout
			<< RED
			<< m_name
			<< " receives "
			<< amount
			<< " points of damage\n\tHit points left: "
			<< m_hitPoints
			<< "\n\tEnergy points left: "
			<< m_energyPoints
			<< DEFAULT
			<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (m_hitPoints <= 0 || m_energyPoints <= 0) {
		std::cout
			<< m_name
			<< " is out. Can't repair itself"
			<< std::endl;
		return ;
	}
	m_hitPoints += amount;
	--m_energyPoints;
	std::cout
		<< BLUE
		<< m_name
		<< " repaired itself "
		<< amount
		<< " points\n\tHit points left: "
		<< m_hitPoints
		<< "\n\tEnergy points left: "
		<< m_energyPoints
		<< DEFAULT
		<< std::endl;
}

