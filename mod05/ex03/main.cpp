#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <exception>
#include <iostream>

int main() {

	Bureaucrat charo("Charo Charez", 1);

	Intern intern;

	AForm* form1 = NULL;
	AForm* form2 = NULL;
	AForm* invalid = NULL;

	try {

		form1 = intern.makeForm("shrubbery creation", "home");
		charo.signForm(*form1);
		form2 = intern.makeForm("robotomy request", "robot");
		charo.signForm(*form2);
		invalid = intern.makeForm("invalid form", "invalid");
		charo.signForm(*invalid);

	} catch (std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	AForm* rrf;

	rrf = intern.makeForm("robotomy request", "Bender");
	std::cout << *rrf;
	rrf->execute(charo);
	charo.signForm(*rrf);
	charo.executeForm(*rrf);

	delete rrf;

	if (form1 != NULL)
		delete form1;
	if (form2 != NULL)
		delete form2;
	if (invalid != NULL)
		delete invalid;

}