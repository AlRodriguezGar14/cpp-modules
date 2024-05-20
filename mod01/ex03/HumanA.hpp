#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
public:
	HumanA(std::string name, Weapon& w);
	HumanA(const HumanA &ha);
	HumanA& operator = (const HumanA &ha);
	~HumanA();
	void    attack();
private:
	Weapon&      _w;
	std::string _name;
};

#endif