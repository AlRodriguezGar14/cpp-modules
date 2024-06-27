#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

public:
	ScavTrap(std::string t_name);
	ScavTrap(const ScavTrap &t_ScavTrap);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& t_ScavTrap);
	void guardGate();
	void attack(const std::string &target);

	int getEnergyPoints() const;
};


#endif
