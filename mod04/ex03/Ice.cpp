#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice& t_ice) : AMateria(t_ice) {
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator = (const Ice& t_ice) {
	std::cout << "Ice assignation operator called" << std::endl;
	if (this == &t_ice)
		return *this;
	AMateria::operator=(t_ice);
	return *this;
}

AMateria* Ice::clone() const {
	std::cout << "Ice clone called" << std::endl;
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout   << "* shoots an ice bolt at "
				<< target.getName()
				<< " *" << std::endl;
}
