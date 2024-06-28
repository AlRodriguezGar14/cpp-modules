#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : m_type("generic wrong animal") {
	std::cout << "WrongAnimal with no type created" << std::endl;
}
WrongAnimal::WrongAnimal(std::string t_type) : m_type(t_type) {
	std::cout << "WrongAnimal constructor with type " << m_type << " called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& t_WrongAnimal) {
	m_type = t_WrongAnimal.m_type;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& t_WrongAnimal) {
	if (this != &t_WrongAnimal) {
		m_type = t_WrongAnimal.m_type;
    }
	return *this;
}

std::string WrongAnimal::getType() const {
	return m_type;
}

void WrongAnimal::makeSound() const {
	std::cout
		<< "brrr, brrrr, badamdum brrr"
		<< std::endl;
}
