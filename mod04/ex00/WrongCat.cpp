#include "WrongCat.hpp"

WrongCat::WrongCat(){
	m_type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &t_WrongCat) : WrongAnimal() {
	m_type = t_WrongCat.m_type;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& t_WrongCat) {
	if (this != &t_WrongCat)
		m_type = t_WrongCat.m_type;
	return *this;
}
