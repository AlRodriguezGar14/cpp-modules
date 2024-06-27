#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
	FragTrap(std::string t_name);
	FragTrap(const FragTrap &t_FragTrap);
	~FragTrap();
	FragTrap& operator=(const FragTrap& t_FragTrap);
	void highFivesGuys(void);
};

#endif
