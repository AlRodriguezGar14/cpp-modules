#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
	Dog ();
	Dog (const Dog &t_Dog);
	~Dog ();
	Dog& operator = (const Dog &t_Dog);
	void makeSound() const;
	void setBrainIdea(const std::string &t_idea, int t_index);
	std::string getBrainIdea(int t_index) const;
private:
	Brain *m_brain;
};


#endif
