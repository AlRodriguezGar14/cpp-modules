#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		m_inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& t_materiaSource) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = t_materiaSource;
}

MateriaSource& MateriaSource::operator = (const MateriaSource& t_materiaSource) {
	std::cout << "MateriaSource assignation operator called" << std::endl;
	if (this == &t_materiaSource)
		return *this;
	for (int i = 0; i < 4; i++) {
		if (m_inventory[i] != NULL) {
			delete m_inventory[i];
			m_inventory[i] = NULL;
		}
	}
	std::memcpy(m_inventory, t_materiaSource.m_inventory, 4 * sizeof(AMateria*));
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (m_inventory[i] != NULL) {
			delete m_inventory[i];
			m_inventory[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* t_materia) {
	for (int i = 0; i < 4; i++) {
		if (m_inventory[i] == NULL) {
			m_inventory[i] = t_materia;
			return ;
		}
	}
	std::cout << "Inventory is full, can't learn more materia" << std::endl;
	delete t_materia;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (m_inventory[i] != NULL && m_inventory[i]->getType() == type)
			return m_inventory[i]->clone();
	}
	return 0;
}