#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;

enum FormType {
    BEGIN = -1,
    PRESIDENTIALPARDONFORM,
    SHRUBBERYCREATIONFORM,
    ROBOTOMYREQUESTFORM,
    UNKNOWN,
    END
};

class Intern {
public:
    Intern();
    Intern(const Intern &t_intern);
    ~Intern();
    Intern &operator=(const Intern &t_intern);

    FormType getFormType(std::string t_formName);
    AForm *makeForm(std::string t_formName, std::string t_target);
};


#endif