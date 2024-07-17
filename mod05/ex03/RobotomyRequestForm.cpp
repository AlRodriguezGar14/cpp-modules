#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string t_target)
: AForm("Robotomy", 72, 45), m_target(t_target) {
    // Seeding the randomness once is far better than doing it everytime execute is called
    srand(static_cast<unsigned int>(time(0)));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& t_form) : AForm(t_form) {
    *this = t_form;
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& t_form) {
    if (this != &t_form) {
        m_target = t_form.m_target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & t_executor) const {
    if (!canExecute(t_executor))
        return ;
    std::cout   << "Drilling noises..." << std::endl;

    if (rand() % 2)
        std::cout   << m_target
                    << " has been robotomized successfully"
                    << std::endl;
    else
        std::cout   << "The robotomization of "
                    << m_target
                    << " has failed"
                    << std::endl;
}