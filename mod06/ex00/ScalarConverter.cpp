#include "ScalarConverter.hpp"

#include <cstdlib>
#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
// TOREFACTORRR

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &src) { *this = src; }
ScalarConverter& ScalarConverter::operator=(ScalarConverter const &src) { (void)src; return *this; }
ScalarConverter::~ScalarConverter() {}

template<typename T>
bool ScalarConverter::isChar(const T& t_input) {
	if (t_input.length() == 1 && !isdigit(t_input)) {
		return true;
	}
	try {
		int nbr = static_cast<int>(t_input);
		if (isprint(nbr)) {
			return true;
		}
	} catch (std::exception& e) {
	}
	return false;
}

template<typename T>
bool ScalarConverter::ft_isnan(T nbr) {
	return nbr != nbr;
}

template<typename T>
bool ScalarConverter::ft_isinf(T nbr) {
	return nbr == std::numeric_limits<T>::infinity() || nbr == -std::numeric_limits<T>::infinity();
}

template<typename T>
void ScalarConverter::printChar(const T& t_input) {
	std::cout << "char: ";
	try {
		int nbr = static_cast<int>(t_input);
		if (isprint(nbr)) {
			std::cout << "'" << static_cast<char>(nbr) << "'" << std::endl;
			return ;
		}
		std::cout << "Non displayable" << std::endl;
		return ;
	} catch (std::exception& e) {
		std::cout << "impossible" << std::endl;
	}
}

template<typename T>
void ScalarConverter::printInt(const T& t_input) {
	std::cout << "int: ";
	try {
		std::cout << static_cast<int>(t_input) << std::endl;
	} catch (std::exception& e) {
		std::cout << "impossible" << std::endl;
	}
}


template<typename T>
void ScalarConverter::printFloat(const T& t_input) {
	std::cout << "float: ";

	try {
		if (ft_isnan(t_input) || ft_isinf(t_input)) {
			std::cout << "nanf" << std::endl;
			return ;
		}
		if (t_input > std::numeric_limits<float>::max()) {
			std::cout << "+inff" << std::endl;
			return ;
		}
		if (t_input < -std::numeric_limits<float>::max()) {
			std::cout << "-inff" << std::endl;
			return ;
		}
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>((t_input)) << "f" << std::endl;
	} catch (std::exception& e) {
		std::cout << "impossible" << std::endl;
	}
}

template<typename T>
void ScalarConverter::printDouble(const T& t_input) {
	std::cout << "double: ";

	try {
		if (ft_isnan(t_input) || ft_isinf(t_input)) {
			std::cout << "nan" << std::endl;
			return ;
		}
		if (t_input > std::numeric_limits<double>::max()) {
			std::cout << "+inf" << std::endl;
			return ;
		}
		if (t_input < -std::numeric_limits<double>::max()) {
			std::cout << "-inf" << std::endl;
			return ;
		}
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(t_input) << std::endl;
	} catch (std::exception& e) {
		std::cout << "impossible" << std::endl;
	}

}


void ScalarConverter::convert(const std::string& t_input) {

	ConvertedType converted_type;

	int converted_type_idx = 0;

	if (t_input.find('.') != std::string::npos) {
		if (t_input.find('f') != std::string::npos) {
			try {
				converted_type.setFloat(static_cast<float>(std::atof(t_input.c_str())));
				converted_type_idx = 3;
			} catch (std::exception& e) {
			}
		} else {
			try {
				converted_type.setDouble(std::atof(t_input.c_str()));
				converted_type_idx = 4;
			} catch (std::exception& e) {
			}
		}
	}
	else {
		if (t_input.length() == 1 && !isdigit(t_input[0])) {
			converted_type.setChar(t_input[0]);
			converted_type_idx = 1;
		} else {
			try {
				converted_type.setInt(std::atoi(t_input.c_str()));
				converted_type_idx = 2;
			} catch (std::exception& e) {
			}
		}
	}
	if (converted_type_idx == 0) {
		std::cout << "impossible" << std::endl;
		return ;
	}

	if (converted_type_idx == 1) {

		printChar(converted_type.getChar());
		printInt(converted_type.getChar());
		printFloat(converted_type.getChar());
		printDouble(converted_type.getChar());
	}
	if (converted_type_idx == 2) {

		printChar(converted_type.getInt());
		printInt(converted_type.getInt());
		printFloat(converted_type.getInt());
		printDouble(converted_type.getInt());
	}
	if (converted_type_idx == 3) {

		printChar(converted_type.getFloat());
		printInt(converted_type.getFloat());
		printFloat(converted_type.getFloat());
		printDouble(converted_type.getFloat());
	}
	if (converted_type_idx == 4) {

		printChar(converted_type.getDouble());
		printInt(converted_type.getDouble());
		printFloat(converted_type.getDouble());
		printDouble(converted_type.getDouble());
	}
}
