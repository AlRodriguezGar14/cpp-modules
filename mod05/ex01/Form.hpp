#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
private:
	const std::string m_name;
	bool m_isSigned;
	const int m_signGrade;
	const int m_execGrade;


public:
	Form(std::string t_name, int t_signGrade, int t_execGrade);
	Form(const Form& t_Form);
	Form& operator = (const Form& t_Form);
	~Form();

	// Methods
	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(Bureaucrat& t_Bureaucrat);
	void setSign();

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

std::ostream& operator << (std::ostream& os, Form& t_Form);

#endif
