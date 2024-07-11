#include "Character.hpp"
#include "Ice.hpp"

Character::Character(std::string t_name) : m_name(t_name), m_unequipedIndex(0) {
	std::cout << "Character constructor called" << std::endl;
	m_unequiped = NULL;
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
    m_unequipedIndex = t_character.m_unequipedIndex;
    for (int i = 0; i < 4; i++) {
        if (m_inventory[i] != NULL)
            delete m_inventory[i];
        m_inventory[i] = t_character.m_inventory[i]->clone();
    }
    if (m_unequiped != NULL)
        delete[] m_unequiped;
    m_unequiped = new AMateria*[m_unequipedIndex];
    for (int i = 0; i < m_unequipedIndex; i++)
        m_unequiped[i] = t_character.m_unequiped[i]->clone();
    return *this;
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	if (m_unequipedIndex != 0)
		delete[] m_unequiped;
}

void Character::relocateUnequiped(AMateria* m) {

	if (m_unequipedIndex == 0) {
		m_unequiped = new AMateria*[1];
		m_unequiped[0] = m;
		m_unequipedIndex++;
		return ;
	}

	AMateria **tmp = new AMateria*[m_unequipedIndex + 1];
	for (int i = 0; i < m_unequipedIndex; i++)
		tmp[i] = m_unequiped[i];
	tmp[m_unequipedIndex] = m;
	delete[] m_unequiped;
	m_unequiped = tmp;
	m_unequipedIndex++;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; ++i) {
		if (m_inventory[i] == NULL) {
			m_inventory[i] = m;
			return ;
		}
	}
//	relocateUnequiped(m);
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || m_inventory[idx] == NULL)
		return ;

//	relocateUnequiped(m_inventory[idx]);
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