#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string t_name): ClapTrap(t_name) {
	std::cout << "ClapTrap built: "
		<< "hit points: "
		<< m_hitPoints
		<< " energy points: "
		<< m_energyPoints
		<< " attack damage : "
		<< m_attackDamage
		<< std::endl;
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
	std::cout
		<< "ScavTrap named "
		<< m_name
		<< " set its specific values from the generic ClapTrap"
		<< std::endl;
	std::cout << "New values: "
			  << "hit points: "
			  << m_hitPoints
			  << " energy points: "
			  << m_energyPoints
			  << " attack damage : "
			  << m_attackDamage
			  << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &t_ScavTrap) : ClapTrap(t_ScavTrap.m_name) {
	*this = t_ScavTrap;
}

ScavTrap::~ScavTrap() {
	std::cout
		<< "ScavTrap named "
		<< m_name
		<< " destroyed"
		<< std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& t_ScavTrap) {
	if (&t_ScavTrap != this)
		*this = t_ScavTrap;
	return *this;
}

void ScavTrap::guardGate() {
	if (m_hitPoints <= 0 || m_energyPoints <= 0) {
		std::cout
			<< "ScavTrap "
			<< m_name
			<< " is out, can't guard anything"
			<< std::endl;
	}
	std::cout
		<< "ScavTrap "
		<< m_name
		<< " entered the Gate Keper mode"
		<< std::endl;
}

void ScavTrap::attack(const std::string &target) {

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
			<< "The ScavTrap "
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
