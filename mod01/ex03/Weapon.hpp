#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
public:
	Weapon(std::string t_type);
	Weapon(const Weapon &t_w);
	Weapon& operator = (const Weapon &t_w);
	~Weapon();

	std::string getType();
	void        setType(std::string t_type);
private:
	std::string m_type;
};

#endif
