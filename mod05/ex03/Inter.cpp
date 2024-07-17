#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &t_intern) { *this = t_intern; }
Intern& Intern::operator=(const Intern &t_intern) { (void)t_intern; return *this; }
Intern::~Intern() {}

FormType Intern::getFormType(std::string t_formName) {

    std::string formNames[] = {
        "presidential pardon",
        "shrubbery creation",
        "robotomy request"
    };

    for (FormType i = BEGIN; i != END; i = static_cast<FormType>(i + 1)) {
        if (formNames[i] == t_formName) {
            std::cout << "Intern creates " << formNames[i] << std::endl; 
            return (FormType)i;
        }
    }
    return UNKNOWN;
}

AForm *Intern::makeForm(std::string t_formName, std::string t_target) {

    FormType formType = getFormType(t_formName);

    switch (formType) {
        case PRESIDENTIALPARDONFORM:
            return new PresidentialPardonForm(t_target);
        case SHRUBBERYCREATIONFORM:
            return new ShrubberyCreationForm(t_target);
        case ROBOTOMYREQUESTFORM:
            return new RobotomyRequestForm(t_target);
        default:
            throw std::runtime_error("Form not found");
    }

}