#include "Animal.hpp"

Animal::Animal() : m_type("ethereal") {
	std::cout << "Animal with no type created" << std::endl;
}
Animal::Animal(std::string t_type) : m_type(t_type) {
	std::cout << "Animal constructor with type " << m_type << " called" << std::endl;
}

Animal::Animal(const Animal& t_Animal) {
	m_type = t_Animal.m_type;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& t_Animal) {
	if (this != &t_Animal) {
		m_type = t_Animal.m_type;
    }
	return *this;
}

std::string Animal::getType() const {
	return m_type;
}
