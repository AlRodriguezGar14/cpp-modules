#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#define FRACTIONAL_BITS 8

class FixedPoint {
public:
    FixedPoint ();
    FixedPoint (const FixedPoint &t_FixedPoint);
    ~FixedPoint ();
    FixedPoint& operator = (const FixedPoint &t_FixedPoint);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int	m_fixedPointValue;
	static const int m_fractionalBits = FRACTIONAL_BITS;

};

#endif

