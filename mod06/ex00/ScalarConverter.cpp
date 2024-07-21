#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &src) { *this = src; }
ScalarConverter& ScalarConverter::operator=(ScalarConverter const &src) { (void)src; return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& t_input) {
	if (t_input.length() == 1 && !isdigit(t_input[0])) {
		return true;
	}
	try {
		int nbr = std::stoi(t_input);
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

void ScalarConverter::printChar(const std::string& t_input) {
	std::cout << "char: ";
	if (isChar(t_input)) {
		std::cout << "'" << static_cast<char>(std::stoi(t_input)) << "'" << std::endl;
		return ;
	}
	try {
		int nbr = std::stoi(t_input);
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

void ScalarConverter::printInt(const std::string& t_input) {
	std::cout << "int: ";
	if (t_input.length() == 1 && !isdigit(t_input[0])) {
		std::cout << static_cast<int>(t_input[0]) << std::endl;
		return ;
	}
	try {
		std::cout << std::stoi(t_input) << std::endl;
	} catch (std::exception& e) {
		std::cout << "impossible" << std::endl;
	}
}


void ScalarConverter::printFloat(const std::string& t_input) {
	std::cout << "float: ";

	try {
		long double nbr = std::stold(t_input);

		if (ft_isnan(nbr) || ft_isinf(nbr)) {
			std::cout << "nanf" << std::endl;
			return ;
		}
		if (nbr > std::numeric_limits<float>::max()) {
			std::cout << "+inff" << std::endl;
			return ;
		}
		if (nbr < std::numeric_limits<float>::lowest()) {
			std::cout << "-inff" << std::endl;
			return ;
		}
		std::cout << std::fixed << std::setprecision(1) << std::stof(t_input) << "f" << std::endl;
	} catch (std::exception& e) {
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::printDouble(const std::string& t_input) {
	std::cout << "double: ";

	try {
		long double nbr = std::stold(t_input);

		if (ft_isnan(nbr) || ft_isinf(nbr)) {
			std::cout << "nan" << std::endl;
			return ;
		}
		if (nbr > std::numeric_limits<double>::max()) {
			std::cout << "+inf" << std::endl;
			return ;
		}
		if (nbr < std::numeric_limits<double>::lowest()) {
			std::cout << "-inf" << std::endl;
			return ;
		}
		std::cout << std::fixed << std::setprecision(1) << std::stod(t_input) << std::endl;
	} catch (std::exception& e) {
		std::cout << "impossible" << std::endl;
	}

}

void ScalarConverter::convert(const std::string& t_input) {

	printChar(t_input);
	printInt(t_input);
	printFloat(t_input);
	printDouble(t_input);
}
