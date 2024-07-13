#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure constructor called" << std::endl;
};

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure& t_cure) : AMateria(t_cure) {
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator = (const Cure& t_cure) {
	std::cout << "Cure assignation operator called" << std::endl;
	if (this == &t_cure) {
		return *this;
	}
	AMateria::operator=(t_cure);
	return *this;
}

AMateria* Cure::clone() const {
	std::cout << "Cure clone called" << std::endl;
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout   << "* heals "
	            << target.getName()
	            << "'s wounds *" << std::endl;
}