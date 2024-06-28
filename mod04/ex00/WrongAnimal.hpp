#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {

public:
	WrongAnimal ();
    WrongAnimal (std::string type);
    WrongAnimal (const WrongAnimal &t_WrongAnimal);
    virtual ~WrongAnimal ();
    WrongAnimal& operator = (const WrongAnimal &t_WrongAnimal);
	std::string getType() const;
	void makeSound() const;

protected:
    	std::string m_type;
};

#endif
