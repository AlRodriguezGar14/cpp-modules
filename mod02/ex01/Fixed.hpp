#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#define FRACTIONAL_BITS 8
#define MAX_INT pow(2, (32 - FRACTIONAL_BITS)) - 1
#define MIN_INT pow(2, -(32 - FRACTIONAL_BITS))

class Fixed {
public:
    Fixed ();
	Fixed(const int t_input);
	Fixed(const float t_input);
    Fixed (const Fixed &t_Fixed);
    ~Fixed ();
    Fixed& operator = (const Fixed &t_Fixed);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int									m_fixedPointValue;
	static const int m_fractionalBits = FRACTIONAL_BITS;

};

std::ostream& operator<<(std::ostream& os, const Fixed& t_Fixed);

#endif

