#include "Dog.hpp"

Dog::Dog() {
	m_type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &t_Dog) {
	delete brain;
	m_type = t_Dog.m_type;
	brain = new Brain(*t_Dog.brain);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
	std::cout << "Brain deleted before destructing the dog" << std::endl;
}

Dog& Dog::operator=(const Dog& t_Dog) {
	if (this != &t_Dog) {
		delete brain;
		brain = new Brain(*t_Dog.brain);
		m_type = t_Dog.m_type;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "woof, woof, ruff, ruff" << std::endl;
}

void Dog::setBrainIdea(const std::string &idea, int index) {
	brain->setIdea(idea, index);
}

std::string Dog::getBrainIdea(int index) const {
	return brain->getIdea(index);
}
