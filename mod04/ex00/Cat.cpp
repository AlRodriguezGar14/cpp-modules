#include "Cat.hpp"

Cat::Cat(){
	m_type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &t_Cat) : Animal() {
	m_type = t_Cat.m_type;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& t_Cat) {
	if (this != &t_Cat)
		*this = t_Cat;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "miaow, mrrrrrr" << std::endl;
}
