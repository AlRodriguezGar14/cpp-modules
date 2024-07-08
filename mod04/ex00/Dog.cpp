#include "Dog.hpp"

Dog::Dog() {
	m_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &t_Dog) : Animal() {
	m_type = t_Dog.m_type;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& t_Dog) {
	if (this != &t_Dog)
		*this = t_Dog;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "woof, woof, ruff, ruff" << std::endl;
}
