#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria {
public:
	Cure();
	virtual ~Cure();
	Cure(const Cure& t_cure);
	Cure& operator=(const Cure& t_cure);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif