#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : m_type(type) {
	// std::cout << "AMateria \"interface\" constructor called" << std::endl;
}

AMateria& AMateria::operator = (const AMateria& t_amateria) {
	// std::cout << "AMateria \"interface\" assignation operator called" << std::endl;
	if (this == &t_amateria)
		return *this;
	m_type = t_amateria.m_type;
	return *this;
}

AMateria::AMateria(const AMateria& t_amateria) : m_type(t_amateria.m_type) {
	// std::cout << "AMateria \"interface\" copy constructor called" << std::endl;
}

AMateria::~AMateria() {
	// std::cout << "AMateria \"interface\" destructor called" << std::endl;
}

std::string const & AMateria::getType() const {
	return m_type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}