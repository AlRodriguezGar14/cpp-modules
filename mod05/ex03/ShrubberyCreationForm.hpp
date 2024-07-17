#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
private:
    std::string m_target;
public:
    ShrubberyCreationForm(std::string t_target);
    ShrubberyCreationForm(const ShrubberyCreationForm& t_form);
    ShrubberyCreationForm& operator = (const ShrubberyCreationForm& t_form);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const & t_executor) const;
};

#endif