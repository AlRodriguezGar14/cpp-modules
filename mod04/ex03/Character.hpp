#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>
#include <cstring>

class Character : public ICharacter {
private:
	std::string m_name;
	AMateria* m_inventory[4];
	AMateria **m_floor;
	int     m_floorCount;
	void    moveFloor(AMateria* t_materia);

public:
	Character(std::string t_name);
	Character(const Character& t_character);
	Character& operator = (const Character& t_character);
	~Character();

	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	std::string const & getName() const;


};

#endif