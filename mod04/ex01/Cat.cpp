#include "Cat.hpp"

Cat::Cat(){
	m_type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &t_Cat) {
	delete brain;
	m_type = t_Cat.m_type;
	brain = new Brain(*t_Cat.brain);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
	std::cout << "Brain deleted before destructing the cat" << std::endl;
}

Cat& Cat::operator=(const Cat& t_Cat) {
	if (this != &t_Cat) {
		delete brain;
		m_type = t_Cat.m_type;
		brain = new Brain(*t_Cat.brain);
	}

	return *this;
}

void Cat::makeSound() const {
	std::cout << "miaow, mrrrrrr" << std::endl;
}

void Cat::setBrainIdea(const std::string &idea, int index) {
	brain->setIdea(idea, index);
}

std::string Cat::getBrainIdea(int index) const {
	return brain->getIdea(index);
}
