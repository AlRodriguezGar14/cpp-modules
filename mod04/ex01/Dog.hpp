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
	void setBrainIdea(const std::string &idea, int index);
	std::string getBrainIdea(int index) const;
private:
	Brain *brain;
};


#endif
