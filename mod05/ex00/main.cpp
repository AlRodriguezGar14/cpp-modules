#include "Bureaucrat.hpp"

#include <exception>
#include <iostream>

int main() {

	try {
		Bureaucrat charo("Charo Charez", 1);
		std::cout << charo;
		charo.decrementGradeBy(10);
		std::cout << charo;
		charo.incrementGradeBy(10);
		std::cout << charo;
		charo.incrementGradeBy(10);
		std::cout << charo;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------" << std::endl;

	Bureaucrat *paco = NULL;
	try {
		paco = new Bureaucrat("Paco Paquez", 151);
//		paco = new Bureaucrat("Paco Paquez", 10);
		std::cout << *paco;
	} catch (std::exception &e) {
		delete paco;
		std::cout << "Exception: " << e.what() << std::endl;
	}
}