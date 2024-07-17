#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string t_target)
: AForm("Presidential Pardon", 25, 5), m_target(t_target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& t_form) : AForm(t_form) {
    *this = t_form;
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& t_form) {
    if (this != &t_form) {
        m_target = t_form.m_target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & t_executor) const {
    if (!canExecute(t_executor))
        return ;

    std::cout   << m_target
                << " has been pardoned by Zafod Beeblebrox"
                << std::endl;
}
