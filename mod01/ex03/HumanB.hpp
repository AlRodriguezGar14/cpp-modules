#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
public:
	HumanB(std::string name);
	HumanB(std::string name, Weapon* w);
	HumanB(const HumanB &ha);
	HumanB& operator = (const HumanB &ha);
	~HumanB();
	void    attack();
	void    setWeapon(Weapon* w);
private:
	Weapon*     _w;
	std::string _name;
};

#endif