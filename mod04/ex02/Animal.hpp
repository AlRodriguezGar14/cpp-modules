#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {

public:
	Animal ();
    Animal (std::string type);
    Animal (const Animal &t_Animal);
    virtual ~Animal ();
    Animal& operator = (const Animal &t_Animal);
	std::string getType() const;
	virtual void makeSound() const = 0;
	virtual void setBrainIdea(const std::string &t_idea, int t_index) = 0;
	virtual std::string getBrainIdea(int t_index) const = 0;

protected:
    	std::string m_type;
};

#endif
