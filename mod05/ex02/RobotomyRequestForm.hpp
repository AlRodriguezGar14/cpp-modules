#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>
#include <ctime>

class Bureaucrat;

class RobotomyRequestForm : public AForm {
private:
    std::string m_target;

public:
    RobotomyRequestForm(std::string t_target);
    RobotomyRequestForm(const RobotomyRequestForm& t_form);
    RobotomyRequestForm& operator = (const RobotomyRequestForm& t_form);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & t_executor) const;
};

#endif