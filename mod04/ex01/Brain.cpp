#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		m_ideas[i] = "Idea " + std::to_string(i);
	}
	std::cout << "Brain created with 100 ideas" << std::endl;
}

Brain::Brain(const Brain& t_Brain) {
	for (int i = 0; i < 100; i++)
		m_ideas[i] = t_Brain.m_ideas[i];
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& t_Brain) {
	if (this != &t_Brain) {
		for (int i = 0; i < 100; i++)
			m_ideas[i] = t_Brain.m_ideas[i];
    }
	return *this;
}

void Brain::setIdea(const std::string &idea, int index) {
	if (index >= 0 && index < 100)
		m_ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return m_ideas[index];
	return "Invalid index";
}
