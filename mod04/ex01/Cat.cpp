#include "Cat.hpp"

Cat::Cat(){
	m_type = "Cat";
	m_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &t_Cat) {
	delete m_brain;
	m_type = t_Cat.m_type;
	m_brain = new Brain(*t_Cat.m_brain);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete m_brain;
	std::cout << "Brain deleted before destructing the cat" << std::endl;
}

Cat& Cat::operator=(const Cat& t_Cat) {
	if (this != &t_Cat) {
		delete m_brain;
		m_type = t_Cat.m_type;
		m_brain = new Brain(*t_Cat.m_brain);
	}

	return *this;
}

void Cat::makeSound() const {
	std::cout << "miaow, mrrrrrr" << std::endl;
}

void Cat::setBrainIdea(const std::string &t_idea, int t_index) {
	m_brain->setIdea(t_idea, t_index);
}

std::string Cat::getBrainIdea(int t_index) const {
	return m_brain->getIdea(t_index);
}
