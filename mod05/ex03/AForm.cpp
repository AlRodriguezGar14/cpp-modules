#include "AForm.hpp"

AForm::AForm(std::string t_name, int t_signGrade, int t_execGrade) : m_name(t_name), m_isSigned(false), m_signGrade(t_signGrade), m_execGrade(t_execGrade) {
	if (t_signGrade < 1 || t_execGrade < 1) {
		throw AForm::GradeTooHighException();
	} else if (t_signGrade > 150 || t_execGrade > 150) {
		throw AForm::GradeTooLowException();
	}
}
AForm::AForm(const AForm& t_AForm) : m_name(t_AForm.m_name), m_isSigned(t_AForm.m_isSigned), m_signGrade(t_AForm.m_signGrade), m_execGrade(t_AForm.m_execGrade) {}

AForm& AForm::operator=(const AForm &t_AForm) {
	if (this == &t_AForm) {
		return *this;
	}
	m_isSigned = t_AForm.m_isSigned;
	return *this;
}
AForm::~AForm() {
	// std::cout << "AForm " << m_name << " destroyed" << std::endl;
}

std::string AForm::getName() const { return m_name;};
bool AForm::getIsSigned() const { return m_isSigned;};
int AForm::getSignGrade() const { return m_signGrade;};
int AForm::getExecGrade() const { return m_execGrade;};
void AForm::setSign() { m_isSigned = true;};

void AForm::beSigned(Bureaucrat& t_Bureaucrat) {
	if (m_isSigned) {
		std::cout << "AForm " << m_name << " is already signed" << std::endl;
		return ;
	}
	if (t_Bureaucrat.getGrade() > m_signGrade)
		throw AForm::GradeTooLowException();
	t_Bureaucrat.signForm(*this);	
}

bool AForm::canExecute(Bureaucrat const & t_Bureaucrat) const {
    if (t_Bureaucrat.getGrade() > m_execGrade) {
        std::cerr << "Bureaucrat " << t_Bureaucrat.getName() << " cannot execute AForm " << m_name << " because his grade is too low" << std::endl;
        throw AForm::GradeTooLowException();
    }
    if (!m_isSigned) {
        std::cerr << "AForm " << m_name << " can't be executed; it's not signed" << std::endl;
        return false;
    }
    return true;
}

AForm::GradeTooHighException::GradeTooHighException() : std::out_of_range("AForm: Grade is too high") {}
AForm::GradeTooLowException::GradeTooLowException() : std::out_of_range("AForm: Grade is too low") {}

std::ostream& operator<<(std::ostream& os, AForm& t_AForm) {
	os	<< "\tAForm name: " << t_AForm.getName() << "\n"
		<< "\tThe sign grade is: " << t_AForm.getSignGrade() << "\n" 
		<< "\tThe execution grade is: " << t_AForm.getExecGrade() << "\n"
		<< (t_AForm.getIsSigned() ? "\tIt is signed" : "\tIt is not signed")
		<< std::endl;
	return os;
}