#include "Dog.hpp"

Dog::Dog() {
	m_type = "Dog";
	m_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &t_Dog) : Animal() {
	delete m_brain;
	m_type = t_Dog.m_type;
	m_brain = new Brain(*t_Dog.m_brain);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete m_brain;
	std::cout << "Brain deleted before destructing the dog" << std::endl;
}

Dog& Dog::operator=(const Dog& t_Dog) {
	if (this != &t_Dog) {
		delete m_brain;
		m_brain = new Brain(*t_Dog.m_brain);
		m_type = t_Dog.m_type;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "woof, woof, ruff, ruff" << std::endl;
}

void Dog::setBrainIdea(const std::string &t_idea, int t_index) {
	m_brain->setIdea(t_idea, t_index);
}

std::string Dog::getBrainIdea(int t_index) const {
	return m_brain->getIdea(t_index);
}
