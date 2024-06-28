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
	void setBrainIdea(const std::string &t_idea, int t_index);
	std::string getBrainIdea(int t_index) const;
private:
	Brain *m_brain;
};


#endif
