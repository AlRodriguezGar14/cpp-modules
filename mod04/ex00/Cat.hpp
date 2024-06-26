#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat ();
	Cat (const Cat &t_Cat);
	~Cat ();
	Cat& operator = (const Cat &t_Cat);
	void makeSound() const;
};


#endif
