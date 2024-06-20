#include "FixedPoint.hpp"

FixedPoint::FixedPoint() {
	std::cout << "Default constructor called" << std::endl;
	m_fixedPointValue = 0;
}

FixedPoint::FixedPoint(const FixedPoint& t_FixedPoint) {
	std::cout << "Copy constructor called" << std::endl;
	m_fixedPointValue = t_FixedPoint.m_fixedPointValue;
}

FixedPoint::~FixedPoint() {
	std::cout << "Destructor called" << std::endl;
}

FixedPoint& FixedPoint::operator=(const FixedPoint& t_FixedPoint) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &t_FixedPoint) {
		m_fixedPointValue = t_FixedPoint.m_fixedPointValue;
	}
	return *this;
}

int FixedPoint::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return m_fixedPointValue;
}

void FixedPoint::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	m_fixedPointValue = raw;
}
