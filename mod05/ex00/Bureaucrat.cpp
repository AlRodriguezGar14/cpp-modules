#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string t_name, int t_grade) : m_name(t_name) {
	if (t_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (t_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	m_grade = t_grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &t_bureaucrat) : m_name(t_bureaucrat.m_name), m_grade(t_bureaucrat.m_grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &t_bureaucrat) {
	if (this == &t_bureaucrat)
		return *this;

	m_grade = t_bureaucrat.m_grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << m_name << " destructor called" << std::endl;
}

std::string Bureaucrat::getName() const { return m_name;};
int Bureaucrat::getGrade() const { return m_grade;};

void Bureaucrat::incrementGradeBy(int t_increment) {
	std::cout << "Increment " << t_increment << std::endl;
	if ((m_grade - t_increment) < 1)
		throw Bureaucrat::GradeTooHighException();
	m_grade -= t_increment;
}

void Bureaucrat::decrementGradeBy(int t_decrement) {
	std::cout << "Decrement " << t_decrement << std::endl;
	if ((m_grade + t_decrement) > 150)
		throw Bureaucrat::GradeTooLowException();
	m_grade += t_decrement;
}

std::ostream& operator << (std::ostream& os, const Bureaucrat& t_Bureaucrat) {
	os << t_Bureaucrat.getName() << ", bureaucrat grade " << t_Bureaucrat.getGrade() << std::endl;
	return os;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::out_of_range("Invalid grade, it must be > 1")  {}
Bureaucrat::GradeTooLowException::GradeTooLowException() : std::out_of_range("Invalid grade, it must be < 150"){}