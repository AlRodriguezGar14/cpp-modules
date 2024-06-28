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

void Animal::makeSound() const {
	std::cout
		<< "What is the sound but an echo of existence, and what is my essence if not the truth of my being?"
		<< " **starts growling**"
		<< std::endl;
}

void Animal::setBrainIdea(const std::string &t_idea, int t_index) {
	(void)t_idea;
	(void)t_index;
};

std::string Animal::getBrainIdea(int t_index) const {
	(void)t_index;
	return "I have no brain, I am ethereal";
};
