#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>
#include <exception>
#include <stdexcept>
#include <cstdlib>
#include <cmath>
#include <limits>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &src);
	~ScalarConverter();
	ScalarConverter &operator=(ScalarConverter const &src);
public:

	static void convert(std::string const &input);
};

#endif