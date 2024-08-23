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
#include "ConvertedType.hpp"

enum type {
	IMPOSSIBLE = 0,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};


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

	template<typename T>
	static bool isChar(const T& t_input);
	template<typename T>
	static void printChar(const T& t_input);
	template<typename T>
	static void printInt(const T& t_input);
	template<typename T>
	static void printFloat(const T& t_input);
	template<typename T>
	static void printDouble(const T& t_input);

public:

	static void convert(std::string const &input);
};

#endif
