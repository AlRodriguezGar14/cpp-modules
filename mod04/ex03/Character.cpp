#include "Character.hpp"


Character::Character(std::string t_name) : m_name(t_name) {
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
}

Character::Character(const Character& t_character) {
	std::cout << "Character copy constructor called" << std::endl;
	*this = t_character;
}

Character& Character::operator = (const Character& t_character) {
    if (this == &t_character)
        return *this;
    m_name = t_character.m_name;
    for (int i = 0; i < 4; i++) {
        if (m_inventory[i] != NULL) {
	        delete m_inventory[i];
			m_inventory[i] = NULL;
		}
		if (t_character.m_inventory[i])
            m_inventory[i] = t_character.m_inventory[i]->clone();
    }
    return *this;
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;

	for (int i = 0; i < 4; i++) {
		if (m_inventory[i] != NULL) {
			delete m_inventory[i];
			m_inventory[i] = NULL;
		}
	}
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; ++i) {
		if (m_inventory[i] == NULL) {
			m_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || m_inventory[idx] == NULL)
		return ;

	m_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || m_inventory[idx] == NULL)
		return ;
	m_inventory[idx]->use(target);
}

std::string const& Character::getName() const {
	return m_name;
}