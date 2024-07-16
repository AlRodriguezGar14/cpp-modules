#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <exception>
#include <iostream>

int main() {

	Bureaucrat charo("Charo Charez", 1);
	Bureaucrat paco("Paco Paquez", 149);
	ShrubberyCreationForm shrubbery("tree");

	try {
		shrubbery.execute(charo);
		shrubbery.beSigned(charo);
		shrubbery.execute(charo);
		shrubbery.execute(paco);
	} catch (std::exception & e) {
		std::cout << "EXCEPTION: " << e.what() << std::endl;
	}
}