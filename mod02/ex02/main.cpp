#include "Fixed.hpp"

int main() {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	(a < b) ? std::cout << "a is less than b" << std::endl
			: std::cout << "b is less than a" << std::endl;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;

	Fixed c;
	Fixed const d( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "Subject tests:" << std::endl;
	std::cout << c << std::endl;
	std::cout << ++c << std::endl;
	std::cout << c << std::endl;
	std::cout << c++ << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << Fixed::max( c, d ) << std::endl;
	return 0;
}
