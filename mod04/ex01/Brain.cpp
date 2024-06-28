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

void Brain::setIdea(const std::string &t_idea, int t_index) {
	if (t_index >= 0 && t_index < 100)
		m_ideas[t_index] = t_idea;
}

std::string Brain::getIdea(int t_index) const {
	if (t_index >= 0 && t_index < 100)
		return m_ideas[t_index];
	return "Invalid index";
}
