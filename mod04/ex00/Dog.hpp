#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog ();
	Dog (const Dog &t_Dog);
	~Dog ();
	Dog& operator = (const Dog &t_Dog);
	void makeSound() const;
};


#endif
