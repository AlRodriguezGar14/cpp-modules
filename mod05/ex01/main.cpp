#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <exception>
#include <iostream>

int main() {

	Bureaucrat charo("Charo Charez", 5);
	Bureaucrat paco("Paco Paquez", 50);


	Form inspection("Property Inspection", 20, 11);
	Form penalty("Speed Penalty", 60, 50);

	try {
		Form invalid("Invalid Form", 0, 0);
	} catch (std::exception& e) {
		std::cout << "EXCEPTION: " << e.what() << std::endl;
	}

	try {

		std::cout << inspection;
		paco.signForm(inspection);
		std::cout << penalty;;
		penalty.beSigned(paco);
		std::cout << penalty;;
		std::cout << "Paco is going to break the law trying to sign the inspection" << std::endl;
		inspection.beSigned(paco);

	} catch (std::exception& e) {
		std::cout << "EXCEPTION: " << e.what() << std::endl;
	}

	std::cout << inspection;
	inspection.beSigned(charo);
	std::cout << inspection;
	charo.signForm(penalty);




}