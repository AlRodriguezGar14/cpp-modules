#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string t_target)
: AForm("Shrubbery", 145, 137), m_target(t_target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& t_form) : AForm(t_form) {
    *this = t_form;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& t_form) {
    if (this != &t_form) {
        m_target = t_form.m_target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & t_executor) {
    if (!canExecute(t_executor))
        return ;
    std::ofstream file;
    file.open((m_target + "_shrubbery").c_str());
    if (!file)
        throw std::runtime_error("Could not open the file");

    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\\\ //  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_" << std::endl;
    file << "      // \\\\" << std::endl;
    file.close();

    std::cout   << "The form "
                << this->getName()
                << " was executed by "
                << t_executor.getName()
                << std::endl; 
}
