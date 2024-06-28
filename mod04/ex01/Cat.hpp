#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	Cat ();
	Cat (const Cat &t_Cat);
	~Cat ();
	Cat& operator = (const Cat &t_Cat);
	void makeSound() const;
	void setBrainIdea(const std::string &idea, int index);
	std::string getBrainIdea(int index) const;
private:
	Brain *brain;
};


#endif
