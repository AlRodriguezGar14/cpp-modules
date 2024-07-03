#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	m_fixedPointValue = 0;
}

// input * 2 ^ (fractional bits)
// is the same af shifting to the left fractional-bits-times (next function)
Fixed::Fixed(const int t_input) {
	std::cout << "Int constructor called" << std::endl;
	if (t_input >= MAX_INT) {
		std::cout << "Input is out of range, as it requires more bits than the available ones. fixedPointValue set to 0" << std::endl;
		m_fixedPointValue = 0;
		return ;
	}
	m_fixedPointValue = round(t_input * (pow(2, m_fractionalBits)));
}

Fixed::Fixed(const float t_input) {
	std::cout << "Float constructor called" << std::endl;
	if (t_input >= MAX_INT) {
		std::cout << "Input is out of range, as it requires more bits than the available ones. fixedPointValue set to 0" << std::endl;
		m_fixedPointValue = 0;
		return ;
	}
	m_fixedPointValue = round(t_input * (1 << m_fractionalBits));
}

Fixed::Fixed(const Fixed& t_Fixed) {
	std::cout << "Copy constructor called" << std::endl;
	m_fixedPointValue = t_Fixed.m_fixedPointValue;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& t_Fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &t_Fixed) {
		m_fixedPointValue = t_Fixed.m_fixedPointValue;
	}
	return *this;
}

float Fixed::toFloat() const {
	return ((float)m_fixedPointValue * (pow(2, -m_fractionalBits)));
}

int Fixed::toInt() const {
	return (round(m_fixedPointValue * (pow(2, -m_fractionalBits))));
}

std::ostream& operator<<(std::ostream& os, const Fixed& t_Fixed) {
	os << t_Fixed.toFloat();
	return os;
}
