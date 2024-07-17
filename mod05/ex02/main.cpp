#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <exception>
#include <iostream>

int main() {

	Bureaucrat charo("Charo Charez", 1);
	Bureaucrat paco("Paco Paquez", 140);
	ShrubberyCreationForm shrubbery("home");

	try {
		std::cout << shrubbery;
		shrubbery.execute(charo);
		shrubbery.beSigned(paco);
		std::cout << shrubbery;
		shrubbery.execute(charo);
		shrubbery.execute(paco);
	} catch (std::exception & e) {
		std::cout << "EXCEPTION: " << e.what() << std::endl;
	}

	RobotomyRequestForm robotomy("robot");

	try {

		std::cout << robotomy;
		robotomy.execute(charo);
		robotomy.beSigned(charo);
		std::cout << robotomy;
		robotomy.execute(charo);
		charo.executeForm(robotomy);
		robotomy.execute(charo);
		robotomy.execute(charo);
		robotomy.execute(charo);
		paco.executeForm(robotomy);
		robotomy.execute(paco);
	} catch (std::exception & e) {
		std::cout << "EXCEPTION BLOCK 2: " << e.what() << std::endl;
	}

	PresidentialPardonForm pardon("Carvajal");

	try {
		std::cout << pardon;
		pardon.execute(charo);
		paco.signForm(pardon);
		pardon.beSigned(charo);
		std::cout << pardon;
		pardon.execute(charo);
		pardon.execute(paco);
	} catch (std::exception & e) {
		std::cout << "EXCEPTION BLOCK 3: " << e.what() << std::endl;
	}

}