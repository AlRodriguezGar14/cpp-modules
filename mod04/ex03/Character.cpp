#include "Character.hpp"


Character::Character(std::string t_name) : m_name(t_name), m_floorCount(0) {
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
	m_floor = new AMateria*[m_floorCount + 1];
}

Character::Character(const Character& t_character) {
	std::cout << "Character copy constructor called" << std::endl;
	*this = t_character;
}

Character& Character::operator = (const Character& t_character) {
    if (this == &t_character)
        return *this;
    m_name = t_character.m_name;
	m_floorCount = t_character.m_floorCount;
    for (int i = 0; i < 4; i++) {
        if (m_inventory[i] != NULL) {
	        delete m_inventory[i];
			m_inventory[i] = NULL;
		}
		if (t_character.m_inventory[i])
            m_inventory[i] = t_character.m_inventory[i]->clone();
    }
	if (m_floor != NULL) {
		for (int i = 0; i < m_floorCount; i++) {
			delete m_floor[i];
			m_floor[i] = t_character.m_floor[i];
		}
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
	if (m_floor != NULL) {
		for (int i = 0; i < m_floorCount; i++) {
			delete m_floor[i];
			m_floor[i] = NULL;
		}
	}
	delete [] m_floor;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i <= 4; ++i) {
		if (m_inventory[i] == NULL) {
			m_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
	moveFloor();
	m_floor[m_floorCount] = m;
	m_floorCount++;
}

void Character::moveFloor() {
	AMateria** newFloor = new AMateria*[m_floorCount + 1];
	for (int i = 0; i < m_floorCount; i++)
		newFloor[i] = m_floor[i];
	delete[] m_floor;
	m_floor = newFloor;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || m_inventory[idx] == NULL)
		return ;
	moveFloor();
	m_floor[m_floorCount] = m_inventory[idx];
	m_inventory[idx] = NULL;
	m_floorCount++;
	std::cout << "Unequipped " << m_floor[m_floorCount - 1]->getType() << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || m_inventory[idx] == NULL)
		return ;
	m_inventory[idx]->use(target);
}

std::string const& Character::getName() const {
	return m_name;
}