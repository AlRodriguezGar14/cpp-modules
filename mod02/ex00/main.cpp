#include "Fixed.hpp"

int main() {

	FixedPoint a;
	FixedPoint b(a);
	FixedPoint c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	a.setRawBits(42);
	std::cout << a.getRawBits() << std::endl;
	a.setRawBits(2147483648);
	std::cout << a.getRawBits() << std::endl;

	return 0;
}
