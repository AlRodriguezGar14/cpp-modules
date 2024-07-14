#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <cstring>

class MateriaSource : public IMateriaSource {
private:
	AMateria* m_inventory[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& t_materiaSource);
	MateriaSource& operator = (const MateriaSource& t_materiaSource);
	~MateriaSource();

	void learnMateria(AMateria* t_materia);
	AMateria* createMateria(std::string const & type);
};

#endif
