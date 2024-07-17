#ifndef PRESIDENTIALPARADONFORM_HPP
#define PRESIDENTIALPARADONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
private:
    std::string m_target;
public:
    PresidentialPardonForm(std::string t_target);
    PresidentialPardonForm(const PresidentialPardonForm& t_form);
    PresidentialPardonForm& operator = (const PresidentialPardonForm& t_form);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const & t_executor) const;
};

#endif