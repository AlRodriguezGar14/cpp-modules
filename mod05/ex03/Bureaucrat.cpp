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
	// std::cout << m_name << " destructor called" << std::endl;
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

void Bureaucrat::signForm(AForm& t_Form) {
	if (t_Form.getIsSigned()) {
		std::cerr	<< m_name
					<< " couldn't sign "
					<< t_Form.getName()
					<< " because it is already signed"
					<< std::endl;
		return ;
	}
	if (t_Form.getSignGrade() < m_grade) {
		std::cerr	<< m_name
					<< " couldn't sign "
					<< t_Form.getName()
					<< " because his/hers grade is too low. Grade "
					<< m_grade
					<< ", expected < "
					<< t_Form.getSignGrade()
					<< std::endl;
		return ;
	}
	t_Form.setSign();
	std::cout	<< m_name
				<< " signed "
				<< t_Form.getName()
				<< std::endl;
}

void Bureaucrat::executeForm(AForm const & t_Form) {
	if (t_Form.getExecGrade() < m_grade) {
		std::cerr	<< m_name
					<< " couldn't execute "
					<< t_Form.getName()
					<< " because his/hers grade is too low. Grade "
					<< m_grade
					<< ", expected < "
					<< t_Form.getExecGrade()
					<< std::endl;
		return ;
	}
	std::cout << m_name << " executed " << t_Form.getName() << std::endl;
	t_Form.execute(*this);
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::out_of_range("Bureaurat: Invalid grade, it must be > 1")  {}
Bureaucrat::GradeTooLowException::GradeTooLowException() : std::out_of_range("Bureaucrat: Invalid grade, it must be < 150"){}

std::ostream& operator << (std::ostream& os, const Bureaucrat& t_Bureaucrat) {
	os << t_Bureaucrat.getName() << ", bureaucrat grade " << t_Bureaucrat.getGrade() << std::endl;
	return os;
}