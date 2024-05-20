#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
public:
	Weapon(std::string type);
	Weapon(const Weapon &w);
	Weapon& operator = (const Weapon &w);
	~Weapon();

	std::string getType();
	void        setType(std::string type);
private:
	std::string _type;
};

#endif