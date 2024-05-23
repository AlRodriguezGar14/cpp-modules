#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
public:
	HumanA(std::string t_name, Weapon& t_w);
	HumanA(const HumanA &t_ha);
	HumanA& operator = (const HumanA &t_ha);
	~HumanA();
	void    attack();
private:
	Weapon&     m_w;
	std::string m_name;
};

#endif
