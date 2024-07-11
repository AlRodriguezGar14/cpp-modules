#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria {
public:
	Ice();
	virtual ~Ice();
	Ice(const Ice& t_ice);
	Ice& operator=(const Ice& t_ice);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif