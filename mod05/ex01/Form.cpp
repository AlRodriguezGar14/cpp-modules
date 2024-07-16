#include "Form.hpp"

Form::Form(std::string t_name, int t_signGrade, int t_execGrade) : m_name(t_name), m_isSigned(false), m_signGrade(t_signGrade), m_execGrade(t_execGrade) {
	if (t_signGrade < 1 || t_execGrade < 1) {
		throw Form::GradeTooHighException();
	} else if (t_signGrade > 150 || t_execGrade > 150) {
		throw Form::GradeTooLowException();
	}
}
Form::Form(const Form& t_Form) : m_name(t_Form.m_name), m_isSigned(t_Form.m_isSigned), m_signGrade(t_Form.m_signGrade), m_execGrade(t_Form.m_execGrade) {}

Form& Form::operator=(const Form &t_Form) {
	if (this == &t_Form) {
		return *this;
	}
	m_isSigned = t_Form.m_isSigned;
	return *this;
}
Form::~Form() {
	// std::cout << "Form " << m_name << " destroyed" << std::endl;
}

std::string Form::getName() const { return m_name;};
bool Form::getIsSigned() const { return m_isSigned;};
int Form::getSignGrade() const { return m_signGrade;};
int Form::getExecGrade() const { return m_execGrade;};
void Form::setSign() { m_isSigned = true;};

void Form::beSigned(Bureaucrat& t_Bureaucrat) {
	if (m_isSigned) {
		std::cout << "Form " << m_name << " is already signed" << std::endl;
		return ;
	}
	if (t_Bureaucrat.getGrade() > m_signGrade)
		throw Form::GradeTooLowException();
	t_Bureaucrat.signForm(*this);	
}


Form::GradeTooHighException::GradeTooHighException() : std::out_of_range("Form: Grade is too high") {}
Form::GradeTooLowException::GradeTooLowException() : std::out_of_range("Form: Grade is too low") {}

std::ostream& operator<<(std::ostream& os, Form& t_Form) {
	os	<< "\tForm name: " << t_Form.getName() << "\n"
		<< "\tThe sign grade is: " << t_Form.getSignGrade() << "\n" 
		<< "\tThe execution grade is: " << t_Form.getExecGrade() << "\n"
		<< (t_Form.getIsSigned() ? "\tIt is signed" : "\tIt is not signed")
		<< std::endl;
	return os;
}