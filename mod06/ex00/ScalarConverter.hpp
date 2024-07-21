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

	template<typename T>
	static bool ft_isnan(T nbr);
	template<typename T>
	static bool ft_isinf(T nbr);

	static bool isChar(const std::string& t_input);
	static void printChar(const std::string& t_input);
	static void printInt(const std::string& t_input);
	static void printFloat(const std::string& t_input);
	static void printDouble(const std::string& t_input);
public:

	static void convert(std::string const &input);
};

#endif
