#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
public:
	HumanB(std::string t_name);
	HumanB(std::string t_name, Weapon* t_w);
	HumanB(const HumanB &t_ha);
	HumanB& operator = (const HumanB &t_ha);
	~HumanB();
	void    attack();
	void    setWeapon(Weapon* t_w);
private:
	Weapon*     m_w;
	std::string m_name;
};

#endif
