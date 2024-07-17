#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

class Bureaucrat;

class AForm {
private:
	const std::string m_name;
	bool m_isSigned;
	const int m_signGrade;
	const int m_execGrade;

protected:
	bool canExecute(Bureaucrat const & t_Bureaucrat) const;


public:
	AForm(std::string t_name, int t_signGrade, int t_execGrade);
	AForm(const AForm& t_Form);
	AForm& operator = (const AForm& t_Form);
	virtual ~AForm();

	// Methods
	virtual std::string getName() const;
	virtual bool getIsSigned() const;
	virtual int getSignGrade() const;
	virtual int getExecGrade() const;
	virtual void beSigned(Bureaucrat& t_Bureaucrat);
	virtual void execute(Bureaucrat const & t_executor) const = 0;
	virtual void setSign();

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

std::ostream& operator << (std::ostream& os, AForm& t_Form);

#endif
