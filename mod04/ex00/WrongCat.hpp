#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat ();
	WrongCat (const WrongCat &t_WrongCat);
	~WrongCat ();
	WrongCat& operator = (const WrongCat &t_WrongCat);
};


#endif
