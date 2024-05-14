#ifndef PROJECT_UTILS_HPP
# define PROJECT_UTILS_HPP

#include <iostream>
#include <cctype>
#include <string>

//#include "Contact.hpp"
//#include "PhoneBook.hpp"

std::string format_column(const std::string& str);
std::string get_input(const std::string& prompt);
void		clear_stdin(std::istream& in);

#endif
