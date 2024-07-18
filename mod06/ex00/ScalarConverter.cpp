#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &src) { *this = src; }
ScalarConverter& ScalarConverter::operator=(ScalarConverter const &src) { (void)src; return *this; }
ScalarConverter::~ScalarConverter() {}

void printChar(const std::string& t_input) {
	std::cout << "char: ";
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

void printInt(const std::string& t_input) {
	std::cout << "int: ";
	try {
		std::cout << std::stoi(t_input) << std::endl;
	} catch (std::exception& e) {
		std::cout << "impossible" << std::endl;
	}
}


void printFloat(const std::string& t_input) {
	std::cout << "float: ";

	try {
		long double nbr = std::stold(t_input);

		if (std::isnan(nbr) || std::isinf(nbr)) {
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

void ScalarConverter::convert(const std::string& t_input) {

	printChar(t_input);
	printInt(t_input);
	printFloat(t_input);
}