#ifndef PROJECT_UTILS_HPP
# define PROJECT_UTILS_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <cstdio>
#include <sstream>

std::string format_column(const std::string& str);
std::string get_input(const std::string& prompt);
void		clear_stdin(std::istream& in);
std::string to_str(size_t nbr);

#endif
