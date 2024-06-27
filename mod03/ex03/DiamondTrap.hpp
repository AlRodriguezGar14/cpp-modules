#ifndef DIAMONGTRAP_HPP
#define DIAMONGTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap {
public:
	DiamondTrap(std::string t_name);
	DiamondTrap(const DiamondTrap &t_DiamondTrap);
	~DiamondTrap();
	DiamondTrap& operator=(const DiamondTrap &t_DiamondTrap);
	void whoAmI();
	void attack(const std::string &target);
private:
	std::string m_name;
};

#endif
