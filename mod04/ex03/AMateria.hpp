#ifndef IMATERIA_HPP
#define IMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
protected:
	std::string m_type;
public:
	AMateria(std::string const & type);
	AMateria& operator = (const AMateria& t_amateria);
	AMateria(const AMateria& t_amateria);
	virtual ~AMateria();
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif