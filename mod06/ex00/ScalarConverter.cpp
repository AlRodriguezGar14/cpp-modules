#include "ScalarConverter.hpp"

#include <cstdlib>
#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &src) { *this = src; }
ScalarConverter& ScalarConverter::operator=(ScalarConverter const &src) { (void)src; return *this; }
ScalarConverter::~ScalarConverter() {}

template<typename T>
bool ScalarConverter::isChar(const T& t_input) {
	return t_input >= std::numeric_limits<char>::min() && t_input <= std::numeric_limits<char>::max();
}

template<typename T>
bool ScalarConverter::ft_isnan(T nbr) {
	return nbr != nbr;
}

template<typename T>
bool ScalarConverter::ft_isinf(T nbr) {
	return nbr == std::numeric_limits<T>::infinity() || nbr == -std::numeric_limits<T>::infinity();
}

template <typename T>
void ScalarConverter::printChar(const T& t_input) {
	std::cout << "char: ";
	if (isChar(t_input)) {
		if (ft_isnan(t_input) || ft_isinf(t_input)) {
			std::cout << "impossible" << std::endl;
			return ;
		}
		char c = static_cast<char>(t_input);
		if (c >= std::numeric_limits<char>::min() && c <= std::numeric_limits<char>::max() && isprint(c)) {
			std::cout << "'" << c << "'" << std::endl;
		} else {
			std::cout << "Non displayable" << std::endl;
		}
	} else {
		std::cout << "impossible" << std::endl;
	}
}

template<typename T>
void ScalarConverter::printInt(const T& t_input) {
	std::cout << "int: ";
	try {
		if (ft_isnan(t_input) || ft_isinf(t_input)) {
			std::cout << "impossible" << std::endl;
			return ;
		}
		std::cout << static_cast<int>(t_input) << std::endl;
	} catch (std::exception& e) {
		std::cout << "impossible" << std::endl;
	}
}

template<typename T>
void ScalarConverter::printFloat(const T& t_input) {
    std::cout << "float: ";
    if (std::isnan(t_input)) {
        std::cout << "nanf" << std::endl;
    } else if (std::isinf(t_input)) {
        std::cout << (t_input > 0 ? "+inff" : "-inff") << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(t_input) << "f" << std::endl;
    }
}

template<typename T>
void ScalarConverter::printDouble(const T& t_input) {
    std::cout << "double: ";
    if (std::isnan(t_input)) {
        std::cout << "nan" << std::endl;
    } else if (std::isinf(t_input)) {
        std::cout << (t_input > 0 ? "+inf" : "-inf") << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1) << static_cast<double>(t_input) << std::endl;
    }
}

void ScalarConverter::convert(const std::string& t_input) {

    ConvertedType converted_type;
    int converted_type_idx = IMPOSSIBLE;

    if (t_input.length() == 1 && !std::isdigit(t_input[0])) {
        converted_type.setChar(t_input[0]);
        converted_type_idx = CHAR;
    } else {
        char* endptr;
        double value = std::strtod(t_input.c_str(), &endptr);
        
        if (*endptr == '\0' || (*endptr == 'f' && *(endptr + 1) == '\0')) {
            if (t_input.find('.') != std::string::npos || t_input.find('e') != std::string::npos || t_input.find('E') != std::string::npos) {
                if (*endptr == 'f') {
                    converted_type.setFloat(static_cast<float>(value));
                    converted_type_idx = FLOAT;
                } else {
                    converted_type.setDouble(value);
                    converted_type_idx = DOUBLE;
                }
            } else if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) {
                converted_type.setInt(static_cast<int>(value));
                converted_type_idx = INT;
            } else {
				std::cout << "Int overflow. The values won't be accurate" << std::endl;
                converted_type.setDouble(value);
                converted_type_idx = DOUBLE;
            }
        }
    }

	switch (converted_type_idx) {
		case CHAR:
			printChar(converted_type.getChar());
			printInt(converted_type.getChar());
			printFloat(converted_type.getChar());
			printDouble(converted_type.getChar());
			break;
		case INT:
			printChar(converted_type.getInt());
			printInt(converted_type.getInt());
			printFloat(converted_type.getInt());
			printDouble(converted_type.getInt());
			break;
		case FLOAT:
			printChar(converted_type.getFloat());
			printInt(converted_type.getFloat());
			printFloat(converted_type.getFloat());
			printDouble(converted_type.getFloat());
			break;
		case DOUBLE:
			printChar(converted_type.getDouble());
			printInt(converted_type.getDouble());
			printFloat(converted_type.getDouble());
			printDouble(converted_type.getDouble());
			break;
		default:
			break;
	}
}
