#include "Fixed.hpp"

Fixed::Fixed() {
	m_fixedPointValue = 0;
}

Fixed::Fixed(const int t_input) {
	if (t_input >= MAX_INT) {
		std::cout << "Input is out of range, fixedPointValue set to 0" << std::endl;
		m_fixedPointValue = 0;
		return ;
	}
	m_fixedPointValue = round(t_input * (1 << m_fractionalBits));
}

Fixed::Fixed(const float t_input) {
	if (t_input >= MAX_INT) {
		std::cout << "Input is out of range, fixedPointValue set to 0" << std::endl;
		m_fixedPointValue = 0;
		return ;
	}
	m_fixedPointValue = round(t_input * (1 << m_fractionalBits));
}

Fixed::Fixed(const Fixed& t_Fixed) {
	m_fixedPointValue = t_Fixed.m_fixedPointValue;
}

Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed& t_Fixed) {
	if (this != &t_Fixed) {
		m_fixedPointValue = t_Fixed.m_fixedPointValue;
	}
	return *this;
}

int Fixed::getRawBits() const {
	return m_fixedPointValue;
}


float Fixed::toFloat() const {
	return ((float)m_fixedPointValue / (1 << m_fractionalBits));
}

// Comparison operators
bool Fixed::operator<(const Fixed& t_Fixed) const {
	return (m_fixedPointValue < t_Fixed.m_fixedPointValue);
}

bool Fixed::operator<=(const Fixed& t_Fixed) const {
	return (m_fixedPointValue <= t_Fixed.m_fixedPointValue);
}

bool Fixed::operator>(const Fixed& t_Fixed) const {
	return (m_fixedPointValue > t_Fixed.m_fixedPointValue);
}

bool Fixed::operator>=(const Fixed& t_Fixed) const {
	return (m_fixedPointValue >= t_Fixed.m_fixedPointValue);
}

bool Fixed::operator==(const Fixed& t_Fixed) const {
	return (m_fixedPointValue == t_Fixed.m_fixedPointValue);
}

bool Fixed::operator!=(const Fixed& t_Fixed) const {
	return (m_fixedPointValue != t_Fixed.m_fixedPointValue);
}

// Arithmetic operators
Fixed& Fixed::operator+(const Fixed& t_Fixed) {
	m_fixedPointValue += t_Fixed.m_fixedPointValue;
	return *this;
}

Fixed& Fixed::operator-(const Fixed& t_Fixed) {
	m_fixedPointValue -= t_Fixed.m_fixedPointValue;
	return *this;
}

// The scale needs to be re-adjusted
Fixed& Fixed::operator*(const Fixed& t_Fixed) {
	m_fixedPointValue = (m_fixedPointValue * t_Fixed.m_fixedPointValue) >> m_fractionalBits;
	return *this;
}

Fixed& Fixed::operator/(const Fixed& t_Fixed) {
	m_fixedPointValue = (m_fixedPointValue << m_fractionalBits) / t_Fixed.m_fixedPointValue;
	return *this;
}

// Increment / decrement
Fixed& Fixed::operator++() {
	m_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	m_fixedPointValue++;
	return tmp;
}

Fixed& Fixed::operator--() {
	m_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	m_fixedPointValue--;
	return tmp;
}


// Output operator
std::ostream& operator<<(std::ostream& os, const Fixed& t_Fixed) {
	os << t_Fixed.toFloat();
	return os;
}


const Fixed& Fixed::min(const Fixed& t_Fixed1, const Fixed& t_Fixed2) {
	return (t_Fixed1 < t_Fixed2) ? t_Fixed1 : t_Fixed2;
}

const Fixed& Fixed::max(const Fixed& t_Fixed1, const Fixed& t_Fixed2) {
	return (t_Fixed1 > t_Fixed2) ? t_Fixed1 : t_Fixed2;
}

Fixed& Fixed::min(Fixed& t_Fixed1, Fixed& t_Fixed2) {
	return (t_Fixed1 < t_Fixed2) ? t_Fixed1 : t_Fixed2;
}

Fixed& Fixed::max(Fixed& t_Fixed1, Fixed& t_Fixed2) {
	return (t_Fixed1 > t_Fixed2) ? t_Fixed1 : t_Fixed2;
}
