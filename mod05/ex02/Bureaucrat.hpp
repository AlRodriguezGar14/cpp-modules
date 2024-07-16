#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"

#include <string>
#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat {
private:
	const std::string m_name;
	int m_grade; // must be between 1 (highest) and 150 (lowest);

public:
	Bureaucrat(std::string t_name, int t_grade); // Throw errors: GradeTooHighException or GradeTooLowException
	Bureaucrat(const Bureaucrat& t_bureaucrat);
	Bureaucrat& operator=(const Bureaucrat& t_bureaucrat);
	~Bureaucrat();

	// Methods
	std::string getName() const;
	int getGrade() const;
	void incrementGradeBy(int t_increment);
	void decrementGradeBy(int t_decrement);
	void signForm(AForm& t_Form);

	// Exceptions
	class GradeTooHighException : public std::out_of_range {
	public:
		GradeTooHighException();
	};

	class GradeTooLowException : public std::out_of_range {
	public:
		GradeTooLowException();
	};

};

std::ostream& operator << (std::ostream& os, const Bureaucrat& t_Bureaucrat);
#endif
