#ifndef FIXEDPOINT_HPP
#define FIXEDPOINT_HPP

#include <iostream>
#define FRACTIONAL_BITS 8
#define MAX_INT (1 << (32 - FRACTIONAL_BITS)) - 1
#define MIN_INT -MAX_INT

class Fixed {
public:
    Fixed ();
	Fixed(const int t_input);
	Fixed(const float t_input);
    Fixed (const Fixed &t_Fixed);
    ~Fixed ();
    Fixed& operator = (const Fixed &t_Fixed);

	int getRawBits(void) const;
	float toFloat(void) const;

	bool operator>(const Fixed& t_Fixed) const;
	bool operator<(const Fixed& t_Fixed) const;
	bool operator>=(const Fixed& t_Fixed) const;
	bool operator<=(const Fixed& t_Fixed) const;
	bool operator==(const Fixed& t_Fixed) const;
	bool operator!=(const Fixed& t_Fixed) const;

	Fixed& operator+(const Fixed& t_Fixed);
	Fixed& operator-(const Fixed& t_Fixed);
	Fixed& operator*(const Fixed& t_Fixed);
	Fixed& operator/(const Fixed& t_Fixed);

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	static const Fixed& min(const Fixed& t_Fixed1, const Fixed& t_Fixed2);
	static const Fixed& max(const Fixed& t_Fixed1, const Fixed& t_Fixed2);
	static Fixed& min(Fixed& t_Fixed1, Fixed& t_Fixed2);
	static Fixed& max(Fixed& t_Fixed1, Fixed& t_Fixed2);


private:
	int									m_fixedPointValue;
	static const int m_fractionalBits = FRACTIONAL_BITS;

};

std::ostream& operator<<(std::ostream& os, const Fixed& t_Fixed);

#endif

