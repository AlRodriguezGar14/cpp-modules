#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define DEFAULT "\033[0m"

class ClapTrap {

public:
	ClapTrap(std::string t_name);
    ClapTrap (const ClapTrap &t_ClapTrap);
    ~ClapTrap ();
    ClapTrap& operator = (const ClapTrap &t_ClapTrap);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	std::string m_name;
	int m_hitPoints;
	int m_energyPoints;
	int m_attackDamage;

};

#endif
